/**
 ***************************************************
 * @file        bsp_led.c
 * @brief       LED驱动代码
 ***************************************************
 */

#include "bsp_led.h"

/**
 * @brief       初始化LED相关IOMUXC的MUX复用配置
 * @param       无
 * @retval      无
 */
static void LED_IOMUXC_MUX_Config(void)
{
  /* 设置引脚的复用模式为GPIO，不使用SION功能 */
  IOMUXC_SetPinMux(LED_IOMUXC, 0U);
}

/**
 * @brief       初始化LED相关的GPIO模式
 * @param       无
 * @retval      无
 */
static void LED_GPIO_Mode_Config(void)
{
  /* GPIO初始化配置结构体 */
  gpio_pin_config_t led_config;
  
  led_config.direction = kGPIO_DigitalOutput;   /* 输出模式 */
  led_config.outputLogic = 1;                   /* 默认高电平 */
  led_config.interruptMode = kGPIO_NoIntmode;   /* 不使用中断 */
  
  GPIO_PinInit(LED_GPIO, LED_GPIO_PIN, &led_config);
}

/**
 * @brief       初始化LED的GPIO
 * @param       无
 * @retval      无
 */
void LED_Init(void)
{
  /* 初始化GPIO复用、模式 */
  LED_IOMUXC_MUX_Config();
  LED_GPIO_Mode_Config();
}








