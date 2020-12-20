#include "bujin.h"
#include "all.h"


void DBJ_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStruct;
	/*第一步 开外设相关的时钟 */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	
	/*第二部 配置外设相关的结构体*/
	GPIO_InitStruct.GPIO_Pin=CW_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(CW_GPIO_PORT, &GPIO_InitStruct);
}









