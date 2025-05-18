/**
********************************************************************************
* @file     cmd_handler.c
* @author  	Binh Pham
* @version 	1.1
* @date    	2025-05-09
* @brief    Command handler: This module is for executing commands from
*           another sources, such as UART from PC, I2C from another MCU...
* @details
********************************************************************************
* @attention
*
********************************************************************************
*/

#include "ads1115.h"

/**
 * SETUPS COMPONENTS
 * =============================================================================
 */

/* Private defines -----------------------------------------------------------*/
/* Private enumerate/structure -----------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static ads1115_ops_t hw_ops;
/* Private function prototypes -----------------------------------------------*/
/* Function prototypes -------------------------------------------------------*/

/**
 * @brief   NONE
 *
 * @note    NONE
 *
 * @param   NONE
 *
 * @return  NONE
 */
void ads1115_set_hw_ops(ads1115_ops_t *ops)
{
  hw_ops = *ops; // Copy the function pointers
}

/**
 * @brief   NONE
 *
 * @note    NONE
 *
 * @param   NONE
 *
 * @return  NONE
 */
void ads1115_read(uint8_t *data, uint8_t size)
{
  if (hw_ops.read)
  {
    hw_ops.read(data, size);
  }
  return; // Error: function not set
}

/**
 * @brief   NONE
 *
 * @note    NONE
 *
 * @param   NONE
 *
 * @return  NONE
 */
void ads1115_write(uint8_t *data, uint8_t size)
{
  if (hw_ops.write)
  {
    hw_ops.write(data, size);
  }
  return; // Error: function not set
}

/**
 * Basic functions
 * =============================================================================
 */

static void ads1115_set_bit(uint8_t *reg, uint8_t num_bits,
                            uint8_t start_bit_idx, uint8_t new_val)
{
  uint8_t bit_mask = 0;
  for (int i = 0; i < num_bits; i++)
  {
    bit_mask |=
      (1 << (start_bit_idx + i)); // Create a bit mask for the specified bits
  }
  uint8_t x = reg[0]; // Read the first byte of the register
  x &= ~(bit_mask);   // clear the target bits
  x |= ((new_val << start_bit_idx) &
        bit_mask); // Set the new value for the target bits
  reg[0] = x;      // Write back to the register
}

void ads1115_read_reg(uint8_t reg_addr, uint8_t *buf, uint8_t buf_size)
{
  ads1115_write(&reg_addr, 1); // pointing to config register
  ads1115_read(buf, buf_size); // Read config register

  return;
}

/**
 * Bit manipulation functions
 * =============================================================================
 */

/**
 *  @brief Choose the input channel for the ADC
 *  @param mux 0: A0 - A1, 1: A0 - A3, 2: A1 - A3, 3: A2 - A3, 4: A0 - GND, 5:
 * A1 - GND, 6: A2 - GND, 7: A3 - GND
 */
void ads1115_set_cfg_mux(uint8_t mux)
{
  /* Read back registers*/
  uint8_t cfg_regs[2];
  ads1115_read_reg(ADSREG_CFG_REG, cfg_regs,
                   sizeof(cfg_regs)); // Read current configuration register
  /* Modify the gain bits*/
  ads1115_set_bit(&cfg_regs[ADSREG_CFG_MUX_REG_BYTE], ADSREG_CFG_MUX_BIT_NUM,
                  ADSREG_CFG_MUX_BIT_IDX,
                  mux); // Set the OS bit to 1 for continuous mode
  uint8_t set_data[3] = { ADSREG_CFG_REG, cfg_regs[0], cfg_regs[1] };
  ads1115_write(set_data,
                sizeof(set_data)); // Write back to the configuration register
  return;
}

/**
 * @brief Set the configuration register to the desired gain
 * @param pga 0: +/-6.144V, 1: +/-4.096V, 2: +/-2.048V, 3: +/-1.024V, 4:
 * +/-0.512V, 5: +/-0.256V
 */
void ads1115_set_cfg_pga(uint8_t pga)
{
  /* Read back registers*/
  uint8_t cfg_regs[2];
  ads1115_read_reg(ADSREG_CFG_REG, cfg_regs,
                   sizeof(cfg_regs)); // Read current configuration register
  /* Modify the gain bits*/
  ads1115_set_bit(&cfg_regs[ADSREG_CFG_PGA_REG_BYTE], ADSREG_CFG_PGA_BIT_NUM,
                  ADSREG_CFG_PGA_BIT_IDX,
                  pga); // Set the OS bit to 1 for continuous mode
  uint8_t set_data[3] = { ADSREG_CFG_REG, cfg_regs[0], cfg_regs[1] };
  ads1115_write(set_data,
                sizeof(set_data)); // Write back to the configuration register
  return;
}

/**
 * @brief Set the configuration register to continuous mode
 * @param mode 0: single-shot, 1: continuous
 */
void ads1115_set_cfg_op_mode(uint8_t mode)
{
  /* Read back registers*/
  uint8_t cfg_regs[2];
  ads1115_read_reg(ADSREG_CFG_REG, cfg_regs,
                   sizeof(cfg_regs)); // Read current configuration register
  /* Modify the gain bits*/
  ads1115_set_bit(&cfg_regs[ADSREG_CFG_MODE_REG_BYTE], ADSREG_CFG_MODE_BIT_NUM,
                  ADSREG_CFG_MODE_BIT_IDX,
                  mode); // Set the OS bit to 1 for continuous mode
  uint8_t set_data[3] = { ADSREG_CFG_REG, cfg_regs[0], cfg_regs[1] };
  ads1115_write(set_data,
                sizeof(set_data)); // Write back to the configuration register
  return;
}

/**
 * @brief Set the configuration register to the desired data rate
 * @param data_rate 0: 8SPS, 1: 16SPS, 2: 32SPS, 3: 64SPS, 4: 128SPS, 5: 250SPS
 */
void ads1115_set_cfg_data_rate(uint8_t data_rate)
{
  /* Read back registers*/
  uint8_t cfg_regs[2];
  ads1115_read_reg(ADSREG_CFG_REG, cfg_regs,
                   sizeof(cfg_regs)); // Read current configuration register
  /* Modify the gain bits*/
  ads1115_set_bit(&cfg_regs[ADSREG_CFG_DR_REG_BYTE], ADSREG_CFG_DR_BIT_NUM,
                  ADSREG_CFG_DR_BIT_IDX,
                  data_rate); // Set the OS bit to 1 for continuous mode
  uint8_t set_data[3] = { ADSREG_CFG_REG, cfg_regs[0], cfg_regs[1] };
  ads1115_write(set_data,
                sizeof(set_data)); // Write back to the configuration register
  return;
}

/**
 * Application functions
 * =============================================================================
 */

void ads1115_reg_init(void)
{
  ads1115_set_cfg_pga(ADSREG_CFG_PGA_6_144V); // Set the gain to +/-2.048V
  ads1115_set_cfg_op_mode(
    ADSREG_CFG_MODE_CONTINUOUS); // Set the mode to continuous
  ads1115_set_cfg_data_rate(ADSREG_CFG_DR_64SPS);
  return;
}

/**
 * @brief    Get the conversion value from the ADS1115
 *
 * @note     IMPORTANT: must set a delay > than data rate before calling this
 *
 * @return   The conversion value as a 16-bit unsigned integer
 */
uint16_t ads1115_get_conversion(void)
{
  ads1115_write((uint8_t[]){ ADSREG_CONV_REG },
                1); // point to conversion register
  uint8_t data_arr[2];
  ads1115_read(data_arr, sizeof(data_arr)); // Read conversion register
  return (data_arr[0] << 8) | data_arr[1];  // Combine MSB and LSB
}

/**
 * Test functions
 * =============================================================================
 */

void ads1115_test(void)
{
  /* This is according to quick start guide */
  /*
   * 1. Write to Config register:
   * • First byte: 10010000b (first 7-bit I2C address followed by a low R/W bit)
   * • Second byte: 00000001b (points to Config register)
   * • Third byte: 10000100b (MSB of the Config register to be written)
   * • Fourth byte: 10000011b (LSB of the Config register to be written)
   * 2. Write to Address Pointer register:
   * • First byte: 10010000b (first 7-bit I2C address followed by a low R/W bit)
   * • Second byte: 00000000b (points to Conversion register)
   * 3. Read Conversion register:
   * • First byte: 10010001b (first 7-bit I2C address followed by a high R/W
   * bit) • Second byte: the ADS111x responds with the MSB of the Conversion
   * register. • Third byte: the ADS111x responds with the LSB of the Conversion
   * register
   */

  /* 1. Write to Config register*/
  uint8_t data_arr_1[3] = { 0b00000001, 0b10000100, 0b10000011 };
  ads1115_write(data_arr_1, sizeof(data_arr_1)); // Initialize ADS1115
  /* 2. Write to address pointer register*/
  uint8_t data_arr_2[1] = { 0x00 };
  ads1115_write(data_arr_2, sizeof(data_arr_2));
  /* 3. Read */
  uint8_t data_arr_3[2];
  ads1115_read(data_arr_3, sizeof(data_arr_3)); // Read conversion register

  return;
}

/*****************************END OF FILE**************************************/