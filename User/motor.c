#include "motor.h"
#include "all.h"

uint8_t  zhixing_flag=0;
extern  uint16_t norm_AD0,norm_AD1,norm_AD2,norm_AD3, norm_AD4,norm_AD5,norm_AD6,norm_AD7;



void MOTOR_GPIO_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStruct;
	/*第一步 开外设相关的时钟 */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
	RCC_APB2PeriphClockCmd(TRIG_GPIO_CLK|GD_GPIO_CLK, ENABLE);    //配置红外引脚的时钟
	
	/*第二部 配置外设相关的结构体*/
	GPIO_InitStruct.GPIO_Pin=INT1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(INT1_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=INT2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(INT2_GPIO_PORT, &GPIO_InitStruct); 
	
	GPIO_InitStruct.GPIO_Pin=INT3_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(INT3_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=INT4_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(INT4_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=INT5_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(INT5_GPIO_PORT, &GPIO_InitStruct); 
	
	GPIO_InitStruct.GPIO_Pin=INT6_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(INT6_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=INT7_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(INT7_GPIO_PORT, &GPIO_InitStruct); 
	
	GPIO_InitStruct.GPIO_Pin=INT8_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(INT8_GPIO_PORT, &GPIO_InitStruct);
}

void delay(u32 m)
{
  u32 j;
	for(;m>0;m--)
	 for(j=110;j>0;j--);
}

void go_car(void)
{
	 yq_go;
	 zq_go;
	 zh_go;
	 yh_go;		
	 PWM_TIM_CH1(200);
	 PWM_TIM_CH2(200);
	 PWM_TIM_CH3(200);
	 PWM_TIM_CH4(200);
}

void back_car(void)
{
   yq_back;
	 zq_back;
	 yh_back;
	 zh_back;		
		PWM_TIM_CH1(160);
		PWM_TIM_CH2(160);
		PWM_TIM_CH3(160);
		PWM_TIM_CH4(160);
}	

void stop_car(void)
{
    yq_stop;	
		zq_stop;	
		yh_stop;	
		zh_stop;	
}


void CONTROL(void)
{
	u8 m=0;
	long pwm_l;
	long pwm_r;
	PID_Caculator();
	if(zhixing_flag==0)
	{  
		
		pid.Ti=pid.pwm-pid.OUT;
		pid.Sv=pid.pwm+pid.OUT;
		if(pid.Ti<0)
		{
//			zq_back;
//			zh_back;
//		  yq_go;
//	    yh_go
//			pid.Ti=-pid.Ti+150;
			pid.Ti=0;
		}
		if(pid.Sv<0)
		{
//			yq_back;
//			yh_back;
//		  zq_go;
//	    zh_go;
//			pid.Sv=-pid.Sv+150;
			pid.Sv=0;
		}
		if(pid.Ti>500)
			pid.Ti=500;
		if(pid.Sv>500)
			pid.Sv=500;
    PWM_TIM_CH1(pid.Ti);    //左前
		
	  PWM_TIM_CH2(pid.Sv);   //右hou
		
		PWM_TIM_CH3(pid.Ti);    //左后

		PWM_TIM_CH4(pid.Sv);   //右后
	}
	if(zhixing_flag==1)
	{		
			go_car();
	}
	if(zhixing_flag==2)
	{		
			stop_car();
			
	  //
		if(x==1)
		{
			PCA_MG9XX(5,0,90,0,50);
		}
		if(x==3)
	{
		
  PCA_MG9XX(5,0,90,0,50);
	PCA_MG9XX(1,0,20,2,50);   //舵机2 
	BJDJ_Start;
	BJDJ_UP;
  delay_ms(50000);
	BJDJ_Stop;
	PCA_MG9XX(0,0,145,2,50); 	//舵机1  		
	PCA_MG9XX(2,0,50,2,50);
	PCA_MG9XX(15,0,172,2,50);
		//fjiaodu(155);
	BJDJ_Start;
	BJDJ_DOWN;
  delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	BJDJ_Stop;  	
  PCA_MG9XX(2,50,1,2,50);
 	BJDJ_Start;
	BJDJ_UP;
	delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	BJDJ_Stop;   
  PCA_MG9XX(1,20,19,2,50);       //舵机2
	PCA_MG9XX(15,172,40,2,50);
	//zjiaodu(160);
  PCA_MG9XX(0,145,1,2,50);       //舵机1
  delay_ms(10000);
	BJDJ_Start;
	BJDJ_DOWN;
  delay_ms(50000);
	BJDJ_Stop; 
	PCA_MG9XX(2,1,50,2,50);
	BJDJ_Start;
	BJDJ_UP;
  delay_ms(50000);
	BJDJ_Stop; 
	PCA_MG9XX(2,50,1,2,50);
	PCA_MG9XX(15,40,1,2,50);
	                                                //  中下    1
																									
																									
																									
	PCA_MG9XX(0,0,125,2,20); 	//舵机1	
	PCA_MG9XX(1,0,20,2,20);   	//舵机2
  PCA_MG9XX(2,1,45,2,20); 		//舵机3 
	PCA_MG9XX(15,1,160,2,20);    //////////
	//fjiaodu(190);
  BJDJ_Start;  
	BJDJ_DOWN;
	delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	BJDJ_Stop;
	PCA_MG9XX(2,45,1,2,20);
  delay_ms(10000);   	//舵机3  抓紧
  BJDJ_Start; 
	BJDJ_UP;
	delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	delay_ms(50000);
	BJDJ_Stop;
	PCA_MG9XX(15,160,60,2,20);    //////////
	//fjiaodu(70);
  PCA_MG9XX(1,20,19,2,20);       //舵机2
  PCA_MG9XX(0,125,1,2,50);       //舵机1
//	BJDJ_Start;
//	BJDJ_DOWN;
//  delay_ms(50000);
//	BJDJ_Stop;	
//	PCA_MG9XX(2,1,50,2,20);delay_ms(50000);	
//	BJDJ_Start;
//	BJDJ_UP;
//  delay_ms(50000);
//	delay_ms(50000);
//	BJDJ_Stop;
//	PCA_MG9XX(15,60,1,2,20);     //////////
//	//zjiaodu(190);
//	//zjiaodu(65);
//	PCA_MG9XX(2,50,1,2,20);	
	                                                   //右下角   3																									
																									
// BJDJ_Start;
//	BJDJ_DOWN;
//	delay_ms(50000);
//	delay_ms(10000);
//	BJDJ_Stop;
//	PCA_MG9XX(1,0,57,2,50);  	//舵机2
//  /////fjiaodu(160);
//	/////fjiaodu(160);
//  PCA_MG9XX(15,0,90,2,50);
//	PCA_MG9XX(2,0,50,2,50);    //舵机3 
//	PCA_MG9XX(0,0,135,2,50); 	//舵机1	
//	PCA_MG9XX(2,50,10,2,50);   	//舵机3  抓紧	
//	BJDJ_Start;
//	BJDJ_UP;
//  delay_ms(50000);
//	delay_ms(10000);
//	BJDJ_Stop;
//  PCA_MG9XX(0,135,1,2,50);       //舵机1
//	PCA_MG9XX(1,57,26,2,50);       //舵机2
//	/////fjiaodu(80);fjiaodu(80);
//  PCA_MG9XX(15,90,179,2,50);
		}
			delay_ms(5000);
			go_car();
			p=2;
	}
	
	if(zhixing_flag==5)
	{
		while(GPIO_ReadInputDataBit(TRIG_GPIO_PORT,TRIG_GPIO_PIN)==0||GPIO_ReadInputDataBit(GD_GPIO_PORT,GD_GPIO_PIN)==0)
		{ 
			 zh_back;
			 zq_back;
			 yh_go;
			 yq_go;
			 PWM_TIM_CH2(480);    //左前
			
			 PWM_TIM_CH1(480);   //右前
			
			 PWM_TIM_CH3(480);    //左后

			 PWM_TIM_CH4(480);   //右后
			 m=2;
			 delay_ms(180);
		}
		while((GPIO_ReadInputDataBit(TRIG_GPIO_PORT,TRIG_GPIO_PIN)==1&&GPIO_ReadInputDataBit(GD_GPIO_PORT,GD_GPIO_PIN)==1)&&m==2)
		{	zh_go;
			 zq_go;
			 yh_go;
			 yq_go;
			 PWM_TIM_CH2(200);    //左前
			
			 PWM_TIM_CH1(200);   //右前
			
			 PWM_TIM_CH3(200);    //左后

			 PWM_TIM_CH4(200);   //右后    
			 delay_ms(1500);
			
			 zh_go;
			 zq_go;
			 yh_back;
			 yq_back;
			 PWM_TIM_CH2(500);    //左前
			
			 PWM_TIM_CH1(500);   //右前
			
			 PWM_TIM_CH3(500);    //左后

			 PWM_TIM_CH4(500);   //右后
			 delay_ms(500);
			 
			 zh_go;
			 zq_go;
			 yh_go;
			 yq_go;
			 PWM_TIM_CH2(200);    //左前
			
			 PWM_TIM_CH1(200);   //右前
			
			 PWM_TIM_CH3(200);    //左后

			 PWM_TIM_CH4(200);   //右后    
			 delay_ms(1300);
			 
			 zh_go;
			 zq_go;
			 yh_go;
			 yq_go;
			 PWM_TIM_CH2(70);    //左前
			
			 PWM_TIM_CH1(300);   //右前
			
			 PWM_TIM_CH3(300);    //左后

			 PWM_TIM_CH4(70);   //右后  
			 delay_ms(150);
			 
			 zh_go;
			 zq_go;
			 yh_go;
			 yq_go;
			 PWM_TIM_CH2(120);    //左前
			
			 PWM_TIM_CH1(120);   //右前
			
			 PWM_TIM_CH3(120);    //左后

			 PWM_TIM_CH4(120);   //右后  
       m=1;
       if( norm_AD7<390||norm_AD6<390)
			 {
				 zh_go;
				 zq_go;
				 yh_go;
				 yq_go;
				 PWM_TIM_CH2(120);    //左前
				
				 PWM_TIM_CH1(120);   //右前
				
				 PWM_TIM_CH3(120);    //左后

				 PWM_TIM_CH4(120);   //右后  
				 delay_ms(500);
				 break;
			 }			 
	 }	
	}
}
		

		

	 
