#include "sys.h"
#include "delays.h"
#include "diver.h"
#include "stdbool.h"
//IN4: PB8  d
//IN3: PB7  c
//IN2: PB6  b
//IN1: PB5  a
//�������
u8 phasecw[8] ={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};// ��ʱ��
u8 phaseccw[8]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};// ˳ʱ��

//���ų�ʼ��
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
//����ӳ��
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
//�����5.625 360/5.625=64 ���ٱ�1/64 
//��64*64������תһȦ
//nȦ�� 
//direction ����
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
                if(direction == 1)   //�޸�
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
//speed �ٶ� 
//direction ����
void motorNspeed(int speed,bool direction)
{ 
        unsigned char k=0;
        for(k=0;k<8;k++)
        {
                if(direction==1) 
                      SetMotor(phasecw[k]);  //ȡ����
                else 
                      SetMotor(phaseccw[k]);
                delay_ms(speed);        //����ת��        
        }                          
}
 

void zjiaodu(int n)
{
	 u32 z;
	 for( z=0;z<n;z++)                 //�Ƕȿ���  �Ƕ�/360=z/512
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
	 for( z=0;z<n ;z++)                 //�Ƕȿ���  �Ƕ�/360=z/512
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
void stop(void)                       //ֹͣ
{
  GPIO_ResetBits(GPIOD,GPIO_Pin_7);
	GPIO_ResetBits(GPIOG,GPIO_Pin_10);
	GPIO_ResetBits(GPIOG,GPIO_Pin_11);
	GPIO_ResetBits(GPIOG,GPIO_Pin_12);
}



