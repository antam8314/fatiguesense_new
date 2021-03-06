/**************************************************************************//**
 * @file hrm_app.c
 * @brief
 * @version 1.0.0
*******************************************************************************
* # License
*
*******************************************************************************
*
*
******************************************************************************/
#include <fatigue/apps/hrm_app.h>

#ifdef SENSOR
#include <fatigue/sensor/sensor.h>
#endif

// for respiratory rate
#include "arm_math.h"
#include "arm_const_structs.h"

#ifdef TESTING

#include <stdio.h>
#include "hrm_test.h"

#endif

/**************************************************************************//**
 * Local defines
 *****************************************************************************/
// defines for fft
#define PPG_SAMPLES 1024

// 100Hz sample rate / 1024 bins = 0.09765625Hz per bin
#define BIN_WIDTH 0.09765625

// defines for HRV
#define PEAK_WINDOW 20

// defines for smoothing
#define SMOOTHING_WINDOW 15

// defines for resp rate
#define RESP_AVG_WINDOW 10
#define RESP_FATIGUE_THRESHOLD 25

typedef struct
{
  uint16_t value;
  uint64_t time;
} peak_t;

/**************************************************************************//**
 * Global variables
 *****************************************************************************/
static int ppgCnt;
static uint64_t peaks[PEAK_WINDOW];
static int peakIndex;
static uint64_t time;

static uint16_t inputFromSensor;

// HRV variables
static double MeanRR;
static bool HRVFatigue;
static double hrv;

// variables for pulse detection
static peak_t prevInput;
static peak_t lastPeak;
static uint16_t threshold = 500;

// variables for fft
arm_rfft_instance_q15 S;
arm_status fftStatus;
q15_t complexFFT[PPG_SAMPLES * 2];
q15_t magFFT[PPG_SAMPLES/2];
static q15_t ppg_data[PPG_SAMPLES];
static q15_t hanning_window[PPG_SAMPLES];

// variables for respiratory rate
static double respRate;
static q15_t respIntensityData[RESP_AVG_WINDOW];
static bool respFatigue;
static int respCnt;
static float avgRespIntensity;
static float respIntensity;

#ifndef SENSOR

// test data vars
extern int TEST_PPG_LENGTH;
extern uint16_t testPPG[];
static int testCnt = 0;

// timer vars
sl_status_t timerStatus;
sl_sleeptimer_timer_handle_t timer_10ms;
uint32_t timer_timeout = 10;

#endif

//smoothing vars
static int smoothIndex;
static uint16_t smoothSum;
static uint16_t smoothReadings[SMOOTHING_WINDOW];

/**************************************************************************//**
 * @brief Initialize the HRM application.
 *****************************************************************************/
void hrm_init_app(void)
{
  // Init FFT
  fftStatus = ARM_MATH_SUCCESS;
  fftStatus = arm_rfft_init_q15(&S, PPG_SAMPLES, 0, 1);

  for (int i = 0; i < PPG_SAMPLES; i++) {
    hanning_window[i] = f_to_q15(0.5 * (1 - arm_cos_f32(2 * PI * i / PPG_SAMPLES )));
  }


#ifdef TESTING
  if (fftStatus != ARM_MATH_SUCCESS)
    printf("Failed to initialize RFFT structure\n");
#endif
}

/**************************************************************************//**
 * @brief callback from timer to process data
 *****************************************************************************/
#ifndef SENSOR
void hrm_process_input(sl_sleeptimer_timer_handle_t *handle, void *data)
#else
void hrm_process_input(void)
#endif
{
  peak_t input;
  uint16_t smoothAverage;
  bool sensorReady = false;

  time = get_time_ms();

#ifndef SENSOR
  //printf("Loop start time: %" PRIu64 "\n", time);

  // use test dataset input
  if (testCnt == TEST_PPG_LENGTH)
    testCnt = 0;

  // Periodic Moving Average Filter

  inputFromSensor = testPPG[testCnt];

#else
  // ***Sensor input here***
  // sensor input captured in hrm_loop()
#endif

  smoothSum = smoothSum - smoothReadings[smoothIndex];
  smoothReadings[smoothIndex] = inputFromSensor;
  smoothSum = smoothSum + inputFromSensor;
  smoothIndex = (smoothIndex + 1) % SMOOTHING_WINDOW;

  smoothAverage = smoothSum / SMOOTHING_WINDOW;

  input.value = smoothAverage;
  input.time = time;

#ifndef SENSOR
  //printf("Sample value: %f at time: %" PRIu64 "\n", inputFromSensor, time);
  //printf("Sample value: %f\n", smoothAverage);

  testCnt++;
#endif

  //indicate readings are good if average is above some threshold
  if (smoothAverage > 300)
    sensorReady = true;
  else
    sensorReady = false;

  if (sensorReady) {
    // change the input data to Q15 (1.15 meaning data between +/- 1.0)
    // assume input range is 0 to 800
    ppg_data[ppgCnt] = f_to_q15((float)inputFromSensor / 800.0);

    // peak detection
    if (input.value < prevInput.value && prevInput.value > threshold && (input.time - lastPeak.time) > (MS_IN_MINUTE / 150)) {
      // previous value was peak
      if (MeanRR != 0) {
        hrv = fabs(((double)(prevInput.time - lastPeak.time) / MeanRR)-1.0) * 100;
      }

#ifdef TESTING
      printf("Peak value: %i at time: %" PRIu64 " | Variability %lf | Index %i\n", prevInput.value, prevInput.time, hrv, peakIndex);
#endif
      peaks[peakIndex] = prevInput.time;
      peakIndex++;

      lastPeak.value = prevInput.value;
      lastPeak.time = prevInput.time;


      // call Mean RR calc when peak window full
      if (peakIndex == PEAK_WINDOW) {
        peakIndex = 0;
#ifdef TESTING
        printf("Calling MeanRR\n");
#endif
        hrm_calculate_mean_rr();
      }
    }
    ppgCnt++;
    if (ppgCnt == PPG_SAMPLES) {
      ppgCnt = 0;
#ifdef TESTING
      printf("Calling Resp Rate\n");
#endif
      hrm_calculate_resp_rate();
    }
  }

  // copy data to previous var
  prevInput.value = input.value;
  prevInput.time = input.time;

  return;
}

/**************************************************************************//**
 * @brief HRM process main loop.
 *****************************************************************************/
void hrm_loop(void)
{
#ifndef SENSOR
  timerStatus = sl_sleeptimer_start_periodic_timer_ms(&timer_10ms,
                                                 timer_timeout,
                                                 hrm_process_input,
                                                 (void *)NULL,
                                                 0,
                                                 0);
#else
  //*****Sensor interface here*****

  uint16_t data[] = {0, 0}; // to hold read register data
  uint16_t irq = 0;

  // Check INT_DATA_A - interrupt status and control register - indicates data
  //    to be read, cleared automatically on reg read if INT_ACLEAR_DATA_A is
  //    set (default)
  // INT_STATUS_DATA bit 0 INT_DATA_A - Time Slot A data register interrupt
  //                                    status
  adpd4100_reg_read(0x0001,&irq);

  // we only care about bit 0
  irq = (irq & 0x1);

  // if the interrupt is flagged
  if (irq == 1) {

    // Set HOLD_REGS_A = 1.
    // DATA_HOLD_FLAG bit 0 HOLD_REGS_A - Prevent update of Time Slot A data
    //                                    registers.
    //    1  hold contents
    adpd4100_reg_write(0x002E,0x1);

    // Once it's set, read the data register directly.
    // 0x30 SIGNAL1_L_A - signal 1 ch 1 lower half
    // 0x31 SIGNAL1_H_A - signal 1 ch 1 upper half
    adpd4100_reg_read(0x0030,&data[0]);
    adpd4100_reg_read(0x0031,&data[1]);

    // set OLD_REGS_A = 0
    adpd4100_reg_write(0x002E,0x0);

    // grab latest ppg value
    inputFromSensor = data[0] + (data[1] << 16);
  }

  hrm_process_input();
#endif
  return;
}

/**************************************************************************//**
 * @brief This function calculates the period mean RR
 *****************************************************************************/
void hrm_calculate_mean_rr(void)
{
  uint64_t sum = 0;
  int count = 0;
  int rejected = 0;

  for (int i = 0; i < PEAK_WINDOW - 1; i++) {
      if ((peaks[i+1] - peaks[i]) < 2000)  // reject gaps of more than 2s (less than 30bpm)
        sum = sum + (peaks[i+1] - peaks[i]);
      else rejected++;
  }

  // TODO - Don't update if rejected is too high?

  MeanRR = (double)sum / (double)(PEAK_WINDOW - 1 - rejected);

#ifdef TESTING
  printf("MeanRR: %f | Thresh: %f\n", MeanRR, (50.0/MeanRR));
#endif

  for (int i = 0; i < PEAK_WINDOW - 1; i++) {
    //50ms divided by the average RR gives the % variability threshold
    if (fabs(((double)(peaks[i+1] - peaks[i]) / MeanRR)-1.0) < (50.0/MeanRR))
      count++;

#ifdef TESTING
    printf("RR: %"PRIu64" | Abs: %f | Count: %i\n", (peaks[i+1] - peaks[i]), fabs(((double)(peaks[i+1] - peaks[i]) / MeanRR)-1.0), count);
#endif
  }

  if (((double)count / (double)(PEAK_WINDOW - 1 - rejected)) >= 0.9)
    HRVFatigue = true;
  else
    HRVFatigue = false;

#ifdef TESTING
  printf("Mean RR: %f | Fatigued: %i | count: %i\n", MeanRR, HRVFatigue, count);
#endif

  return;
}

/**************************************************************************//**
 * @brief This function performs the FFT to extract respiratory rate
 *****************************************************************************/
void hrm_calculate_resp_rate(void)
{
  q15_t max = 0;
  q15_t mean = 0;
  uint32_t maxIndex = 0;

  arm_mult_q15(ppg_data, hanning_window, ppg_data, PPG_SAMPLES);

  arm_rfft_q15(&S, ppg_data, complexFFT);

  // magnitude function returns amplitude (squared function for power)
  arm_cmplx_mag_q15(complexFFT, magFFT, PPG_SAMPLES/2);

  // remove DC
  magFFT[0] = 0;

#ifdef TESTING
  for (int i = 0; i < PPG_SAMPLES/2; i++) {
    printf("%i, ", magFFT[i]);
  }
  printf("\n");
#endif

  // find peak for resp rate
  arm_max_q15(magFFT, PPG_SAMPLES/2, &max, &maxIndex);

  respIntensityData[respCnt] = max;
  respIntensity = q15_to_f(max);
  respRate = (double)BIN_WIDTH * (double)maxIndex * (double)SEC_IN_MINUTE;

#ifdef TESTING
  printf("Max of %i at %li | Resp Rate: %i breaths per minute\n", max, maxIndex, (uint16_t)respRate);
#endif

  respCnt++;
  if (respCnt == RESP_AVG_WINDOW) {
    respCnt = 0;
    arm_mean_q15(respIntensityData, RESP_AVG_WINDOW, &mean);
    avgRespIntensity = q15_to_f(mean);
#ifdef TESTING
    printf("Resp Intensity: %f\n", avgRespIntensity);
#endif
  }

  // TODO - thresholds
  if (respRate > RESP_FATIGUE_THRESHOLD && respIntensity < 0.66 * avgRespIntensity)
    respFatigue = true;
  else
    respFatigue = false;

#ifdef TESTING
  printf("Resp Fatigued: %i\n", respFatigue);
#endif

    return;
}

/**************************************************************************//**
 * @brief This function returns the current heart rate.
 *****************************************************************************/
uint16_t hrm_get_heart_rate(void)
{
  // MeanRR in ms
  return (uint16_t)((double)MS_IN_MINUTE / MeanRR);
}

/**************************************************************************//**
 * @brief This function returns the current mean rr.
 *****************************************************************************/
uint16_t hrm_get_heart_rate_variability(void)
{
  // HRV as a percent * scalar
  return (uint16_t)(hrv * 1024.0);
}

/**************************************************************************//**
 * @brief This function returns the HRV Fatigue indication status
 *****************************************************************************/
bool hrm_get_hrv_fatigue(void)
{
  return HRVFatigue;
}

/**************************************************************************//**
 * @brief This function returns the current respiratory rate.
 *****************************************************************************/
uint16_t hrm_get_resp_rate(void)
{
  return (uint16_t)(respRate);
}

/**************************************************************************//**
 * @brief This function returns the current respiratory intensity.
 *****************************************************************************/
uint8_t hrm_get_resp_intensity(void)
{
  if (respIntensity < 0.66 * avgRespIntensity)
    // indicate shallow breathing
    return 1;
  else
    // indicate normal breathing
    return 0;
}

/**************************************************************************//**
 * @brief This function returns the Respiratory Fatigue indication status
 *****************************************************************************/
bool hrm_get_resp_fatigue(void)
{
  return respFatigue;
}

/**************************************************************************//**
 * @brief Return tick time in ms
 *****************************************************************************/
uint64_t get_time_ms(void)
{
  uint64_t tick;
  uint64_t ms;

  tick =  sl_sleeptimer_get_tick_count64();
  sl_sleeptimer_tick64_to_ms(tick,&ms);

  return ms;
}

/**************************************************************************//**
 * @brief Convert float to q15
 *****************************************************************************/
int16_t f_to_q15(float f)
{
  if (f >= 1.0) return Q15_PMAX;
  if (f <= -1.0) return Q15_NMAX;

  if (f < 0) {
    return - (Q15_MBITS & (int16_t) (-f * Q15_MULT));
  } else {
    return Q15_MBITS & (int16_t) (f * Q15_MULT);
  }
}

/**************************************************************************//**
 * @brief Convert q15 to float
 *****************************************************************************/
float q15_to_f(int16_t q15)
{
  uint16_t uq15 = q15;
  float f = (uq15 & Q15_MBITS) * 1.0 / Q15_MULT;
  if (uq15 & Q15_SBIT) f = -f;
  return q15 * 1.0 / Q15_MULT;
}
