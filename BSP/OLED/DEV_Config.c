/**
 ***************************************************
 * @file        DEV_Config.c
 * @brief       OLED硬件层
 ***************************************************
 */

#include "DEV_Config.h"
#include "fsl_debug_console.h"

/**
 * @brief       LPI2C发送字节函数
 * @param       value: 数据
 * @param       Cmd: 0x00或0x40
 * @retval      无
 */
int I2C_Write_Byte(uint8_t value, uint8_t Cmd)
{
  status_t reVal = kStatus_Fail;
  size_t txCount = 0xFFU;
  
    /*---------------------------------------------------*/
    /* 发送起始信号和OLED设备地址 */
  if (kStatus_Success == LPI2C_MasterStart(OLED_I2C_MASTER, OLED_ADDR_7BIT, kLPI2C_Write))
  {
    LPI2C_MasterGetFifoCounts(OLED_I2C_MASTER, NULL, &txCount);
    while(txCount)
    {
      LPI2C_MasterGetFifoCounts(OLED_I2C_MASTER, NULL, &txCount);
    }
    
    if (LPI2C_MasterGetStatusFlags(OLED_I2C_MASTER) & kLPI2C_MasterNackDetectFlag)
    {
      return kStatus_LPI2C_Nak;
    }
    
    /*---------------------------------------------------*/
    /* 发送寄存器地址 */
    
    reVal = LPI2C_MasterSend(OLED_I2C_MASTER, &Cmd, 1);
    if (reVal != kStatus_Success)
    {
      if (reVal == kStatus_LPI2C_Nak)
      {
        LPI2C_MasterStop(OLED_I2C_MASTER);
      }
      return -1;
    }
    
    /*---------------------------------------------------*/
    /* 发送数据 */
    
    reVal = LPI2C_MasterSend(OLED_I2C_MASTER, &value, 1);
    if (reVal != kStatus_Success)
    {
      if (reVal == kStatus_LPI2C_Nak)
      {
        LPI2C_MasterStop(OLED_I2C_MASTER);
      }
      return -1;
    }
    
    /*---------------------------------------------------*/
    /* 发送停止信号 */
    
    reVal = LPI2C_MasterStop(OLED_I2C_MASTER);
    if (reVal != kStatus_Success)
    {
      return -1;
    }
    
    /*---------------------------------------------------*/
  }
}

/**
 * @brief       毫秒延时函数
 * @param       xms: 延时毫秒时间
 * @retval      无
 */
void Driver_Delay_ms(uint32_t xms)
{
  SDK_DelayAtLeastUs(xms*1000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}

/**
 * @brief       微秒延时函数
 * @param       xus: 延时微秒时间
 * @retval      无
 */
void Driver_Delay_us(uint32_t xus)
{
  SDK_DelayAtLeastUs(xus, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}




