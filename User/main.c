#include "stm32f10x.h"
#include "all.h"

extern uint16_t AD1_MAX,AD2_MAX,AD3_MAX,AD4_MAX,AD5_MAX,AD6_MAX,AD0_MAX,AD7_MAX;
extern uint16_t ad_Maxcache1,ad_Maxcache2,ad_Maxcache3,ad_Maxcache4,ad_Maxcache5,ad_Maxcache6,ad_Maxcache0,ad_Maxcache7;
extern uint16_t AD1_MIN,AD2_MIN,AD3_MIN,AD4_MIN,AD5_MIN,AD6_MIN,AD0_MIN,AD7_MIN;
extern uint16_t ad_Mincache1,ad_Mincache2,ad_Mincache3,ad_Mincache4,ad_Mincache5,ad_Mincache6,ad_Mincache0,ad_Mincache7;

void flash(void)
{
	while(1)
	{	
	  if(GPIO_ReadInputDataBit(TRIG_GPIO_PORT,TRIG_GPIO_PIN)==0)
			break;
	}
  while(1)
  {
		DISPLAY_AD_GET();
	if(GPIO_ReadInputDataBit(GD_GPIO_PORT,GD_GPIO_PIN)==0)
		break;
			if(AD0_MAX>ad_Maxcache0) {ad_Maxcache0=AD0_MAX;}
			if(AD0_MIN<ad_Mincache0) {ad_Mincache0=AD0_MIN;}
			if(AD1_MAX>ad_Maxcache1) {ad_Maxcache1=AD1_MAX;}
			if(AD1_MIN<ad_Mincache1) {ad_Mincache1=AD1_MIN;}
			if(AD2_MAX>ad_Maxcache2) {ad_Maxcache2=AD2_MAX;}
			if(AD2_MIN<ad_Mincache2) {ad_Mincache2=AD2_MIN;}
			if(AD3_MAX>ad_Maxcache3) {ad_Maxcache3=AD3_MAX;}
			if(AD3_MIN<ad_Mincache3) {ad_Mincache3=AD3_MIN;}
			if(AD4_MAX>ad_Maxcache4) {ad_Maxcache4=AD4_MAX;}
			if(AD4_MIN<ad_Mincache4) {ad_Mincache4=AD4_MIN;}
			if(AD5_MAX>ad_Maxcache5) {ad_Maxcache5=AD5_MAX;}
			if(AD5_MIN<ad_Mincache5) {ad_Mincache5=AD5_MIN;}
			if(AD6_MAX>ad_Maxcache6) {ad_Maxcache6=AD6_MAX;}
			if(AD6_MIN<ad_Mincache6) {ad_Mincache6=AD6_MIN;}
			if(AD7_MAX>ad_Maxcache7) {ad_Maxcache7=AD7_MAX;}
			if(AD7_MIN<ad_Mincache7) {ad_Mincache7=AD7_MIN;}
	}
			FLASH_ErasePage(240);

			flash_write(240,0 ,(uint16_t)(ad_Maxcache1));
			flash_write(240,4 ,(uint16_t)(ad_Maxcache2));
			flash_write(240,8 ,(uint16_t)(ad_Maxcache3));
			flash_write(240,12,(uint16_t)(ad_Maxcache4));
			flash_write(240,16,(uint16_t)(ad_Maxcache5));
			flash_write(240,20,(uint16_t)(ad_Maxcache6));
			flash_write(240,24,(uint16_t)(ad_Mincache1*7/10));
			flash_write(240,28,(uint16_t)(ad_Mincache2*7/10));
			flash_write(240,32,(uint16_t)(ad_Mincache3*7/10));
			flash_write(240,36,(uint16_t)(ad_Mincache4*7/10));
			flash_write(240,40,(uint16_t)(ad_Mincache5*7/10));
			flash_write(240,44,(uint16_t)(ad_Mincache6*7/10));
			flash_write(240,48,(uint16_t)(ad_Maxcache0));
			flash_write(240,52,(uint16_t)(ad_Mincache0*7/10));
			flash_write(240,56,(uint16_t)(ad_Maxcache7));
			flash_write(240,60,(uint16_t)(ad_Mincache7*7/10));
}
void Flash_Read(void)
{
		AD1_MAX = flash_read(240,0);
		AD2_MAX = flash_read(240,4);
		AD3_MAX = flash_read(240,8);
		AD4_MAX = flash_read(240,12);
		AD5_MAX = flash_read(244,16);
		AD6_MAX = flash_read(245,20);
		AD1_MIN = flash_read(246,24);
		AD2_MIN = flash_read(247,28);
		AD3_MIN = flash_read(248,32);
		AD4_MIN = flash_read(249,36);
		AD5_MIN = flash_read(250,40);
		AD6_MIN = flash_read(251,44);

		AD0_MAX = flash_read(252,48);
		AD0_MIN = flash_read(253,52);
		AD7_MAX = flash_read(254,56);
		AD7_MIN = flash_read(255,60);
	}

int main(void)
{
	delay_init();
	LCD_Init();      //液晶初始化
  MOTOR_GPIO_Init();  //电机初始化
	PID_Config();      //PID初始化
	ADCx_Init();       //AD初始化
	BASIC_TIM6_Init();    //adc中断初始化
  BASIC_TIM6_Start();     //adc中断开始 
  PWM_TIM3_Mode_Config();    //输出pwm
  PWM_TIM4_Mode_Config();    //输出pwm
  PWM_GPIO_config();	 //pwm初始化
	DBJ_Init();   //步进电机引脚初始化
  TIM8_init();   //步进电机脉冲初始化
	Step_Motor_GPIO_Init();  //小步进初始化
	pca_setfreq(50);
	BJDJ_Stop;   //停止步进电机
		stop_car();
	flash();     //存AD值

	PCA_MG9XX_Init(60,0);   //舵机初始化
//	delay_ms(5000);
//	PCA_MG9XX(12,10,80,0,50);
//	delay_ms(5000);
//	PCA_MG9XX(12,80,10,0,50);
//	delay_ms(5000);
go_car();
	while(1)
	{
//	  DISPLAY_AD_GET();
    CONTROL();
//		GPIO_ResetBits(INT8_GPIO_PORT,GPIO_Pin_7);
//		GPIO_SetBits(INT7_GPIO_PORT, GPIO_Pin_6);
	}
}






