#include "bujin.h"
#include "all.h"


void DBJ_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStruct;
	/*��һ�� ��������ص�ʱ�� */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	
	/*�ڶ��� ����������صĽṹ��*/
	GPIO_InitStruct.GPIO_Pin=CW_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(CW_GPIO_PORT, &GPIO_InitStruct);
}









