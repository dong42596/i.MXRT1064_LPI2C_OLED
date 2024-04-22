/**
 ***************************************************
 * @file        bsp_i2c_oled.c
 * @brief       I2C�ײ�����
 ***************************************************
 */

#include "bsp_i2c_oled.h"

/**
 * @brief       ��ʼ��OLED���IOMUXC��MUX��������
 * @param       ��
 * @retval      ��
 */
static void OLED_I2C_IOMUXC_MUX_Config(void)
{
  /* �������ŵĸ���ģʽΪGPIO��ʹ��SION���� */
  IOMUXC_SetPinMux(OLED_SCL_IOMUXC, 1U);
  IOMUXC_SetPinMux(OLED_SDA_IOMUXC, 1U);
}

/**
 * @brief       ��ʼ��OLED���I2C���������
 * @param       ��
 * @retval      ��
 */
static void OLED_I2C_Mode_Config(void)
{
  lpi2c_master_config_t masterConfig;
  
  /* ����LPI2Cʱ�� */
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
 * @brief       ��ʼ��LPI2C����
 * @param       ��
 * @retval      ��
 */
void OLED_I2C_Init(void)
{
  /* ��ʼ��LPI2C���Ÿ��á�����ģʽ  */
  OLED_I2C_IOMUXC_MUX_Config();
  OLED_I2C_Mode_Config();
}








