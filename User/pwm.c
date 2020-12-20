#include "PWM.h"
#include "all.h"

void PWM_GPIO_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructu; 
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4|RCC_APB1Periph_TIM3, ENABLE); //打开TIM4时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //打开GPIOB时钟
	
	/*第二部 配置外设相关的结构体*/
	GPIO_InitStructu.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructu.GPIO_Mode=GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructu.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructu);
}

void PWM_TIM3_Mode_Config(void)
{
		TIM_TimeBaseInitTypeDef  TIM_InitStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;
  // 开启定时器时钟,即内部时钟CK_INT=72M
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

/*--------------------时基结构体初始化-------------------------*/
	// 配置周期，这里配置为100K
	

	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_InitStructure.TIM_Period=999;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_InitStructure.TIM_Prescaler= 71;	
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_InitStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_InitStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_InitStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(TIM3, &TIM_InitStructure);

	/*--------------------输出比较结构体初始化-------------------*/	
	// 占空比配置


	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// 输出比较通道 1
	TIM_OCInitStructure.TIM_Pulse = pid.pwm;
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	// 输出比较通道 2
	TIM_OCInitStructure.TIM_Pulse = pid.pwm;
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	// 使能计数器
	TIM_Cmd(TIM3, ENABLE);
}


void PWM_TIM4_Mode_Config(void)
{
		TIM_TimeBaseInitTypeDef  TIM_InitStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;
  // 开启定时器时钟,即内部时钟CK_INT=72M
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);

/*--------------------时基结构体初始化-------------------------*/
	// 配置周期，这里配置为100K
	
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_InitStructure.TIM_Period=999;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_InitStructure.TIM_Prescaler= 71;	
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_InitStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_InitStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_InitStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(TIM4, &TIM_InitStructure);

	/*--------------------输出比较结构体初始化-------------------*/	
	// 占空比配置

	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// 输出比较通道 1
	TIM_OCInitStructure.TIM_Pulse = pid.pwm;
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	// 输出比较通道 2
	TIM_OCInitStructure.TIM_Pulse = pid.pwm;
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	// 使能计数器
	TIM_Cmd(TIM4, ENABLE);
}


void PWM_TIM_CH1(uint16_t CCR1_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// 输出比较通道 1
	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	// 使能计数器
	TIM_Cmd(TIM4, ENABLE);
}


void PWM_TIM_CH2(uint16_t CCR2_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// 输出比较通道 2
	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	// 使能计数器
	TIM_Cmd(TIM4, ENABLE);
}


//////void PWM_TIM_CH3(uint16_t CCR3_Val)
//////{
//////	TIM_OCInitTypeDef  TIM_OCInitStructure;
//////	// 配置为PWM模式1
//////	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//////	// 输出使能
//////	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//////	// 输出通道电平极性配置	
//////	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//////	
//////	// 输出比较通道 3
//////	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;
//////	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
//////	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
//////	
//////	// 使能计数器
//////	TIM_Cmd(TIM3, ENABLE);
//////}

void PWM_TIM_CH3(uint16_t CCR3_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// 输出比较通道 4
	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	// 使能计数器
	TIM_Cmd(TIM3, ENABLE);
}

void PWM_TIM_CH4(uint16_t CCR4_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// 输出比较通道 4
	TIM_OCInitStructure.TIM_Pulse = CCR4_Val;
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	// 使能计数器
	TIM_Cmd(TIM3, ENABLE);
}


void TIM8_init(void)   //步进电机控制
{
	GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE); 
	  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure); 
	//初始化TIM
	TIM_TimeBaseStructure.TIM_Period = 100;//3.846KHz - 1Hz
	TIM_TimeBaseStructure.TIM_Prescaler = 71;//1000KHz计数频率  71
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);

	 //通道3
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 50;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM8, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM8,ENABLE);
	TIM_Cmd(TIM8, ENABLE);	
	TIM_CtrlPWMOutputs(TIM8, ENABLE);
}

