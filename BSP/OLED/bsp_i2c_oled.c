/**
 ***************************************************
 * @file        bsp_i2c_oled.c
 * @brief       I2C底层配置
 ***************************************************
 */

#include "bsp_i2c_oled.h"

/**
 * @brief       初始化OLED相关IOMUXC的MUX复用配置
 * @param       无
 * @retval      无
 */
static void OLED_I2C_IOMUXC_MUX_Config(void)
{
  /* 设置引脚的复用模式为GPIO，使用SION功能 */
  IOMUXC_SetPinMux(OLED_SCL_IOMUXC, 1U);
  IOMUXC_SetPinMux(OLED_SDA_IOMUXC, 1U);
}

/**
 * @brief       初始化OLED相关I2C外设的配置
 * @param       无
 * @retval      无
 */
static void OLED_I2C_Mode_Config(void)
{
  lpi2c_master_config_t masterConfig;
  
  /* 配置LPI2C时钟 */
  CLOCK_SetMux(kCLOCK_Lpi2cMux, LPI2C_CLOCK_SOURCE_SELECT);
  CLOCK_SetDiv(kCLOCK_Lpi2cDiv, LPI2C_CLOCK_SOURCE_DIVIDER);
  
  /*
   * masterConfig.debugEnable = false;
   * masterConfig.ignoreAck = false;
   * masterConfig.pinConfig = kLPI2C_2PinOpenDrain;
   * masterConfig.baudRate_Hz = 100000U;
   * masterConfig.busIdleTimeout_ns = 0;
   * masterConfig.pinLowTimeout_ns = 0;
   * masterConfig.sdaGlitchFilterWidth_ns = 0;
   * masterConfig.sclGlitchFilterWidth_ns = 0;
   */
  LPI2C_MasterGetDefaultConfig(&masterConfig);
  
  masterConfig.baudRate_Hz = OLED_I2C_BAUDRATE;
  
  LPI2C_MasterInit(OLED_I2C_MASTER, &masterConfig, LPI2C_CLOCK_FREQUENCY);
}

/**
 * @brief       初始化LPI2C外设
 * @param       无
 * @retval      无
 */
void OLED_I2C_Init(void)
{
  /* 初始化LPI2C引脚复用、工作模式  */
  OLED_I2C_IOMUXC_MUX_Config();
  OLED_I2C_Mode_Config();
}








