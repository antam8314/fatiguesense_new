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

// defines for HRV
#define PEAK_WINDOW 20

//defines for smoothing
#define SMOOTHING_WINDOW 15

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

// HRV variables
static double MeanRR;
static bool HRVFatigue;

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

#ifdef TESTING

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

#ifdef TESTING
  if (fftStatus != ARM_MATH_SUCCESS)
    printf("Failed to initialize RFFT structure\n");
#endif
}

/**************************************************************************//**
 * @brief callback from timer to process data
 *****************************************************************************/
#ifdef TESTING
void hrm_process_input(sl_sleeptimer_timer_handle_t *handle, void *data)
#else
void hrm_process_input(void)
#endif
{
  peak_t input;
  uint16_t inputFromSensor;
  uint16_t smoothAverage;
  bool sensorReady = false;

  time = get_time_ms();

#ifdef TESTING
  //printf("Loop start time: %" PRIu64 "\n", time);

  // use test dataset input
  if (testCnt == TEST_PPG_LENGTH)
    testCnt = 0;

  // Periodic Moving Average Filter

  inputFromSensor = testPPG[testCnt];

#else
  // ***Sensor input here***

#endif

  smoothSum = smoothSum - smoothReadings[smoothIndex];
  smoothReadings[smoothIndex] = inputFromSensor;
  smoothSum = smoothSum + inputFromSensor;
  smoothIndex = (smoothIndex + 1) % SMOOTHING_WINDOW;

  smoothAverage = smoothSum / SMOOTHING_WINDOW;

  input.value = smoothAverage;
  input.time = time;

#ifdef TESTING
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
      lastPeak.value = prevInput.value;
      lastPeak.time = prevInput.time;

      peaks[peakIndex] = prevInput.time;
#ifdef TESTING
      printf("Peak value: %i at time: %" PRIu64 " | index %i\n", prevInput.value, prevInput.time, peakIndex);
#endif
      peakIndex++;

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
#ifdef TESTING
  timerStatus = sl_sleeptimer_start_periodic_timer_ms(&timer_10ms,
                                                 timer_timeout,
                                                 hrm_process_input,
                                                 (void *)NULL,
                                                 0,
                                                 0);
#else
  //*****Sensor interface here*****

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

  for (int i = 0; i < PEAK_WINDOW - 1; i++) {
    //50ms divided by the average RR gives the % variability threshold
    if (fabs(((double)(peaks[i+1] - peaks[i]) / MeanRR)-1.0) < (50.0/MeanRR))
      count++;

#ifdef TESTING
    printf("RR: %"PRIu64" | MeanRR: %f | Abs: %f | Thresh: %f\n", (peaks[i+1] - peaks[i]), MeanRR, fabs(((double)(peaks[i+1] - peaks[i]) / MeanRR)-1.0), (50.0/MeanRR));
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
  q15_t hanning_window[PPG_SAMPLES];
  for (int i = 0; i < PPG_SAMPLES; i++) {
    hanning_window[i] = f_to_q15(0.5 * (1 - arm_cos_f32(2 * PI * i / PPG_SAMPLES )));
  }

  arm_mult_q15(ppg_data, hanning_window, ppg_data, PPG_SAMPLES);

  arm_rfft_q15(&S, ppg_data, complexFFT);

  // magnitude function returns amplitude (squared function for power)
  arm_cmplx_mag_q15(complexFFT, magFFT, PPG_SAMPLES/2+1);

  // remove DC
  // magFFT[0] = 0;

#ifdef TESTING
  for (int i = 0; i < PPG_SAMPLES/2; i++) {
    printf("%i, ", magFFT[i]);
  }
  printf("\n");
#endif

  // find peaks for resp rate and heart rate




  return;
}

/**************************************************************************//**
 * @brief This function returns the current heart rate.
 *****************************************************************************/
uint16_t hrm_get_heart_rate(void)
{
  // MeanRR in ms
  return (uint16_t)(MS_IN_MINUTE / MeanRR);
}

/**************************************************************************//**
 * @brief This function returns the current mean rr.
 *****************************************************************************/
uint16_t hrm_get_heart_rate_mean_rr(void)
{
  // MeanRR in ms, convert to sec * 1024
  return (uint16_t)((MeanRR / 1000.0) * 1024.0);
}

/**************************************************************************//**
 * @brief This function returns the HRV Fatigue indication status
 *****************************************************************************/
bool hrm_get_hrv_fatigue(void)
{
  return HRVFatigue;
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
