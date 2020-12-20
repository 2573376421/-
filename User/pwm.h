#ifndef _PWM_H
#define _PWM_H

#include "stm32f10x.h"


void PWM_TIM3_Mode_Config(void);
void PWM_TIM4_Mode_Config(void);
void PWM_TIM_CH1(uint16_t CCR1_Val);
void PWM_TIM_CH2(uint16_t CCR2_Val);
void PWM_TIM_CH3(uint16_t CCR3_Val);
void PWM_TIM_CH4(uint16_t CCR4_Val);
void PWM_GPIO_config(void);

void TIM8_init(void);

#define  BJDJ_Start	  {TIM_SetCompare3(TIM8,50); }  //¶¯
#define	 BJDJ_Stop    {TIM_SetCompare3(TIM8,0);	  } //Í£


#endif



