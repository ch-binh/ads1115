/**
********************************************************************************
* @file     ads1115.c
* @author  	Binh Pham
* @version 	1.0
* @date    	2025-05-09
* @brief    C driver for ADC ADS1115
* @details
********************************************************************************
* @attention
*
********************************************************************************
*/

#ifndef __ADS1115_H
#define __ADS1115_H

#include <stdint.h>
#include "ads1115_reg.h"
/**
 * Hardware Abstraction Layer for ADS1115
 * =============================================================================
 * =============================================================================
 */

typedef struct
{
  void (*write)(uint8_t *data, uint8_t size);
  void (*read)(uint8_t *data, uint8_t size);
} ads1115_ops_t;

void ads1115_set_hw_ops(ads1115_ops_t *ops);

void ads1115_read(uint8_t *data, uint8_t size);
void ads1115_write(uint8_t *data, uint8_t size);

/**
 * Application Abstraction Layer for ADS1115
 * =============================================================================
 * =============================================================================
 */

/**
 * Basic functions
 * =============================================================================
 */
void ads1115_read_reg(uint8_t reg_addr, uint8_t *buf, uint8_t buf_size);
/**
 * Bit manipulation functions
 * =============================================================================
 */

/**
 *  @brief Choose the input channel for the ADC
 *  @param mux 0: A0 - A1, 1: A0 - A3, 2: A1 - A3, 3: A2 - A3, 4: A0 - GND, 5:
 * A1 - GND, 6: A2 - GND, 7: A3 - GND
 */
void ads1115_set_cfg_mux(uint8_t mux);

/**
 * @brief Set the configuration register to the desired gain
 * @param pga 0: +/-6.144V, 1: +/-4.096V, 2: +/-2.048V, 3: +/-1.024V, 4:
 * +/-0.512V, 5: +/-0.256V
 */
void ads1115_set_cfg_pga(uint8_t pga);

/**
 * @brief Set the configuration register to continuous mode
 * @param mode 0: single-shot, 1: continuous
 */
void ads1115_set_cfg_op_mode(uint8_t mode);

/**
 * @brief Set the configuration register to the desired data rate
 * @param data_rate 0: 8SPS, 1: 16SPS, 2: 32SPS, 3: 64SPS, 4: 128SPS, 5: 250SPS
 */
void ads1115_set_cfg_data_rate(uint8_t data_rate);

/**
 * Application functions
 * =============================================================================
 */

void ads1115_reg_init(void);

uint16_t ads1115_get_conversion(void);

/**
 * Test functions
 * =============================================================================
 */

void ads1115_test(void);

#endif // __ADS1115_H