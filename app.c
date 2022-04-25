/**************************************************************************//**
 * @file app.c
 * @brief Application interface provided to main().
 * @version 1.0.0
*******************************************************************************
* # License
* <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
*******************************************************************************
*
* SPDX-License-Identifier: Zlib
*
* The licensor of this software is Silicon Laboratories Inc.
*
* This software is provided \'as-is\', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*
*******************************************************************************
* # Experimental Quality
* This code has not been formally tested and is provided as-is. It is not
* suitable for production environments. In addition, this code will not be
* maintained and there may be no bug maintenance planned for these resources.
* Silicon Labs may update projects from time to time.
******************************************************************************/
#include <fatigue/apps/hrm_app.h>
#include <fatigue/ble/config/app_timer.h>
#include <fatigue/ble/config/ble_att_handler.h>
#include <fatigue/ble/device_information/device_information.h>
#include <fatigue/ble/fatigue/fatigue.h>
#include <fatigue/ble/gsr/galvanic_skin_response.h>
#include <fatigue/ble/heart_rate/heart_rate.h>
#include <fatigue/ble/respiratory_rate/respiratory_rate.h>
#include "em_common.h"
#include "app_assert.h"
#include "sl_bluetooth.h"
#include "gatt_db.h"
#include "app.h"

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_usart.h"

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

static void services_init(void);

// The advertising set handle allocated from Bluetooth stack.
static uint8_t advertising_set_handle = 0xff;

static uint8_t connection_handle = 0xff;

/**************************************************************************//**
 * Application Init.
 *****************************************************************************/
SL_WEAK void app_init(void)
{
  /////////////////////////////////////////////////////////////////////////////
  // Put your additional application init code here!                         //
  // This is called once during start-up.                                    //
  /////////////////////////////////////////////////////////////////////////////
  initGPIO();
  initUSART0();
  initADPD4100();
  hrm_init_app();
  services_init();
}

/**************************************************************************//**
 * Application Process Action.
 *****************************************************************************/
SL_WEAK void app_process_action(void)
{
  /////////////////////////////////////////////////////////////////////////////
  // Put your additional application code here!                              //
  // This is called infinitely.                                              //
  // Do not call blocking functions from here!                               //
  /////////////////////////////////////////////////////////////////////////////
  hrm_loop();
}

/**************************************************************************//**
 * Bluetooth stack event handler.
 * This overrides the dummy weak implementation.
 *
 * @param[in] evt Event coming from the Bluetooth stack.
 *****************************************************************************/
void sl_bt_on_event(sl_bt_msg_t *evt)
{
  sl_status_t sc;
  bd_addr address;
  uint8_t address_type;
  uint8_t system_id[8];

  switch (SL_BT_MSG_ID(evt->header))
  {
    /* ------------------------------- */
    /* This event indicates the device has started and the radio is ready. */
    /* Do not call any stack command before receiving this boot event! */
    case sl_bt_evt_system_boot_id:

      /* Extract unique ID from BT Address. */
      sc = sl_bt_system_get_identity_address(&address, &address_type);
      app_assert_status(sc);

      /* Pad and reverse unique ID to get System ID. */
      system_id[0] = address.addr[5];
      system_id[1] = address.addr[4];
      system_id[2] = address.addr[3];
      system_id[3] = 0xFF;
      system_id[4] = 0xFE;
      system_id[5] = address.addr[2];
      system_id[6] = address.addr[1];
      system_id[7] = address.addr[0];

      sc = sl_bt_gatt_server_write_attribute_value(gattdb_system_id,
                                                   0,
                                                   sizeof(system_id),
                                                   system_id);
      app_assert_status(sc);

      /* Create an advertising set. */
      sc = sl_bt_advertiser_create_set(&advertising_set_handle);
      app_assert_status(sc);

      /* Set advertising interval to 100ms. */
      sc = sl_bt_advertiser_set_timing(
        advertising_set_handle,
        160, // min. adv. interval (milliseconds * 1.6)
        160, // max. adv. interval (milliseconds * 1.6)
        0,   // adv. duration
        0);  // max. num. adv. events
      app_assert_status(sc);
      /* Start general advertising and enable connections. */
      sc = sl_bt_advertiser_start(
        advertising_set_handle,
        advertiser_general_discoverable,
        advertiser_connectable_scannable);
      app_assert_status(sc);
      break;

    /* ------------------------------- */
    /* This event indicates that a new connection was opened. */
    case sl_bt_evt_connection_opened_id:
      connection_handle = evt->data.evt_connection_opened.connection;
      break;

    // -------------------------------
    // This event indicates that a connection was closed.
    case sl_bt_evt_connection_closed_id:
      /* Service disconnect handlers */
      heart_rate_disconnect_event(evt);
      fatigue_disconnect_event(evt);
      galvanic_skin_response_disconnect_event(evt);
      respiratory_rate_disconnect_event(evt);
      device_information_disconnect_event(evt);
      connection_handle = 0xff;

      /* Restart advertising after client has disconnected. */
      sc = sl_bt_advertiser_start(
        advertising_set_handle,
        advertiser_general_discoverable,
        advertiser_connectable_scannable);
      app_assert_status(sc);
      break;

    case sl_bt_evt_gatt_server_user_write_request_id:

      /* Service write handlers */

      break;

    case sl_bt_evt_gatt_server_user_read_request_id:

      /* Handle previous read operation for long characteristics */
      if (ble_att_send_data_handler(evt->data.evt_gatt_server_user_read_request.characteristic,
                                    evt->data.evt_gatt_server_user_read_request.offset)) {
        /* Event handled */
        break;
      }

      /* Service read handlers */
      /* Heart Rate characteristics read */
      if (evt->data.evt_gatt_server_user_read_request.characteristic
          == gattdb_body_sensor_location) {
        heart_rate_read_callback(evt);
      }
      /* Device Information characteristics read */
      else if ((evt->data.evt_gatt_server_user_read_request.characteristic
                >= gattdb_manufacturer_name_string)
            && (evt->data.evt_gatt_server_user_read_request.characteristic
                <= gattdb_firmware_revision_string)) {
        device_information_read_callback(evt);
      }
      break;

    case sl_bt_evt_gatt_server_characteristic_status_id:
      /* Heart Rate characteristics read */
      if (evt->data.evt_gatt_server_characteristic_status.characteristic
          == gattdb_heart_rate_measurement) {
        heart_rate_characteristic_status(evt);
      }
      else if (evt->data.evt_gatt_server_characteristic_status.characteristic
          == gattdb_respiratory_rate_measurement) {
        respiratory_rate_characteristic_status(evt);
      }
      else if (evt->data.evt_gatt_server_characteristic_status.characteristic
          == gattdb_galvanic_skin_response_measurement) {
        galvanic_skin_response_characteristic_status(evt);
      }
      else if (evt->data.evt_gatt_server_characteristic_status.characteristic
          == gattdb_fatigued_indication) {
        fatigue_characteristic_status(evt);
      }
      break;

    /* Software Timer event */
    case sl_bt_evt_system_soft_timer_id:
      /* Check which software timer handle is in question */
      if (evt->data.evt_system_soft_timer.handle == HEART_RATE_TIMER) {
        heart_rate_send_new_data(connection_handle);
        break;
      }

      if (evt->data.evt_system_soft_timer.handle == RESPIRATORY_RATE_TIMER) {
        respiratory_rate_send_new_data(connection_handle);
        break;
      }

      if (evt->data.evt_system_soft_timer.handle == GALVANIC_SKIN_RESPONSE_TIMER) {
        galvanic_skin_response_send_new_data(connection_handle);
        break;
      }

      if (evt->data.evt_system_soft_timer.handle == FATIGUE_TIMER) {
        fatigue_send_new_data(connection_handle);
        break;
      }
      break;

    /* ------------------------------- */
    /* Default event handler. */
    default:
      break;
  }
}

/*******************************************************************************
 * @brief
 *   BLE service initialization
 * @param
 *   None
 * @return
 *   None
 ******************************************************************************/
static void services_init(void)
{
  device_information_init();
  heart_rate_init();
  respiratory_rate_init();
  galvanic_skin_response_init();
  fatigue_init();
}

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
  init.baudrate = 50000;  // change from 1 Mbps to 10 Kbps

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

  int i = 0;              // char counter
  int j = 0;              // line counter
  uint16_t deviceid = 0;
  uint8_t r = 0;          // return
  //FILE *config;           // pointer to config file
  int config_lines;       // total lines in config
//  char buff[255];         // parse one line at a time
//  int counter;            // count digits in line of file
  int read_addr = 0;      // track whether we have read the address on the line
  int index = 0;          // address/data array index
//  int endoffile = 0;
//  uint16_t addr = 0;      // temporary address holder
//  uint16_t dat = 0;       // temporary data holder
  uint16_t address[1000]; // max 1000 instructions at a time
  uint16_t dat[1000];
  int comment = 0;            // track if line has a comment/count slashes

  (void)address;

  // wait for ADPD4100 to start up by reading CHIP_ID register
  while (deviceid != 0x2c2) {
      r = adpd4100_reg_read(0x8,&deviceid);
  }

  // set typical default ADPD4100 configuration [1]

  //################################################################
  //## ADPD4100 Reference Config File, single-ended
  //## Please review config file for your design. This is a generic config file.

//  const char configstr[][255] = {
//      "0009 0080 // OSC32M - deafult 0x80 - 32MHz trim - trim your own clock",
//      "000B 02B2 // OCS1M - default 0x2B2 - 1MHz trim - trim your own clock",
//      "000C 0012 // OCS32K - default 0x12 - 32kHz trim - trim your own clock",
//      "000D 2710 // 100 Hz",
//      "000F 0006 // enable 1MHz osc",
//      "0010 0200 // Three timeslots",
//      "0020 0004 // in1 connected to vc1 during sleep, everything else floating",
//      "0021 0000 // all inputs single ended, vc1 set to Vdd during sleep",
//      "0022 0003 // gpio0 is output, inverted",
//      "0023 0002 // intx to gpio0",
//      "0014 8000 // fifo thresh interrupt to intx",
//
//      "// timeslot A - continuous connect mode - green PPG",
//
//      "0100 0000 // Rin = 500, tsA offset = 0, skip subsample",
//      "0101 40DA // path = TIA + BPF + INT + ADC",
//      "0102 0001 // IN1 to channel 1, others disconnected",
//      "0103 5002 // precondition inputs to TIA_Vref, VC1 active state = V_delta",
//      "0104 03C0 // Rf = 200k Rint = 400k",
//      "0105 0707 // 11 mA on LED1A, 2A, 3A",
//      "0106 0007",
//      "0107 0140 // 64 pulses",
//      "0108 0000 // period set by automatic period of continuous connect mode",
//      "0109 0210 // led width= 2us led offset=16 us",
//      "010A 0003 // integrator width=3 us",
//      "010B 0210 // integrator offset=16.5 us - ADJUST FINE OFFSET",
//      "010C 0001 // no modulation",
//      "0110 0003 // signal size = 3 bytes",
//      "010D 0099 // -++- int pattern",
//      "010E 0000 // NO OFFSET - review if needed",
//      "010F 0000 // NO OFFSET - review if needed",
//      "0112 0000 // no decimation",
//
//      "// timeslot B - continuous connect mode - red PPG",
//
//      "0120 0000 // Rin = 500, tsA offset = 0, skip subsample",
//      "0121 40DA // path = TIA + BPF + INT + ADC",
//      "0122 0001 // IN1 to channel 1, others disconnected",
//      "0123 5002 // precondition inputs to TIA_Vref, VC1 active state = V_delta",
//      "0124 03C0 // Rf = 200k Rint = 400k",
//      "0125 0000 // 11 mA on LED3B",
//      "0126 0087",
//      "0127 0140 // 64 pulses",
//      "0128 0000 // period set by automatic period of continuous connect mode",
//      "0129 0210 // led width= 2us led offset=16 us",
//      "012A 0003 // integrator width=3 us",
//      "012B 0210 // integrator offset=16.5 us - ADJUST FINE OFFSET",
//      "012C 0001 // no modulation",
//      "0130 0003 // signal size = 3 bytes",
//      "012D 0099 // -++- int pattern",
//      "012E 0000 // NO OFFSET - review if needed",
//      "012F 0000 // NO OFFSET - review if needed",
//      "0132 0000 // no decimation",
//
//      "// timeslot C - continuous connect mode - IR PPG",
//
//      "0140 0000 // Rin = 500, tsA offset = 0, skip subsample",
//      "0141 40DA // path = TIA + BPF + INT + ADC",
//      "0142 0001 // IN1 to channel 1, others disconnected",
//      "0143 5002 // precondition inputs to TIA_Vref, VC1 active state = V_delta",
//      "0144 03C0 // Rf = 200k Rint = 400k",
//      "0145 0000 // 11 mA on LED4B",
//      "0146 8700",
//      "0147 0140 // 64 pulses",
//      "0148 0000 // period set by automatic period of continuous connect mode",
//      "0149 0210 // led width= 2us led offset=16 us",
//      "014A 0003 // integrator width=3 us",
//      "014B 0210 // integrator offset=16.5 us - ADJUST FINE OFFSET",
//      "014C 0001 // no modulation",
//      "0150 0003 // signal size = 3 bytes",
//      "014D 0099 // -++- int pattern",
//      "014E 0000 // NO OFFSET - review if needed",
//      "014F 0000 // NO OFFSET - review if needed",
//      "0152 0000 // no decimation"
//  };

  //config_lines = sizeof(configstr)/sizeof(configstr[0]);
//  config_lines = 68;

  // open config file from path
  //config = fopen("config.txt","r");

  // read config string line by line and extract the addresses of registers to
  //  write to and the data to write to them, ignoring whitespaces and comments
  //  (indicated with //), until the end
  //while (!endoffile) {

//  for(j=0; j<config_lines; j++) {
//
//    // check every char of the line (buff)
//    for(i=0; i<255; i++) {
//
//        // if comment symbol detected, stop reading that line
//        if (configstr[j][i] == '/') {
//            comment++;  // count comment symbols
//            if (comment == 2) {
//                break;
//            }
//
//        }
//
//        // ignore whitespaces
//        else if (configstr[j][i] == ' ') {}
//
//        // if not a whitespace or comment, it's an address or data
//        else {
//
//            // if address has not been read, read it
//            if (!read_addr) {
//                // as each char is read left to right (4 digits),
//                //  recreate the whole address
//                address[index] = (int)(configstr[j][i] << 12) +
//                    (int)(configstr[j][i+1] << 8) +
//                    (int)(configstr[j][i+2] << 4) +
//                    (int)(configstr[j][i+3]);
//                read_addr = 1;
//            }
//
//            // otherwise, addr is read and we need to read the data
//            else {
//                dat[index] = (int)(configstr[j][i] << 12) +
//                    (int)(configstr[j][i+1] << 8) +
//                    (int)(configstr[j][i+2] << 4) +
//                    (int)(configstr[j][i+3]);
//                index++;        // increment the index
//                read_addr = 0;  // reset address read indicator
//                break;          // stop parsing the line
//            }
//        }
//    }
//  }

  // perform register writes according to collected initial config
//  for (i=0; i<config_lines; i++) {
//      r = adpd4100_reg_write(address[i],dat[i]);
//      if (r == 1) {
//          printf("error");
//      }
//  }

    // OSC_32M_FREQ_ADJ bits 0-7 - High frequency oscillator frequency control
    adpd4100_reg_write(0x9,0x80); // default

    // OSC_1M_FREQ_ADJ bits 0-9 - Low frequency oscillator frequency control
    // 1MHz trim - trim your own clock
    adpd4100_reg_write(0xB,0x2b2); //default

    // OSC_32K_ADJUST bits 0-5 - 32 kHzoscillator trim
    adpd4100_reg_write(0xC,0x12); // default

    // OSC_32K_ADJUST TS_FREQ bits 0-15 TIMESLOT_PERIOD_L
    //  - Lower 16 bits of time slot period in low frequency oscillator cycles.
    //  100 Hz
    r = adpd4100_reg_write(0xD,0x2710); // default
    //if (r == 1) {
    //    printf("error");
    //}

    //  enable 1MHz osc
    adpd4100_reg_write(0xF,0x6);

    // One timeslot active: A
    adpd4100_reg_write(0x10,0x0);

    // in1 connected to vc1 during sleep, everything else floating
    adpd4100_reg_write(0x20,0x4);

    // default:     "0021 0000 // all inputs single ended, vc1 set to Vdd during
    //              sleep",

    // gpio0 is output, inverted
    adpd4100_reg_write(0x22,0x3);

    // GPIO01 bits 0-6 GPIOOUT0 - GPIO0 output signal select
    // 0x2 - Interrupt X
    adpd4100_reg_write(0x23,0x2);

    // INT_ENABLE_XD bit 15 INTX_EN_FIFO_TH - INT_FIFO_TH interrupt enable.
    //    Write a 1 to this bit to enable drive of the FIFO threshold status on
    //    Interrupt X.
    adpd4100_reg_write(0x14,0x8000);

    //      "// timeslot A - continuous connect mode - green PPG",
    //
    //      "0100 0000 // Rin = 500, tsA offset = 0, skip subsample",
    // TS_CTRL_A bits 10-11 INPUT_R_SELECT_A[1:0] - Input resistor (R IN ) select.
    // default

    //      "0101 40DA // path = TIA + BPF + INT + ADC", // default

    //      "0102 0001 // IN1 to channel 1, others disconnected",
    adpd4100_reg_write(0x102,0x1);

    //      "0103 5002 // precondition inputs to TIA_Vref, VC1 active state = V_delta",
    // CATHODE_A
    //    bits 0-1 VC1_SEL_x - VC1 active state for Time Slot x.
    //    10b    TIA_VREF + 215mV
    //    bits 12-14 PRECON_x - Precondition value for enabled inputs during Time Slot x.
    //    101: precondition with TIA_VREF
    adpd4100_reg_write(0x103,0x5002);

    //      "0104 03C0 // Rf = 200k Rint = 400k",
    //  AFE_TRIM_VREF_x:    11: TIA_VREF = 1.265 V.
    //  VREF_PULSE_VAL_x:   11: modulate TIA_VREF = 1.265 V.
    adpd4100_reg_write(0x104,0x3c0);

    //      "0105 0707 // 11 mA on LED1A, 2A, 3A",
    adpd4100_reg_write(0x105,0x707);
    adpd4100_reg_write(0x106,0x7);

    //      "0107 0140 // 64 pulses",
    adpd4100_reg_write(0x107,0x140);

    //      "0108 0000 // period set by automatic period of continuous connect mode", // default

    //      "0109 0210 // led width= 2us led offset=16 us",
    adpd4100_reg_write(0x109,0x210);

    // b11 integrator width=3 us // default
    // INTEG_SETUP_A bits 6-7 ADC_COUNT_x - ADC conversions per pulse =
    //      ADC_COUNT_x + 1
    //adpd4100_reg_write(0x10a,0x3);

    //      "010B 0210 // integrator offset=16.5 us - ADJUST FINE OFFSET",
    adpd4100_reg_write(0x10b,0x210);

    //      "010C 0001 // no modulation",
    adpd4100_reg_write(0x10c,0x1);

    //      "0110 0003 // signal size = 3 bytes",
    adpd4100_reg_write(0x110,0x3);

    //      "010D 0099 // -++- int pattern",
    adpd4100_reg_write(0x10d,0x99);

    // all default below
    //      "010E 0000 // NO OFFSET - review if needed",
    //      "010F 0000 // NO OFFSET - review if needed",
    //      "0112 0000 // no decimation",

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

  /*
   * Eliminate unused variable warning so that inbug can be observed
   * in the debugger.
   */
  //(void)inbuf;

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

//  free(buff);
  //if (address == (uint16_t)(0x1)) {
  //    printf("breakpoint");
  //}

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
