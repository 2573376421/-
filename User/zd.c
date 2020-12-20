#include "zd.h"


static void TIM6_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    // 设置中断组为0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);		
	// 设置中断来源
    NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM6_IRQ ;	
	// 设置主优先级为 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	 
	// 设置抢占优先级为3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void TIM6_Mode_Config(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		
	// 开启定时器时钟,即内部时钟CK_INT=72M
    BASIC_TIM6_APBxClock_FUN(BASIC_TIM6_CLK, ENABLE);
	
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
    TIM_TimeBaseStructure.TIM_Period = BASIC_TIM6_Period;	

	// 时钟预分频数为
    TIM_TimeBaseStructure.TIM_Prescaler= BASIC_TIM6_Prescaler;
	
	// 时钟分频因子 ，基本定时器没有，不用管
    //TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	
	// 计数器计数模式，基本定时器只能向上计数，没有计数模式的设置
    //TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
		
	// 重复计数器的值，基本定时器没有，不用管
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
	// 初始化定时器
    TIM_TimeBaseInit(BASIC_TIM6, &TIM_TimeBaseStructure);
		
	// 清除计数器中断标志位
    TIM_ClearFlag(BASIC_TIM6, TIM_FLAG_Update);
	
	// 开启计数器中断
    TIM_ITConfig(BASIC_TIM6,TIM_IT_Update,ENABLE);
		
	// 使能计数器
    TIM_Cmd(BASIC_TIM6, DISABLE);	
}

void BASIC_TIM6_Init(void)
{
	TIM6_NVIC_Config();
	TIM6_Mode_Config();
}
void BASIC_TIM6_Start(void)
{
	TIM_Cmd(BASIC_TIM6, ENABLE);
}
void BASIC_TIM6_Stop(void)
{
	TIM_Cmd(BASIC_TIM6, DISABLE);
}


