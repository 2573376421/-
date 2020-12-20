#include "pid.h"
#include "all.h"

PID_InitTypeDef pid;

extern  uint16_t norm_AD0,norm_AD1,norm_AD2,norm_AD3, norm_AD4,norm_AD5,norm_AD6,norm_AD7;
extern  uint16_t normAD_MAX[8];
extern  uint8_t  zhixing_flag;
u8 p=0,x=0;

void PID_Config(void)
{
	  pid.Kp=1.3;
		pid.Ti=0;
		pid.Td=0;
  	pid.pwm=280;//速度
		pid.Out0=0;
		pid.Sv=0;
}

void PID_Caculator(void)
{
   float Ielek,Ek;
	
	 if((norm_AD3==normAD_MAX[4]&&norm_AD4==normAD_MAX[5])||(norm_AD3==normAD_MAX[5]&&norm_AD4==normAD_MAX[4]))
	 {
		 zhixing_flag=0;
		 pid.Pv =-(norm_AD3-norm_AD4);
	 }
	 if(normAD_MAX[5]<370)
	 {

	 if((norm_AD2==normAD_MAX[4]&&norm_AD3==normAD_MAX[5])||(norm_AD2==normAD_MAX[5]))
	 {
		 zhixing_flag=0;
		 pid.Pv =norm_AD3-norm_AD2+200;
	 }
	 if((norm_AD5==normAD_MAX[5])||(norm_AD4==normAD_MAX[5]&&norm_AD5==normAD_MAX[4]))
	 {
		 zhixing_flag=0;
		 pid.Pv =norm_AD5-norm_AD4-200;
	 }
	}
	 if(norm_AD0>400&&norm_AD7<330&&p==0)               //停车
	 {
		 delay_ms(10);
		 if(norm_AD0>400&&norm_AD7<330)               //停车
		{
		 zhixing_flag=2;
		 x++;
		 p=1;
	 }
	 }
	 if(norm_AD1<350&&norm_AD6<350)
	 {
		 if(x==3)
		 {			 
			 zhixing_flag=4;
		 }
		 zhixing_flag=1;
	 }
	 if(p==2)
	 {
		 zhixing_flag=1;
	 }
	 if(p==2&&norm_AD0>400&&norm_AD7>400)
	 {
	   p=0;
	 }
//	 
	 
	 
	 if((GPIO_ReadInputDataBit(TRIG_GPIO_PORT,TRIG_GPIO_PIN)==0||GPIO_ReadInputDataBit(GD_GPIO_PORT,GD_GPIO_PIN)==0))
	 {
	   zhixing_flag=5;
	 }
	 
	  Ek=pid.Pv-0;	
	  pid.Ek=Ek;
	  Ielek=pid.Ek-pid.Ek_1;
	  pid.OUT=pid.Kp*pid.Pv+pid.Td*Ielek;
	  pid.Ek_1=Ek;
	 
}




	 

