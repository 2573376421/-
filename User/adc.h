#ifndef __ADC_H
#define	__ADC_H


#include "stm32f10x.h"

// ˫ģʽʱ��ADC1��ADC2ת�������ݶ������ADC1�����ݼĴ�����
// ADC1���ڵ�ʮ��λ��ADC2���ڸ�ʮ��λ
// ˫ADCģʽ�ĵ�һ��ADC��������ADC1
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

// ˫ADCģʽ�ĵڶ���ADC��������ADC2
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

// ADC1 ��Ӧ DMA1ͨ��1��ADC3��ӦDMA2ͨ��5��ADC2û��DMA����
#define    ADC_DMA_CHANNEL               DMA1_Channel1
#define    ADC_DMA_CLK                   RCC_AHBPeriph_DMA1

void ADCx_Init(void);

#endif /* __BSP_ADC_H */


