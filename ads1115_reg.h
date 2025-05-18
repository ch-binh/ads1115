/**
 * DEFINES - ADS1115 Registers
 * ==================================================================
 * ==================================================================
 */

#define ADSREG_LSB 0x01
#define ADSREG_MSB 0x00

/* Address pointer */
#define ADSREG_CONV_REG 0x00     // Conversion register
#define ADSREG_CFG_REG 0x01      // Configuration register
#define ADSREG_LOTHRESH_REG 0x02 // Low threshold register
#define ADSREG_HITHRESH_REG 0x03 // High threshold register

/* Operation status */
#define ADSREG_CFG_OS_NOP 0x00    // No operation
#define ADSREG_CFG_OS_SINGLE 0x01 // Start a single conversion

/* Input multiplex */
#define ADSREG_CFG_MUX_BIT_NUM 0x03        // 3 bits
#define ADSREG_CFG_MUX_BIT_IDX 0x04        // bits 4, 5 and 6
#define ADSREG_CFG_MUX_REG_BYTE ADSREG_MSB // msb byte
#define ADSREG_CFG_AIN0_IN_AIN1_REF 0x00   // AIN0 input with ref from AIN1
#define ADSREG_CFG_AIN0_IN_AIN3_REF 0x01   // AIN0 input with ref from AIN3
#define ADSREG_CFG_AIN1_IN_AIN3_REF 0x02   // AIN1 input with ref from AIN3
#define ADSREG_CFG_AIN2_IN_AIN3_REF 0x03   // AIN2 input with ref from AIN3
#define ADSREG_CFG_AIN0_IN_GND 0x04        // AIN0 input with ref from GND
#define ADSREG_CFG_AIN1_IN_GND 0x05        // AIN1 input with ref from GND
#define ADSREG_CFG_AIN2_IN_GND 0x06        // AIN2 input with ref from GND
#define ADSREG_CFG_AIN3_IN_GND 0x07        // AIN3 input with ref from GND

/* Programmable gain amplifier */
#define ADSREG_CFG_PGA_BIT_NUM 0x03        // 3 bits
#define ADSREG_CFG_PGA_BIT_IDX 0x01        // bits 1, 2 and 3
#define ADSREG_CFG_PGA_REG_BYTE ADSREG_MSB // 2nd byte
#define ADSREG_CFG_PGA_6_144V 0x00         // +/-6.144V
#define ADSREG_CFG_PGA_4_096V 0x01         // +/-4.096V
#define ADSREG_CFG_PGA_2_048V 0x02         // +/-2.048V
#define ADSREG_CFG_PGA_1_024V 0x03         // +/-1.024V
#define ADSREG_CFG_PGA_0_512V 0x04         // +/-0.512V
#define ADSREG_CFG_PGA_0_256V 0x05         // +/-0.256V

/* Device operating mode */
#define ADSREG_CFG_MODE_BIT_NUM 0x01        // 1 bit
#define ADSREG_CFG_MODE_BIT_IDX 0x00        // bit 0
#define ADSREG_CFG_MODE_REG_BYTE ADSREG_MSB // 2nd byte
#define ADSREG_CFG_MODE_CONTINUOUS 0x00     // Continuous conversion mode
#define ADSREG_CFG_MODE_SINGLE 0x01         // Single-shot mode

/* Data rate */
#define ADSREG_CFG_DR_BIT_NUM 0x03        // 3 bit
#define ADSREG_CFG_DR_BIT_IDX 0x05        // bit 5,6,7
#define ADSREG_CFG_DR_REG_BYTE ADSREG_LSB // lsb byte
#define ADSREG_CFG_DR_8SPS 0x00             // 8 samples per second
#define ADSREG_CFG_DR_16SPS 0x01            // 16 samples per second
#define ADSREG_CFG_DR_32SPS 0x02            // 32 samples per second
#define ADSREG_CFG_DR_64SPS 0x03            // 64 samples per second
#define ADSREG_CFG_DR_128SPS 0x04           // 128 samples per second
#define ADSREG_CFG_DR_250SPS 0x05           // 250 samples per second
#define ADSREG_CFG_DR_475SPS 0x06           // 475 samples per second
#define ADSREG_CFG_DR_860SPS 0x07           // 860 samples per second

/* Comparator mode */
#define ADSREG_CFG_COMP_MODE_TRAD 0x00   // Traditional comparator
#define ADSREG_CFG_COMP_MODE_WINDOW 0x01 // Window comparator

/* Comparator polarity */
#define ADSREG_CFG_COMP_POL_LOW 0x00  // Active low
#define ADSREG_CFG_COMP_POL_HIGH 0x01 // Active high

/* Comparator latch */
#define ADSREG_CFG_COMP_LAT_NONLATCH 0x00 // Non-latching comparator
#define ADSREG_CFG_COMP_LAT_LATCH 0x01    // Latching comparator

/* Comparator queue */
#define ADSREG_CFG_COMP_QUE_1CONV 0x00   // Assert after 1 conversion
#define ADSREG_CFG_COMP_QUE_2CONV 0x01   // Assert after 2 conversions
#define ADSREG_CFG_COMP_QUE_4CONV 0x02   // Assert after 4 conversions
#define ADSREG_CFG_COMP_QUE_DISABLE 0x03 // Disable comparator
