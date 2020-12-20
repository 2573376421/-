#ifndef __ADC_H
#define	__ADC_H


#include "stm32f10x.h"

// 双模式时，ADC1和ADC2转换的数据都存放在ADC1的数据寄存器，
// ADC1的在低十六位，ADC2的在高十六位
// 双ADC模式的第一个ADC，必须是ADC1
#define    ADCx_1                           ADC1
#define    ADCx_1_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADCx_1_CLK                       RCC_APB2Periph_ADC1

#define    ADCx_1_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    ADCx_1_GPIO_CLK                  RCC_APB2Periph_GPIOA  
#define    ADCx_1_PORT                      GPIOA
#define    ADCx_1_PIN1                      GPIO_Pin_0
#define    ADCx_1_CHANNEL1                  ADC_Channel_0
#define    ADCx_1_PIN2                      GPIO_Pin_1
#define    ADCx_1_CHANNEL2                  ADC_Channel_1
#define    ADCx_1_PIN3                      GPIO_Pin_2
#define    ADCx_1_CHANNEL3                  ADC_Channel_2
#define    ADCx_1_PIN4                      GPIO_Pin_3
#define    ADCx_1_CHANNEL4                  ADC_Channel_3

// 双ADC模式的第二个ADC，必须是ADC2
#define    ADCx_2                           ADC2
#define    ADCx_2_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADCx_2_CLK                       RCC_APB2Periph_ADC2

#define    ADCx_2_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    ADCx_2_GPIO_CLK                  RCC_APB2Periph_GPIOA 
#define    ADCx_2_PORT                      GPIOA
#define    ADCx_2_PIN5                      GPIO_Pin_4
#define    ADCx_2_CHANNEL5                  ADC_Channel_4
#define    ADCx_2_PIN6                      GPIO_Pin_5
#define    ADCx_2_CHANNEL6                  ADC_Channel_5
#define    ADCx_2_PIN7                      GPIO_Pin_6
#define    ADCx_2_CHANNEL7                  ADC_Channel_6
#define    ADCx_2_PIN8                      GPIO_Pin_7
#define    ADCx_2_CHANNEL8                  ADC_Channel_7


#define    NOFCHANEL                        4

// ADC1 对应 DMA1通道1，ADC3对应DMA2通道5，ADC2没有DMA功能
#define    ADC_DMA_CHANNEL               DMA1_Channel1
#define    ADC_DMA_CLK                   RCC_AHBPeriph_DMA1

void ADCx_Init(void);

#endif /* __BSP_ADC_H */


