#include "madc.h"
#include "all.h"

extern  uint8_t  zhixing_flag;
extern  uint8_t  k;
extern  uint8_t  x;

extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];
float ADC_ConvertedValueLocal[NOFCHANEL*2]={0,0};
uint16_t norm_AD1,norm_AD2,norm_AD3,norm_AD4,norm_AD5,norm_AD6,norm_AD0,norm_AD7;
uint16_t RawData_AD0,RawData_AD1,RawData_AD2,RawData_AD3,RawData_AD4,RawData_AD5,RawData_AD6,RawData_AD7;
uint16_t Recursive_AD0,Recursive_AD1,Recursive_AD2,Recursive_AD3,Recursive_AD4,Recursive_AD5,Recursive_AD6,Recursive_AD7;
uint16_t A1,A2,A3,A4,A5,A6,A0,A7;
uint16_t normAD_MAX[8],normAD;
uint16_t value_buf[8][12];
uint16_t AD1_MAX,AD2_MAX,AD3_MAX,AD4_MAX,AD5_MAX,AD6_MAX,AD0_MAX,AD7_MAX;
uint16_t AD1_MIN,AD2_MIN,AD3_MIN,AD4_MIN,AD5_MIN,AD6_MIN,AD0_MIN,AD7_MIN;
uint16_t ad_Maxcache1,ad_Maxcache2,ad_Maxcache3,ad_Maxcache4,ad_Maxcache5,ad_Maxcache6,ad_Maxcache0,ad_Maxcache7;
uint16_t ad_Mincache1=50000,ad_Mincache2=50000,ad_Mincache3=50000,ad_Mincache4=50000,ad_Mincache5=50000,ad_Mincache6=50000,ad_Mincache0=50000,ad_Mincache7=50000;
float AD1_K,AD2_K,AD3_K,AD4_K,AD5_K,AD6_K,AD0_K,AD7_K,ADC_AV;

/******************
★功能：算术平均滤波
说明：连续取N个采样值进行算术平均运算
★输入：AD端口
★输出：算术平均滤波后的值
******************/

uint16_t average_ad_data(uint8_t id)
{
	uint32_t sum1=0;
	uint8_t  i;
	for(i=0;i<12;i++)
	{
		sum1+=ADC_ConvertedValueLocal[id];
	}
	sum1= sum1/12.0;
	return (uint16_t)sum1;
}	


uint16_t RecursiveAverageFiltering(uint8_t num ,uint16_t dat)
{
	uint8_t i;
	uint16_t value;
	uint32_t sum=0;
	for(i=11;i>=1;i--)
	{
		value_buf[num][i]=value_buf[num][i-1];   //所有数据左移，低位扔掉
	}
	value_buf[num][0]=dat;
	for(i=0;i<12;i++)
	{
		sum += value_buf[num][i];
	}
	value = (uint16_t)sum/12.0;
	return value;
}



void get_adc(void)
{  
	  uint16_t temp0=0 ,temp1=0;
	
  	temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;
		temp1 = (ADC_ConvertedValue[0]&0XFFFF);		
		ADC_ConvertedValueLocal[4] =temp0;
		ADC_ConvertedValueLocal[0] =temp1;		
    temp0 = (ADC_ConvertedValue[1]&0XFFFF0000) >> 16;
		temp1 = (ADC_ConvertedValue[1]&0XFFFF);		
		ADC_ConvertedValueLocal[5] =temp0;
		ADC_ConvertedValueLocal[1] =temp1;		
	  temp0 = (ADC_ConvertedValue[2]&0XFFFF0000) >> 16;
		temp1 = (ADC_ConvertedValue[2]&0XFFFF);		
		ADC_ConvertedValueLocal[6] =temp0;
		ADC_ConvertedValueLocal[2] =temp1;		
	  temp0 = (ADC_ConvertedValue[3]&0XFFFF0000) >> 16;
		temp1 = (ADC_ConvertedValue[3]&0XFFFF);		
		ADC_ConvertedValueLocal[7] =temp0;
		ADC_ConvertedValueLocal[3] =temp1;		

	RawData_AD0=average_ad_data(0);
	RawData_AD1=average_ad_data(1);
	RawData_AD2=average_ad_data(2);
	RawData_AD3=average_ad_data(3);
	RawData_AD4=average_ad_data(4);
	RawData_AD5=average_ad_data(5);
	RawData_AD6=average_ad_data(6);
	RawData_AD7=average_ad_data(7);
	//AD数据平滑滤波
	Recursive_AD0=RecursiveAverageFiltering(0,RawData_AD0);
	Recursive_AD1=RecursiveAverageFiltering(1,RawData_AD1);
	Recursive_AD2=RecursiveAverageFiltering(2,RawData_AD2);
	Recursive_AD3=RecursiveAverageFiltering(3,RawData_AD3);
	Recursive_AD4=RecursiveAverageFiltering(4,RawData_AD4);
	Recursive_AD5=RecursiveAverageFiltering(5,RawData_AD5);
	Recursive_AD6=RecursiveAverageFiltering(6,RawData_AD6);
	Recursive_AD7=RecursiveAverageFiltering(7,RawData_AD7);

	AD0_MAX=MAX(Recursive_AD0,AD0_MAX);
	AD1_MAX=MAX(Recursive_AD1,AD1_MAX);
	AD2_MAX=MAX(Recursive_AD2,AD2_MAX);
	AD3_MAX=MAX(Recursive_AD3,AD3_MAX);
	AD4_MAX=MAX(Recursive_AD4,AD4_MAX);
	AD5_MAX=MAX(Recursive_AD5,AD5_MAX);
	AD6_MAX=MAX(Recursive_AD6,AD6_MAX);
	AD7_MAX=MAX(Recursive_AD7,AD7_MAX);
  AD0_MIN=MIN(Recursive_AD0,AD0_MIN);
	AD1_MIN=MIN(Recursive_AD1,AD1_MIN);
	AD2_MIN=MIN(Recursive_AD2,AD2_MIN);
	AD3_MIN=MIN(Recursive_AD3,AD3_MIN);
	AD4_MIN=MIN(Recursive_AD4,AD4_MIN);
	AD5_MIN=MIN(Recursive_AD5,AD5_MIN);
	AD6_MIN=MIN(Recursive_AD6,AD6_MIN);
	AD7_MIN=MIN(Recursive_AD7,AD7_MIN);
	
//	ADC_AV=((AD1_MAX-AD1_MIN)+(AD2_MAX-AD2_MIN)+(AD3_MAX-AD3_MIN)+(AD4_MAX-AD4_MIN)+(AD5_MAX-AD5_MIN)+(AD6_MAX-AD6_MIN)+(AD7_MAX-AD7_MIN)+(AD0_MAX-AD0_MIN))/8;

//	AD0_K=ADC_AV/(AD0_MAX-AD0_MIN);
//	AD1_K=ADC_AV/(AD1_MAX-AD1_MIN);
//	AD2_K=ADC_AV/(AD2_MAX-AD2_MIN);
//	AD3_K=ADC_AV/(AD3_MAX-AD3_MIN);
//	AD4_K=ADC_AV/(AD4_MAX-AD4_MIN);
//	AD5_K=ADC_AV/(AD5_MAX-AD5_MIN);
//	AD6_K=ADC_AV/(AD6_MAX-AD6_MIN);
//	AD7_K=ADC_AV/(AD7_MAX-AD7_MIN);
////AD数据归一化
//	A0=((Recursive_AD0-AD0_MIN)*AD0_K)>0?(Recursive_AD0-AD0_MIN)*AD0_K:0;
//	A1=((Recursive_AD1-AD1_MIN)*AD1_K)>0?(Recursive_AD1-AD1_MIN)*AD1_K:0;
//	A2=((Recursive_AD2-AD2_MIN)*AD2_K)>0?(Recursive_AD2-AD2_MIN)*AD2_K:0;
//	A3=((Recursive_AD3-AD3_MIN)*AD3_K)>0?(Recursive_AD3-AD3_MIN)*AD3_K:0;
//	A4=((Recursive_AD4-AD4_MIN)*AD4_K)>0?(Recursive_AD4-AD4_MIN)*AD4_K:0;
//	A5=((Recursive_AD5-AD5_MIN)*AD5_K)>0?(Recursive_AD5-AD5_MIN)*AD5_K:0;
//	A6=((Recursive_AD6-AD6_MIN)*AD6_K)>0?(Recursive_AD6-AD6_MIN)*AD6_K:0;
//	A7=((Recursive_AD7-AD7_MIN)*AD7_K)>0?(Recursive_AD7-AD7_MIN)*AD7_K:0;
  
	norm_AD0=Recursive_AD0*500/ad_Maxcache0;
	norm_AD1=Recursive_AD1*500/ad_Maxcache1;
	norm_AD2=Recursive_AD2*500/ad_Maxcache2;
	norm_AD3=Recursive_AD3*500/ad_Maxcache3;
	norm_AD4=Recursive_AD4*500/ad_Maxcache4;
	norm_AD5=Recursive_AD5*500/ad_Maxcache5;
	norm_AD6=Recursive_AD6*500/ad_Maxcache6;
	norm_AD7=Recursive_AD7*500/ad_Maxcache7;
	

//AD归一化值排序,从大往小排
	normAD_MAX[2]=norm_AD2;
	normAD_MAX[3]=norm_AD4;
	normAD_MAX[4]=norm_AD3;
	normAD_MAX[5]=norm_AD5;

	for(uint8_t x=2;x<5;x++)
		for(uint8_t y=x+1;y<6;y++)
		{
			if(normAD_MAX[x]<normAD_MAX[y])
			{
				normAD=normAD_MAX[x];
				normAD_MAX[x]=normAD_MAX[y];
				normAD_MAX[y]=normAD;
			}
		}
}

void DISPLAY_AD_GET(void)
{
  LCD_P6x8Str(0,0,"AD0 :");
	LCD_P6x8Str(66,0,"AD1 :");
	LCD_P6x8Str(0,1,"AD2 :");
	LCD_P6x8Str(66,1,"AD3 :");
	LCD_P6x8Str(0,2,"AD4 :");
	LCD_P6x8Str(66,2,"AD5 :");
	LCD_P6x8Str(0,3,"AD6 :");
	LCD_P6x8Str(66,3,"AD7 :");
	if(pid.OUT>0)
	LCD_P6x8Str(0,4,"OUT+:");
	else
	LCD_P6x8Str(0,4,"OUT-:");		
	LCD_P6x8Str(66,4,"er :");
	LCD_P6x8Str(0,5,"pwm :");	
	LCD_P6x8Str(66,5,"flag:");	 		
  LCD_P6x8Str(0,6,"x : ");	 		

	
	LCD_P6x8integer(norm_AD0,5,0,30);
	LCD_P6x8integer(norm_AD1,5,0,96);
	LCD_P6x8integer(norm_AD2,5,1,30);
	LCD_P6x8integer(norm_AD3,5,1,96);
	LCD_P6x8integer(norm_AD4,5,2,30);
	LCD_P6x8integer(norm_AD5,5,2,96);
	LCD_P6x8integer(norm_AD6,5,3,30);
	LCD_P6x8integer(norm_AD7,5,3,96);	
	LCD_P6x8integer(pid.OUT,5,4,30);
	LCD_P6x8integer(pid.Sv,5,4,96);	
	LCD_P6x8integer(pid.Ti,5,5,30);
	LCD_P6x8integer(zhixing_flag,5,5,96);
	LCD_P6x8integer(x,5,6,30);
}





