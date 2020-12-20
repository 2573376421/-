#include "sys.h"
#include "delays.h"
#include "diver.h"
#include "stdbool.h"
//IN4: PB8  d
//IN3: PB7  c
//IN2: PB6  b
//IN1: PB5  a
//四相八拍
u8 phasecw[8] ={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};// 逆时针
u8 phaseccw[8]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};// 顺时针

//引脚初始化
void Step_Motor_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_Init(GPIOD,&GPIO_InitStructure);   
	
	  
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_Init(GPIOG,&GPIO_InitStructure);   
}
//引脚映射
void SetMotor(unsigned char InputData)
{
    if(InputData&0x01)
    {
        GPIO_SetBits(GPIOB,GPIO_Pin_5);
    }
    else
    {
        GPIO_ResetBits(GPIOB,GPIO_Pin_5);
    }
    if(InputData&0x02)
    {
        GPIO_SetBits(GPIOB,GPIO_Pin_6);
    }
    else
    {
        GPIO_ResetBits(GPIOB,GPIO_Pin_6);

    }
    if(InputData&0x04)
    {
        GPIO_SetBits(GPIOB,GPIO_Pin_7);
    }
    else
    {
        GPIO_ResetBits(GPIOB,GPIO_Pin_7);
    }
    if(InputData&0x08)
    {
        GPIO_SetBits(GPIOB,GPIO_Pin_8);
    }
    else
    {
        GPIO_ResetBits(GPIOB,GPIO_Pin_8);
    }
}
//步距角5.625 360/5.625=64 减速比1/64 
//故64*64个脉冲转一圈
//n圈数 
//direction 方向
void motorNcircle(int n,bool direction)
{
    int i,j,k=0;
    for(j=0;j<n;j++)
    {
        for(i=0;i<512;i++)
        //for(i=0;i<8;i++)
        {
            for(k=0;k<8;k++)
            {
                if(direction == 1)   //修改
                {
                    SetMotor(phasecw[k]);
                }
                else
                {
                    SetMotor(phaseccw[k]);
                }
                delay_ms(2);
            }
        }
    }
}
//speed 速度 
//direction 方向
void motorNspeed(int speed,bool direction)
{ 
        unsigned char k=0;
        for(k=0;k<8;k++)
        {
                if(direction==1) 
                      SetMotor(phasecw[k]);  //取数据
                else 
                      SetMotor(phaseccw[k]);
                delay_ms(speed);        //调节转速        
        }                          
}
 

void zjiaodu(int n)
{
	 u32 z;
	 for( z=0;z<n;z++)                 //角度控制  角度/360=z/512
	 { 
			 GPIO_SetBits(GPIOD,GPIO_Pin_7);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_10);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_11);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_12);
			 delay_ms(5);
			 GPIO_ResetBits(GPIOD,GPIO_Pin_7);
			 GPIO_SetBits(GPIOG,GPIO_Pin_10);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_11);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_12);
			 delay_ms(5);
			 GPIO_ResetBits(GPIOD,GPIO_Pin_7);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_10);
			 GPIO_SetBits(GPIOG,GPIO_Pin_11);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_12);
			 delay_ms(5);
			 GPIO_ResetBits(GPIOD,GPIO_Pin_7);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_10);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_11);
			 GPIO_SetBits(GPIOG,GPIO_Pin_12);
	 }
}

void fjiaodu(int n)
{
	 u32 z;
	 for( z=0;z<n ;z++)                 //角度控制  角度/360=z/512
	 { 
			 GPIO_ResetBits(GPIOD,GPIO_Pin_7);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_10);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_11);
			 GPIO_SetBits(GPIOG,GPIO_Pin_12);
			 delay_ms(5);
			 GPIO_ResetBits(GPIOD,GPIO_Pin_7);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_10);
			 GPIO_SetBits(GPIOG,GPIO_Pin_11);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_12);
			 delay_ms(5);
			 GPIO_ResetBits(GPIOD,GPIO_Pin_7);
			 GPIO_SetBits(GPIOG,GPIO_Pin_10);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_11);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_12);
			 delay_ms(5);
			 GPIO_SetBits(GPIOD,GPIO_Pin_7);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_10);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_11);
			 GPIO_ResetBits(GPIOG,GPIO_Pin_12);
	 }
}
void stop(void)                       //停止
{
  GPIO_ResetBits(GPIOD,GPIO_Pin_7);
	GPIO_ResetBits(GPIOG,GPIO_Pin_10);
	GPIO_ResetBits(GPIOG,GPIO_Pin_11);
	GPIO_ResetBits(GPIOG,GPIO_Pin_12);
}



