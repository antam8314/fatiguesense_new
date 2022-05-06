// engineer: Alex Stanfill
// created: 03/22
// modified from original
// [1] Engineer Zone "what is the default configuration for ADPD4100 Wrist
//        worn PPG for Heart Rate Monitoring?" - https://ez.analog.com/optical_sensing/f/q-a/537217/what-is-the-default-configuration-for-adpd4100-wrist-worn-ppg-for-heart-rate-monitoring
/***************************************************************************//**
 * @file
 * @brief Sensor interface.
 ******************************************************************************/

#include <fatigue/sensor/sensor.h>

// Size of the data buffers
#define BUFLEN  4

// added to C includes: ${StudioSdkPath}/hardware/kit/common/bsp
#include "bsp.h"
// added to C includes: ${StudioSdkPath}/hardware/kit/EFR32BG22_BRD4184A/config
#include "bspconfig.h"

// SPI ports and pins
// COPI = controller out, peripheral in
#define US0COPI_PORT  gpioPortC
#define US0COPI_PIN   0
#define US0CIPO_PORT  gpioPortC
#define US0CIPO_PIN   1
#define US0CLK_PORT   gpioPortC
#define US0CLK_PIN    2
#define US0CS_PORT    gpioPortB
#define US0CS_PIN     2

#define UPPERBYTE_MASK  0x7f80
#define LOWERBYTE_MASK  0xfe

/**************************************************************************//**
 * @brief
 *    GPIO initialization
 *****************************************************************************/
void initGPIO(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);

  // Configure TX pin as an output
  GPIO_PinModeSet(US0COPI_PORT, US0COPI_PIN, gpioModePushPull, 0);

  // Configure RX pin as an input
  GPIO_PinModeSet(US0CIPO_PORT, US0CIPO_PIN, gpioModeInput, 0);

  // Configure CLK pin as an output low (CPOL = 0)
  GPIO_PinModeSet(US0CLK_PORT, US0CLK_PIN, gpioModePushPull, 0);

  // Configure CS pin as an output and drive inactive high
  GPIO_PinModeSet(US0CS_PORT, US0CS_PIN, gpioModePushPull, 1);

//  // Configure button 0 pin as an input
//  GPIO_PinModeSet(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN, gpioModeInputPull, 1);
//
//  // Interrupt on button 0 rising edge to start transfers
//  GPIO_ExtIntConfig(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN, BSP_GPIO_PB0_PIN, true, false, true);

  // Enable NVIC GPIO interrupt
#if (BSP_GPIO_PB0_PIN & 1)
  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);
#else
  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
#endif

}

/**************************************************************************//**
 * @brief
 *    USART0 initialization
 *****************************************************************************/
void initUSART0(void)
{
  CMU_ClockEnable(cmuClock_USART0, true);

  // Default asynchronous initializer (main mode, 1 Mbps, 8-bit data)
  USART_InitSync_TypeDef init = USART_INITSYNC_DEFAULT;

  init.msbf = true;   // MSB first transmission for SPI compatibility
  init.baudrate = 50000;  // change from 1 Mbps to 50 Kbps due to limitations
                          //  of opamp doing level shifting on CIPO

  /*
   * Route USART0 RX, TX, and CLK to the specified pins.  Note that CS is
   * not controlled by USART0 so there is no write to the corresponding
   * USARTROUTE register to do this.
   */
  GPIO->USARTROUTE[0].TXROUTE = (US0COPI_PORT << _GPIO_USART_TXROUTE_PORT_SHIFT)
      | (US0COPI_PIN << _GPIO_USART_TXROUTE_PIN_SHIFT);
  GPIO->USARTROUTE[0].RXROUTE = (US0CIPO_PORT << _GPIO_USART_RXROUTE_PORT_SHIFT)
      | (US0CIPO_PIN << _GPIO_USART_RXROUTE_PIN_SHIFT);
  GPIO->USARTROUTE[0].CLKROUTE = (US0CLK_PORT << _GPIO_USART_CLKROUTE_PORT_SHIFT)
      | (US0CLK_PIN << _GPIO_USART_CLKROUTE_PIN_SHIFT);

  // Enable USART interface pins
  GPIO->USARTROUTE[0].ROUTEEN = GPIO_USART_ROUTEEN_RXPEN |    // MISO
                                GPIO_USART_ROUTEEN_TXPEN |    // MOSI
                                GPIO_USART_ROUTEEN_CLKPEN;

  // Configure and enable USART0
  USART_InitSync(USART0, &init);
}



/**************************************************************************//**
 * @brief
 *    ADPD4100 initialization
 *****************************************************************************/
void initADPD4100(void) {
  uint16_t deviceid = 0;
  uint8_t r = 0;

  // wait for ADPD4100 to start up by reading CHIP_ID register
  while (deviceid != 0x2c2) {
      r = adpd4100_reg_read(0x8,&deviceid);
  }

  // set typical default ADPD4100 configuration [1]

  // OSC_32M_FREQ_ADJ bits 0-7 - High frequency oscillator frequency control
  adpd4100_reg_write(0x9,0x80); // default

  // OSC_1M_FREQ_ADJ bits 0-9 - Low frequency oscillator frequency control
  // 1MHz trim - trim your own clock
  adpd4100_reg_write(0xB,0x2b2); //default

  // OSC_32K_ADJUST bits 0-5 - 32 kHzoscillator trim
  adpd4100_reg_write(0xC,0x12); // default

  // OSC_32K_ADJUST TS_FREQ bits 0-15 TIMESLOT_PERIOD_L
  //  - Lower 16 bits of time slot period in low frequency oscillator cycles.
  adpd4100_reg_write(0xD,0x2710); // 100 Hz, default

  //  enable 1MHz osc
  adpd4100_reg_write(0xF,0x6);

  // One timeslot active: A
  adpd4100_reg_write(0x10,0x0);

  // in1 connected to vc1 during sleep, everything else floating
  adpd4100_reg_write(0x20,0x4);

  // all inputs single ended, vc1 set to Vdd during sleep
  adpd4100_reg_write(0x21,0x0); // default

  // gpio0 is output, inverted
  adpd4100_reg_write(0x22,0x3);

  // GPIO01 bits 0-6 GPIOOUT0 - GPIO0 output signal select
  // 0x2 - Interrupt X
  adpd4100_reg_write(0x23,0x2);

  // INT_ENABLE_XD bit 15 INTX_EN_FIFO_TH - INT_FIFO_TH interrupt enable.
  //    Write a 1 to this bit to enable drive of the FIFO threshold status on
  //    Interrupt X.
  adpd4100_reg_write(0x14,0x8000);

  // timeslot A - continuous connect mode - green PPG

  // TS_CTRL_A bits 10-11 INPUT_R_SELECT_A[1:0] - Input resistor (R IN ) select
  // Rin = 500, tsA offset = 0, skip subsample
  adpd4100_reg_write(0x100,0x0);    // default

  // path = TIA + BPF + INT + ADC
  adpd4100_reg_write(0x101,0x40DA);   // default

  // IN1 to channel 1, others disconnected
  adpd4100_reg_write(0x102,0x1);

  // precondition inputs to TIA_Vref, VC1 active state = V_delta
  // CATHODE_A
  //    bits 0-1 VC1_SEL_x - VC1 active state for Time Slot x.
  //        10b    TIA_VREF + 215mV
  //    bits 12-14 PRECON_x - Precondition value for enabled inputs during Time Slot x.
  //        101: precondition with TIA_VREF
  adpd4100_reg_write(0x103,0x5002);

  //  AFE_TRIM_VREF_x:    11: TIA_VREF = 1.265 V.
  //  VREF_PULSE_VAL_x:   11: modulate TIA_VREF = 1.265 V.
  //  0x104 AFE_TRIM_A
  //    12-11 CH1_TRIM_INT_x
  //    9-8   AFE_TRIM_VREF_x
  //    7-6   VREF_PULSE_VAL_x
  //    2-0   TIA_GAIN_CH1_x
  // Set to 0x03C0 = 0000 0011 1100 0000 for Rf = 200k Rint = 400k
  // To lower gain from 200k/400k = 0.5 to 0.25,
  //  set to 0000 0011 1100 0001 = 0x3C1
  adpd4100_reg_write(0x104,0x3c1);

  // 11 mA on LED1A, 2A, 3A
  //adpd4100_reg_write(0x105,0x707);
  //adpd4100_reg_write(0x106,0x7);

  // Reducing the LED amperage to avoid saturating TIA and/or ADC
  // 8 mA on LED1A, 2A, 3A
  adpd4100_reg_write(0x105,0x505);
  adpd4100_reg_write(0x106,0x5);

  // 64 pulses
  adpd4100_reg_write(0x107,0x140);

  // period set by automatic period of continuous connect mode
  adpd4100_reg_write(0x108,0x0);  // default

  // led width= 2us led offset=16 us
  adpd4100_reg_write(0x109,0x210);


  // INTEG_SETUP_A bits 6-7 ADC_COUNT_x - ADC conversions per pulse =
  //      ADC_COUNT_x + 1
  //          b11 integrator width=3 us
  adpd4100_reg_write(0x10a,0x3);  // default

  // integrator offset=16.5 us - ADJUST FINE OFFSET
  adpd4100_reg_write(0x10b,0x210);

  // no modulation
  adpd4100_reg_write(0x10c,0x1);

  // signal size = 3 bytes
  adpd4100_reg_write(0x110,0x3);

  // -++- int pattern
  adpd4100_reg_write(0x10d,0x99);

  // NO OFFSET - review if needed
  adpd4100_reg_write(0x10E,0x0);    // default

  // NO OFFSET - review if needed
  adpd4100_reg_write(0x10F,0x0);    // default

  // no decimation
  adpd4100_reg_write(0x112,0x0);    // default

  // ------------- Initialization complete ---------------
  // start operations
  // OPMODE bit 0 - operating mode selection
  // 0  standby
  // 1  go mode (operate selected time slots)
  adpd4100_reg_write(0x10,0x1);

}

/**************************************************************************//**
 * @brief GPIO IRQHandler
 *****************************************************************************/
#if (BSP_GPIO_PB0_PIN & 1)
void GPIO_ODD_IRQHandler(void)
#else
void GPIO_EVEN_IRQHandler(void)
#endif
{
  // Disable button 0 interrupt since it is only needed once
  GPIO_IntDisable(1 << BSP_GPIO_PB0_PIN);

  // Clear the falling edge interrupt flag
  GPIO_IntClear(1 << BSP_GPIO_PB0_PIN);
}

/******************************************************************************/
/**
 * Find first set bit in word.
 */
uint32_t find_first_set_bit(uint32_t word)
{
  uint32_t first_set_bit = 0;

  while (word) {
    if (word & 0x1)
      return first_set_bit;
    word >>= 1;
    first_set_bit ++;
  }

  return 32;
}
/**************************************************************************//**
 * @brief
 *    Read ADPD4100 register
 *****************************************************************************/
uint8_t adpd4100_reg_read(uint16_t address, uint16_t *data) {
  int i;        // uint16_t

  int bytes = 4;

  // Outgoing data
  uint8_t outbuf[bytes];

  // Incoming data
  uint8_t inbuf[bytes];

  // temporary buffer for translating incoming data
  uint8_t buff[] = { 0, 0 };

  // Zero incoming buffer and outgoing data array
  for (i = 0; i < bytes; i++)
  {
    inbuf[i] = (uint8_t)0;
    outbuf[i] = (uint8_t)0;
  }


  // send these 16 bits:
  // ------byte 0------ ------byte 1------
  // 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 Rd
  // |-----(read register address)----| 0
  // (MSB----------LSB) (MSB----------LSB)
  // So to send a read register address of 0x8, CHIP_ID reg
  // 0  0  0  0  0  0 0 0 0 0 0 1 0 0 0 0

  // place bits 0-6 in 2nd byte, and bits 7-15 in 1st byte
  outbuf[1] = (address << 1) & LOWERBYTE_MASK;
  outbuf[0] = (address & UPPERBYTE_MASK) >> find_first_set_bit(UPPERBYTE_MASK);

  // Assert chip select (drive low)
  GPIO_PinOutClear(US0CS_PORT, US0CS_PIN);

  /*
   * Because this example is most likely going to be running with
   * another EFM32/EFR32 device on the secondary side, it must insert
   * a delay between chip select assertion and sending the first
   * byte.
   *
   * On Series 1 and Series 2 EFM32/EFR32 devices, this delay needs
   * to be between 7 and 10 us in order for the downstream firmware
   * to enable SPI reception and pre-load the first byte to be
   * transmitted.
   *
   * Similar delays are not uncommon for things like high-precision
   * delta-sigma A-to-D converters where the falling chip select
   * wakes the device from a low-power state, starts a conversion,
   * and can return data after some set delay.
   */
  for (i = 0; i < 25; i++);

  /*
   * Repeatedly perform single byte SPI transfers (transmission and
   * reception) of the specified length.  USART_SpiTransfer() polls
   * USART_STATUS_TXC for transmission complete, so this function ties
   * up the CPU until the last bit of the byte being transmitted is sent.
   */
  // this will send 2 bytes and then receive 2 bytes
  for (i = 0; i < bytes; i++) {
      inbuf[i] = USART_SpiTransfer(USART0, outbuf[i]);
  }

  // De-assert chip select upon transfer completion (drive high)
  GPIO_PinOutSet(US0CS_PORT, US0CS_PIN);

  /*
   * Insert a short delay after CS de-assertion.  When this code is
   * running on a faster main (e.g. either higher clock rate or a
   * faster CPU such as a Cortex-M3), the secondary implementation
   * running on a slower device (e.g. either lower clock rate or a
   * slower CPU such as a Cortex-M0+) needs extra time to prepare
   * the input and output buffers for the next round of bytes to be
   * transferred.
   */
  for (i = 0; i < 20; i++);

  // load received data into data
  for (i = 0; i < bytes-2; i++) {
    buff[i] = inbuf[i+2];
  }

  // translate the register read
  *data = ((uint16_t)buff[0] << 8) & 0xff00;
  *data |= buff[1] & 0xff;

  return 0;
}

uint8_t adpd4100_reg_write(uint16_t address, uint16_t data) {
  int i;        // uint16_t counter
  int bytes = 4;  // # bites to read/write
  uint8_t r = 0;  // return value
  uint16_t testdata = 0;  // read reg data to verify correct write

  uint8_t outbuf[bytes];    // Outgoing data
  uint8_t inbuf[bytes];     // Incoming data

  uint8_t buff[] = { 0, 0, 0, 0 };    // temporary buffer for translating data

  /*
   * Eliminate unused variable warning so that inbug can be observed
   * in the debugger.
   */
  (void)inbuf;

  // Zero incoming buffer and outgoing data array
  for (i = 0; i < bytes; i++)
  {
    inbuf[i] = (uint8_t)0;
    outbuf[i] = (uint8_t)0;
  }


  // send these 16 bits:
  // ------byte 0------ ------byte 1------
  // 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 Rd
  // |-----(read register address)----| 0
  // (MSB----------LSB) (MSB----------LSB)
  // So to send a read register address of 0x8, CHIP_ID reg
  // 0  0  0  0  0  0 0 0 0 0 0 1 0 0 0 0

  // Due to MSB first, and first bit transmitted indicating read/write,
  //  place bits 0-6 in 2nd byte, and bits 7-15 in 1st byte, etc.
  outbuf[0] = (address & UPPERBYTE_MASK) >> find_first_set_bit(UPPERBYTE_MASK);
  outbuf[1] = ((address << 1) & LOWERBYTE_MASK) | 0x1 ; // set bit 0 to write (1)
  outbuf[2] = (data & 0xff00) >> find_first_set_bit(0xff00);
  outbuf[3] = data & 0xff;            // lowest 16 bits of data

  // Assert chip select (drive low)
  GPIO_PinOutClear(US0CS_PORT, US0CS_PIN);

  /*
   * Because this example is most likely going to be running with
   * another EFM32/EFR32 device on the secondary side, it must insert
   * a delay between chip select assertion and sending the first
   * byte.
   *
   * On Series 1 and Series 2 EFM32/EFR32 devices, this delay needs
   * to be between 7 and 10 us in order for the downstream firmware
   * to enable SPI reception and pre-load the first byte to be
   * transmitted.
   *
   * Similar delays are not uncommon for things like high-precision
   * delta-sigma A-to-D converters where the falling chip select
   * wakes the device from a low-power state, starts a conversion,
   * and can return data after some set delay.
   */
  for (i = 0; i < 25; i++);

  /*
   * Repeatedly perform single byte SPI transfers (transmission and
   * reception) of the specified length.  USART_SpiTransfer() polls
   * USART_STATUS_TXC for transmission complete, so this function ties
   * up the CPU until the last bit of the byte being transmitted is sent.
   */
  // this will send 4 bytes:
  //    out 2 bytes:  address of reg to write
  //    out 2 bytes:  value to write to reg

  for (i = 0; i < bytes; i++) {
      inbuf[i] = USART_SpiTransfer(USART0, outbuf[i]);
  }

  // De-assert chip select upon transfer completion (drive high)
  GPIO_PinOutSet(US0CS_PORT, US0CS_PIN);

  /*
   * Insert a short delay after CS de-assertion.  When this code is
   * running on a faster main (e.g. either higher clock rate or a
   * faster CPU such as a Cortex-M3), the secondary implementation
   * running on a slower device (e.g. either lower clock rate or a
   * slower CPU such as a Cortex-M0+) needs extra time to prepare
   * the input and output buffers for the next round of bytes to be
   * transferred.
   */
  for (i = 0; i < 20; i++);

  // Read the register that was just written to in order to confirm success
  //    out 2 bytes:  address of reg to read
  //    in  2 bytes:  value of reg (should match value to write)
  adpd4100_reg_read(address,&testdata);

  if (testdata == data) {
      r = 0;
  }
  else {
      r = 1;  // error
  }

  return r;
}
