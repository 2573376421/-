#ifndef __madc_H
#define	__madc_H


#include "stm32f10x.h"

#define MAX(x,y)  ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)<(y)?(x):(y))

uint16_t average_ad_data(uint8_t id);
uint16_t RecursiveAverageFiltering(uint8_t num ,uint16_t dat);
void get_adc(void);
void DISPLAY_AD_GET(void);
	
#endif




