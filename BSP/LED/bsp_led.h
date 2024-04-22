/**
 ***************************************************
 * @file        bsp_led.h
 * @brief       LED��������
 ***************************************************
 */

#ifndef __LED_H
#define __LED_H

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"

/*-------------------------------*/
/* ���Ŷ��� */

#define LED_GPIO        GPIO1
#define LED_GPIO_PIN    (9U)
#define LED_IOMUXC      IOMUXC_GPIO_AD_B0_09_GPIO1_IO09

/*-------------------------------*/
/* �˿ڶ��� */

#define LED(x)        do{ x ? \
                        GPIO_PinWrite(LED_GPIO, LED_GPIO_PIN, 1U) : \
                        GPIO_PinWrite(LED_GPIO, LED_GPIO_PIN, 0U) ; \
                      }while(0)

//#define LED_TOGGLE    

/*-------------------------------*/
/* �������� */

void LED_Init(void);


#endif
