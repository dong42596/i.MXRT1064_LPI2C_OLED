/**
 ***************************************************
 * @file        bsp_led.c
 * @brief       LED��������
 ***************************************************
 */

#include "bsp_led.h"

/**
 * @brief       ��ʼ��LED���IOMUXC��MUX��������
 * @param       ��
 * @retval      ��
 */
static void LED_IOMUXC_MUX_Config(void)
{
  /* �������ŵĸ���ģʽΪGPIO����ʹ��SION���� */
  IOMUXC_SetPinMux(LED_IOMUXC, 0U);
}

/**
 * @brief       ��ʼ��LED��ص�GPIOģʽ
 * @param       ��
 * @retval      ��
 */
static void LED_GPIO_Mode_Config(void)
{
  /* GPIO��ʼ�����ýṹ�� */
  gpio_pin_config_t led_config;
  
  led_config.direction = kGPIO_DigitalOutput;   /* ���ģʽ */
  led_config.outputLogic = 1;                   /* Ĭ�ϸߵ�ƽ */
  led_config.interruptMode = kGPIO_NoIntmode;   /* ��ʹ���ж� */
  
  GPIO_PinInit(LED_GPIO, LED_GPIO_PIN, &led_config);
}

/**
 * @brief       ��ʼ��LED��GPIO
 * @param       ��
 * @retval      ��
 */
void LED_Init(void)
{
  /* ��ʼ��GPIO���á�ģʽ */
  LED_IOMUXC_MUX_Config();
  LED_GPIO_Mode_Config();
}








