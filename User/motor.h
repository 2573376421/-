#ifndef __MOTOR_H
#define	__MOTOR_H

#include "stm32f10x.h"

//前右轮
#define INT1_GPIO_CLK   RCC_APB2Periph_GPIOC
#define INT1_GPIO_PORT  GPIOC
#define INT1_GPIO_PIN   GPIO_Pin_0

#define INT2_GPIO_CLK   RCC_APB2Periph_GPIOC
#define INT2_GPIO_PORT  GPIOC
#define INT2_GPIO_PIN   GPIO_Pin_1

//前左轮
#define INT3_GPIO_CLK   RCC_APB2Periph_GPIOC
#define INT3_GPIO_PORT  GPIOC
#define INT3_GPIO_PIN   GPIO_Pin_2

#define INT4_GPIO_CLK   RCC_APB2Periph_GPIOC
#define INT4_GPIO_PORT  GPIOC
#define INT4_GPIO_PIN   GPIO_Pin_3

//前右轮
#define INT5_GPIO_CLK   RCC_APB2Periph_GPIOC
#define INT5_GPIO_PORT  GPIOC
#define INT5_GPIO_PIN   GPIO_Pin_4

#define INT6_GPIO_CLK   RCC_APB2Periph_GPIOC
#define INT6_GPIO_PORT  GPIOC
#define INT6_GPIO_PIN   GPIO_Pin_5

//前左轮
#define INT7_GPIO_CLK   RCC_APB2Periph_GPIOC
#define INT7_GPIO_PORT  GPIOC
#define INT7_GPIO_PIN   GPIO_Pin_6

#define INT8_GPIO_CLK   RCC_APB2Periph_GPIOC
#define INT8_GPIO_PORT  GPIOC
#define INT8_GPIO_PIN   GPIO_Pin_7


#define  zh_go       { GPIO_ResetBits(INT1_GPIO_PORT,INT1_GPIO_PIN); GPIO_SetBits(INT2_GPIO_PORT, INT2_GPIO_PIN); }
#define  zh_stop     { GPIO_ResetBits(INT1_GPIO_PORT,INT1_GPIO_PIN); GPIO_ResetBits(INT2_GPIO_PORT, INT2_GPIO_PIN); }
#define  zh_back     { GPIO_SetBits(INT1_GPIO_PORT,INT1_GPIO_PIN); GPIO_ResetBits(INT2_GPIO_PORT, INT2_GPIO_PIN); }

#define  yh_go       { GPIO_ResetBits(INT4_GPIO_PORT,INT4_GPIO_PIN); GPIO_SetBits(INT3_GPIO_PORT, INT3_GPIO_PIN); }
#define  yh_stop     { GPIO_ResetBits(INT4_GPIO_PORT,INT4_GPIO_PIN); GPIO_ResetBits(INT3_GPIO_PORT, INT3_GPIO_PIN); }
#define  yh_back     { GPIO_SetBits(INT4_GPIO_PORT,INT4_GPIO_PIN); GPIO_ResetBits(INT3_GPIO_PORT, INT3_GPIO_PIN); }

#define  zq_go       { GPIO_SetBits(INT5_GPIO_PORT,INT5_GPIO_PIN); GPIO_ResetBits(INT6_GPIO_PORT, INT6_GPIO_PIN);}
#define  zq_stop     { GPIO_ResetBits(INT5_GPIO_PORT,INT5_GPIO_PIN); GPIO_ResetBits(INT6_GPIO_PORT, INT6_GPIO_PIN); }
#define  zq_back     { GPIO_SetBits(INT6_GPIO_PORT,INT6_GPIO_PIN); GPIO_ResetBits(INT5_GPIO_PORT, INT5_GPIO_PIN); }

#define  yq_go       { GPIO_ResetBits(INT8_GPIO_PORT,INT8_GPIO_PIN); GPIO_SetBits(INT7_GPIO_PORT, INT7_GPIO_PIN);}
#define  yq_stop     { GPIO_ResetBits(INT8_GPIO_PORT,INT8_GPIO_PIN); GPIO_ResetBits(INT7_GPIO_PORT, INT7_GPIO_PIN); }
#define  yq_back     { GPIO_ResetBits(INT8_GPIO_PORT,INT8_GPIO_PIN); GPIO_ResetBits(INT7_GPIO_PORT, INT7_GPIO_PIN); }


//红外引脚
#define TRIG_GPIO_CLK   RCC_APB2Periph_GPIOE
#define TRIG_GPIO_PORT  GPIOE
#define TRIG_GPIO_PIN   GPIO_Pin_10

#define GD_GPIO_CLK   RCC_APB2Periph_GPIOE
#define GD_GPIO_PORT  GPIOE
#define GD_GPIO_PIN   GPIO_Pin_11


void MOTOR_GPIO_Init(void);
void go_car(void);
void stop_car(void);
void back_car(void);
void CONTROL(void);
	
#endif




