#include "PWM.h"
#include "all.h"

void PWM_GPIO_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructu; 
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4|RCC_APB1Periph_TIM3, ENABLE); //��TIM4ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //��GPIOBʱ��
	
	/*�ڶ��� ����������صĽṹ��*/
	GPIO_InitStructu.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructu.GPIO_Mode=GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructu.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructu);
}

void PWM_TIM3_Mode_Config(void)
{
		TIM_TimeBaseInitTypeDef  TIM_InitStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;
  // ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

/*--------------------ʱ���ṹ���ʼ��-------------------------*/
	// �������ڣ���������Ϊ100K
	

	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_InitStructure.TIM_Period=999;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_InitStructure.TIM_Prescaler= 71;	
	// ʱ�ӷ�Ƶ���� ����������ʱ��ʱ��Ҫ�õ�
	TIM_InitStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_InitStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// �ظ���������ֵ��û�õ����ù�
	TIM_InitStructure.TIM_RepetitionCounter=0;	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(TIM3, &TIM_InitStructure);

	/*--------------------����ȽϽṹ���ʼ��-------------------*/	
	// ռ�ձ�����


	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// ����Ƚ�ͨ�� 1
	TIM_OCInitStructure.TIM_Pulse = pid.pwm;
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 2
	TIM_OCInitStructure.TIM_Pulse = pid.pwm;
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	// ʹ�ܼ�����
	TIM_Cmd(TIM3, ENABLE);
}


void PWM_TIM4_Mode_Config(void)
{
		TIM_TimeBaseInitTypeDef  TIM_InitStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;
  // ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);

/*--------------------ʱ���ṹ���ʼ��-------------------------*/
	// �������ڣ���������Ϊ100K
	
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_InitStructure.TIM_Period=999;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_InitStructure.TIM_Prescaler= 71;	
	// ʱ�ӷ�Ƶ���� ����������ʱ��ʱ��Ҫ�õ�
	TIM_InitStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_InitStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// �ظ���������ֵ��û�õ����ù�
	TIM_InitStructure.TIM_RepetitionCounter=0;	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(TIM4, &TIM_InitStructure);

	/*--------------------����ȽϽṹ���ʼ��-------------------*/	
	// ռ�ձ�����

	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// ����Ƚ�ͨ�� 1
	TIM_OCInitStructure.TIM_Pulse = pid.pwm;
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 2
	TIM_OCInitStructure.TIM_Pulse = pid.pwm;
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	// ʹ�ܼ�����
	TIM_Cmd(TIM4, ENABLE);
}


void PWM_TIM_CH1(uint16_t CCR1_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// ����Ƚ�ͨ�� 1
	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	// ʹ�ܼ�����
	TIM_Cmd(TIM4, ENABLE);
}


void PWM_TIM_CH2(uint16_t CCR2_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// ����Ƚ�ͨ�� 2
	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	// ʹ�ܼ�����
	TIM_Cmd(TIM4, ENABLE);
}


//////void PWM_TIM_CH3(uint16_t CCR3_Val)
//////{
//////	TIM_OCInitTypeDef  TIM_OCInitStructure;
//////	// ����ΪPWMģʽ1
//////	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//////	// ���ʹ��
//////	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//////	// ���ͨ����ƽ��������	
//////	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//////	
//////	// ����Ƚ�ͨ�� 3
//////	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;
//////	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
//////	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
//////	
//////	// ʹ�ܼ�����
//////	TIM_Cmd(TIM3, ENABLE);
//////}

void PWM_TIM_CH3(uint16_t CCR3_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// ����Ƚ�ͨ�� 4
	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	// ʹ�ܼ�����
	TIM_Cmd(TIM3, ENABLE);
}

void PWM_TIM_CH4(uint16_t CCR4_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// ����Ƚ�ͨ�� 4
	TIM_OCInitStructure.TIM_Pulse = CCR4_Val;
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	// ʹ�ܼ�����
	TIM_Cmd(TIM3, ENABLE);
}


void TIM8_init(void)   //�����������
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
	//��ʼ��TIM
	TIM_TimeBaseStructure.TIM_Period = 100;//3.846KHz - 1Hz
	TIM_TimeBaseStructure.TIM_Prescaler = 71;//1000KHz����Ƶ��  71
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);

	 //ͨ��3
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

