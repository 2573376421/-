#ifndef __bujin_H
#define	__bujin_H

#include "stm32f10x.h"


//步进电机正反转
#define CW_GPIO_CLK   RCC_APB2Periph_GPIOD
#define CW_GPIO_PORT  GPIOD
#define CW_GPIO_PIN   GPIO_Pin_0

#define BJDJ_UP         {GPIO_ResetBits(CW_GPIO_PORT, CW_GPIO_PIN); }   
#define BJDJ_DOWN       {GPIO_SetBits(CW_GPIO_PORT, CW_GPIO_PIN); }     



void DBJ_Init(void);


#endif
