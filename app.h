/***************************************************************************//**
 * @file
 * @brief Application interface provided to main().
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
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
 ******************************************************************************/

#ifndef APP_H
#define APP_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

/**************************************************************************//**
 * Application Init.
 *****************************************************************************/
void app_init(void);

/**************************************************************************//**
 * @brief
 *    GPIO initialization
 *****************************************************************************/
void initGPIO(void);

/**************************************************************************//**
 * @brief
 *    USART0 initialization
 *****************************************************************************/
void initUSART0(void);

/**************************************************************************//**
 * ADPD4100 Init.
 *****************************************************************************/
void initADPD4100(void);

#if (BSP_GPIO_PB0_PIN & 1)
void GPIO_ODD_IRQHandler(void);
#else
void GPIO_EVEN_IRQHandler(void);
#endif

/******************************************************************************/
/**
 * Find first set bit in word.
 */
uint32_t find_first_set_bit(uint32_t word);

/**************************************************************************//**
 *    Read ADPD4100 register
 *****************************************************************************/
uint8_t adpd4100_reg_read(uint16_t address, uint16_t *data);

/**************************************************************************//**
 *    Write ADPD4100 register
 *****************************************************************************/
uint8_t adpd4100_reg_write(uint16_t address, uint16_t data);

/**************************************************************************//**
 * Application Process Action.
 *****************************************************************************/
void app_process_action(void);

#endif // APP_H
