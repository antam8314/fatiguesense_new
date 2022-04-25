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
      //pulse_oximeter_disconnect_event(evt);
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
