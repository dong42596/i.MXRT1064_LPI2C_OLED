/**
 ***************************************************
 * @file        bsp_i2c_oled.h
 * @brief       I2C底层配置
 ***************************************************
 */

#ifndef __I2C_OLED_H
#define __I2C_OLED_H

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_lpi2c.h"

/*-------------------------------*/
/* lpi2c配置定义 */

#define OLED_I2C_MASTER_BASE    (LPI2C1_BASE)
#define OLED_I2C_MASTER         ((LPI2C_Type *)OLED_I2C_MASTER_BASE)
#define OLED_I2C_BAUDRATE       400000U

#define LPI2C_CLOCK_SOURCE_SELECT       (0U)
#define LPI2C_CLOCK_SOURCE_DIVIDER      (5U)
#define LPI2C_CLOCK_FREQUENCY           ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (LPI2C_CLOCK_SOURCE_DIVIDER + 1U))

/*-------------------------------*/
/* lpi2c引脚定义 */

#define OLED_SCL_IOMUXC         IOMUXC_GPIO_AD_B1_00_LPI2C1_SCL
#define OLED_SDA_IOMUXC         IOMUXC_GPIO_AD_B1_01_LPI2C1_SDA




/*-------------------------------*/
/* 函数声明 */

void OLED_I2C_Init(void);




#endif

