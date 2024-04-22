/**
 ***************************************************
 * @file        DEV_Config.h
 * @brief       OLEDӲ����
 ***************************************************
 */

#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

#include "bsp_i2c_oled.h"
#include "bsp_led.h"

/*-------------------------------*/
/* OLED���ö��� */

#define OLED_ADDR_7BIT 0x3C

#define IIC_CMD    0x00
#define IIC_RAM    0x40

/*-------------------------------*/
/* OLED���Ŷ��� */

/* RST������LEDʹ��ͬһ��I/O�� */
#define OLED_RST_0      LED(0)
#define OLED_RST_1      LED(1)

/*-------------------------------*/
/* �������� */

int I2C_Write_Byte(uint8_t value, uint8_t Cmd);
void Driver_Delay_ms(uint32_t xms);
void Driver_Delay_us(uint32_t xus);


#endif


