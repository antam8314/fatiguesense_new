/**************************************************************************//**
 * @file   respiratory_rate.c
 * @brief  Respiratory rate service
 * @version 1.1.0
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
 
/*******************************************************************************
 *******************************   INCLUDES   **********************************
 ******************************************************************************/
#include <fatigue/apps/hrm_app.h>
#include <fatigue/ble/config/app_timer.h>
#include <fatigue/ble/config/ble_att_handler.h>
#include <fatigue/ble/respiratory_rate/respiratory_rate.h>
#include "sl_bt_api.h"
#include "gatt_db.h"
#include <string.h>
#include <stdio.h>

#define ATT_WRITE_NOT_PERMITTED 0x03

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/


 
/*******************************************************************************
 *******************************   TYPEDEFS   **********************************
 ******************************************************************************/
typedef struct
{
  uint16_t respiratory_rate_measurement;
  uint16_t respiratory_intensity_measurement;
} respiratory_rate_t;
 
/*******************************************************************************
 *****************************   LOCAL DATA   **********************************
 ******************************************************************************/
static respiratory_rate_t service_data;
static bool notifications_enabled = false;
 
/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/
 
/*******************************************************************************
 * @brief
 *   Service Respiratory Rate initialization
 * @return
 *   None
 ******************************************************************************/
void respiratory_rate_init(void)
{
  // Initialize const strings values
  service_data.respiratory_rate_measurement = 0;
  service_data.respiratory_intensity_measurement = 0;
}

/*******************************************************************************
 * @brief
 *   Function to handle read data
 * @param[in] evt
 *   Gecko event
 * @return
 *   None
 ******************************************************************************/
/*void respiratory_rate_read_callback(sl_bt_msg_t *evt)
{
  
}*/

/*******************************************************************************
 * @brief
 *   Function to handle write data
 * @param[in] evt
 *   Gecko event
 * @return
 *   None
 ******************************************************************************/
/*void respiratory_rate_write_callback(sl_bt_msg_t *evt)
{

}*/

/*******************************************************************************
 * @brief
 *   Function to handle disconnect event
 * @param[in] evt
 *   Gecko event
 * @return
 *   None
 ******************************************************************************/
void respiratory_rate_disconnect_event(sl_bt_msg_t *evt)
{
  (void)evt;
  // stop timer for indicate and notify
  if (notifications_enabled == true) {
    notifications_enabled = false;
    sl_bt_system_set_soft_timer(0, RESPIRATORY_RATE_TIMER, 0);
  }
}

/*******************************************************************************
 * @brief
 *   Function to handle gecko_evt_gatt_server_characteristic_status_id event
 * @param[in] evt
 *   Gecko event
 * @return
 *   None
 ******************************************************************************/
void respiratory_rate_characteristic_status(sl_bt_msg_t *evt)
{
  uint8_t send_data[3]; // two bytes for rate and one byte for intensity
  
  service_data.respiratory_rate_measurement = hrm_get_resp_rate();
  send_data[0] = service_data.respiratory_rate_measurement & 0xff;
  send_data[1] = (service_data.respiratory_rate_measurement >> 8) & 0xff;

  service_data.respiratory_intensity_measurement = hrm_get_resp_intensity();
  send_data[2] = service_data.respiratory_intensity_measurement;

  // Notification or Indication status changed for Respiratory Rate Measurement
  if (evt->data.evt_gatt_server_characteristic_status.characteristic
      == gattdb_respiratory_rate_measurement
      && evt->data.evt_gatt_server_characteristic_status.status_flags
      == gatt_server_client_config ) {
    // Notification or Indication - enabled
    if (evt->data.evt_gatt_server_characteristic_status.client_config_flags) {
      //Start a software timer 500ms interval
      sl_bt_system_set_soft_timer(16384, RESPIRATORY_RATE_TIMER, 0);

      sl_bt_gatt_server_send_notification(
           evt->data.evt_gatt_server_characteristic_status.connection,
           evt->data.evt_gatt_server_characteristic_status.characteristic,
           3,
           send_data);
      notifications_enabled = true;
    }
    // Notification or Indication - disabled
    else {
      notifications_enabled = false;
      //Stop the software timer 
      sl_bt_system_set_soft_timer(0, RESPIRATORY_RATE_TIMER, 0);
    }
  }
}

/*******************************************************************************
 * @brief
 *   Function to update Respiratory Rate data
 * @return
 *   None
 ******************************************************************************/
void respiratory_rate_send_new_data(uint8_t connect)
{
  uint8_t send_data[3]; // two bytes for rate and one byte for intensity

  service_data.respiratory_rate_measurement = hrm_get_resp_rate();
  send_data[0] = service_data.respiratory_rate_measurement & 0xff;
  send_data[1] = (service_data.respiratory_rate_measurement >> 8) & 0xff;

  service_data.respiratory_intensity_measurement = hrm_get_resp_intensity();
  send_data[2] = service_data.respiratory_intensity_measurement;

  if (notifications_enabled == true) {
     sl_bt_gatt_server_send_notification(connect,
                                         gattdb_respiratory_rate_measurement,
                                         3,
                                         send_data);
  }
}

