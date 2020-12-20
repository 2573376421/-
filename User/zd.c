#include "zd.h"


static void TIM6_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    // �����ж���Ϊ0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);		
	// �����ж���Դ
    NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM6_IRQ ;	
	// ���������ȼ�Ϊ 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	 
	// ������ռ���ȼ�Ϊ3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void TIM6_Mode_Config(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		
	// ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
    BASIC_TIM6_APBxClock_FUN(BASIC_TIM6_CLK, ENABLE);
	
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
    TIM_TimeBaseStructure.TIM_Period = BASIC_TIM6_Period;	

	// ʱ��Ԥ��Ƶ��Ϊ
    TIM_TimeBaseStructure.TIM_Prescaler= BASIC_TIM6_Prescaler;
	
	// ʱ�ӷ�Ƶ���� ��������ʱ��û�У����ù�
    //TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	
	// ����������ģʽ��������ʱ��ֻ�����ϼ�����û�м���ģʽ������
    //TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
		
	// �ظ���������ֵ��������ʱ��û�У����ù�
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
	// ��ʼ����ʱ��
    TIM_TimeBaseInit(BASIC_TIM6, &TIM_TimeBaseStructure);
		
	// ����������жϱ�־λ
    TIM_ClearFlag(BASIC_TIM6, TIM_FLAG_Update);
	
	// �����������ж�
    TIM_ITConfig(BASIC_TIM6,TIM_IT_Update,ENABLE);
		
	// ʹ�ܼ�����
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


