/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "bsp_led.h"
#include "OLED_Driver.h"
#include "OLED_GUI.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    /* Just enable the trace clock, leave coresight initialization to IDE debugger */
    SystemCoreClockUpdate();
    CLOCK_EnableClock(kCLOCK_Trace);
    
    /* User Init */
    LED_Init();
    OLED_I2C_Init();
    
    /*----------------------------------------------*/
    /* OLED */
    
    OLED_Init(SCAN_DIR_DFT);    /* D2U_L2R */
    
    GUI_Show();
    
    OLED_Clear(OLED_BACKGROUND);
    OLED_Display();
    
    /* Show Pic */
    GUI_Disbitmap(0  , 2, Signal816  , 16, 8);
    GUI_Disbitmap(24 , 2, Bluetooth88, 8 , 8);
    GUI_Disbitmap(40 , 2, Msg816     , 16, 8);
    GUI_Disbitmap(64 , 2, GPRS88     , 8 , 8);
    GUI_Disbitmap(90 , 2, Alarm88    , 8 , 8);
    GUI_Disbitmap(112, 2, Bat816     , 16, 8);
    
    /* Show 16 Gray Map */
    GUI_DisGrayMap(0, 73, gImage_flower);
    
    GUI_DisString_EN(0 , 52, "MUSIC", &Font12, FONT_BACKGROUND, WHITE);
    GUI_DisString_EN(48, 52, "MENU" , &Font12, FONT_BACKGROUND, WHITE);
    GUI_DisString_EN(90, 52, "PHONE", &Font12, FONT_BACKGROUND, WHITE);
    
    OLED_Display();

    /*----------------------------------------------*/

    while (1)
    {
      /* Show time */
      uint8_t sec = 0;
      DEV_TIME sDev_time;
      sDev_time.Hour = 12;
      sDev_time.Min = 34;
      sDev_time.Sec = 56;
      for (;;) {
              sec++;
              sDev_time.Sec = sec;
              if (sec == 60) {
                      sDev_time.Min = sDev_time.Min + 1;
                      sec = 0;
                      if (sDev_time.Min == 60) {
                              sDev_time.Hour =  sDev_time.Hour + 1;
                              sDev_time.Min = 0;
                              if (sDev_time.Hour == 24) {
                                sDev_time.Hour = 0;
                                sDev_time.Min = 0;
                                sDev_time.Sec = 0;
                              }
                      }
              }
              GUI_Showtime(0, 22, 127, 47, &sDev_time, WHITE);
              Driver_Delay_ms(1000);//Analog clock 1s 
      }
    }
}
