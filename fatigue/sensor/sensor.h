// engineer: Alex Stanfill
// created: 03/22
// modified from original
/***************************************************************************//**
 * @file
 * @brief Sensor interface.
 ******************************************************************************/

#ifndef SENSOR_H
#define SENSOR_H

#include "em_common.h"
#include "app_assert.h"
#include "sl_bluetooth.h"
#include "gatt_db.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_usart.h"

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

#endif // SENSOR_H
