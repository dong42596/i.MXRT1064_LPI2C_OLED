/**
 ***************************************************
 * @file        bsp_led.h
 * @brief       LED驱动代码
 ***************************************************
 */

#ifndef __LED_H
#define __LED_H

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"

/*-------------------------------*/
/* 引脚定义 */

#define LED_GPIO        GPIO1
#define LED_GPIO_PIN    (9U)
#define LED_IOMUXC      IOMUXC_GPIO_AD_B0_09_GPIO1_IO09

/*-------------------------------*/
/* 端口定义 */

#define LED(x)        do{ x ? \
                        GPIO_PinWrite(LED_GPIO, LED_GPIO_PIN, 1U) : \
                        GPIO_PinWrite(LED_GPIO, LED_GPIO_PIN, 0U) ; \
                      }while(0)

//#define LED_TOGGLE    

/*-------------------------------*/
/* 函数声明 */

void LED_Init(void);


#endif
