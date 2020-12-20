#ifndef __SYSTICK_H
#define __SYSTICK_H


#include "stm32f10x.h"
#include "core_cm3.h"


#define            BASIC_TIM6                   TIM6
#define            BASIC_TIM6_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            BASIC_TIM6_CLK               RCC_APB1Periph_TIM6
#define            BASIC_TIM6_Period            500-1 //²»ÊÇ10000us
#define            BASIC_TIM6_Prescaler         71
#define            BASIC_TIM6_IRQ               TIM6_IRQn
#define            BASIC_TIM6_IRQHandler        TIM6_IRQHandler

void BASIC_TIM6_Init(void);
void BASIC_TIM6_Stop(void);
void BASIC_TIM6_Start(void);


#endif



