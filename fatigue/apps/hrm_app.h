/**************************************************************************//**
 * @file hrm_app.h
 * @brief Header file of hrm_app.c
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
#ifndef HRM_APP_H__
#define HRM_APP_H__

#define HRM_DEMO_NAME "FatigueSense Heart Rate"
#define HRM_DEMO_VERSION "1.0.0"

#define MS_IN_MINUTE 60000
#define SEC_IN_MINUTE 60

#define Q15_SBIT    0x8000
#define Q15_MBITS   0x7FFF
#define Q15_MULT    0x8000
#define Q15_PMAX    0x7FFF
#define Q15_NMAX    0x8000

#define TESTING 1

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include "sl_sleeptimer.h"

/**************************************************************************//**
 * @brief Initialize the HRM application.
 *****************************************************************************/
void hrm_init_app(void);

/**************************************************************************//**
 * @brief HRM process main loop.
 *****************************************************************************/
void hrm_loop(void);

/**************************************************************************//**
 * @brief callback from timer to process data
 *****************************************************************************/
#ifdef TESTING
void hrm_process_input(sl_sleeptimer_timer_handle_t *handle, void *data);
#else
void hrm_process_input(void);
#endif

/**************************************************************************//**
 * @brief This function calculates the period mean RR
 *****************************************************************************/
void hrm_calculate_mean_rr(void);

/**************************************************************************//**
 * @brief This function performs the FFT to extract respiratory rate
 *****************************************************************************/
void hrm_calculate_resp_rate(void);

/**************************************************************************//**
 * @brief This function returns the current heart rate.
 *****************************************************************************/
uint16_t hrm_get_heart_rate(void);

/**************************************************************************//**
 * @brief This function returns the current mean rr.
 *****************************************************************************/
uint16_t hrm_get_heart_rate_mean_rr(void);

/**************************************************************************//**
 * @brief This function returns the HRV Fatigue indication status
 *****************************************************************************/
bool hrm_get_hrv_fatigue(void);

/**************************************************************************//**
 * @brief Return tick time in ms
 *****************************************************************************/
uint64_t get_time_ms(void);

/**************************************************************************//**
 * @brief This function returns the current respiratory rate.
 *****************************************************************************/
uint16_t hrm_get_resp_rate(void);

/**************************************************************************//**
 * @brief This function returns the current respiratory intensity.
 *****************************************************************************/
uint16_t hrm_get_resp_intensity(void);

/**************************************************************************//**
 * @brief This function returns the Respiratory Fatigue indication status
 *****************************************************************************/
bool hrm_get_resp_fatigue(void);
/**************************************************************************//**
 * @brief Convert float to q15
 *****************************************************************************/
int16_t f_to_q15 (float f);

/**************************************************************************//**
 * @brief Convert q15 to float
 *****************************************************************************/
float q15_to_f (int16_t q15);

#endif    //HRM_APP_H__
