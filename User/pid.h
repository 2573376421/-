#ifndef __PID_H
#define	__PID_H

#include "stm32f10x.h"
extern u8 p,x;
typedef  struct
{
  float Sv;   //�趨ֵ
	float Pv;   //״ֵ̬
	float Kp;   //�Ŵ�ϵ��
	float T;    //��������
	float Ti;   //����ʱ�䳣��
	float Td;   //΢��ʱ�䳣��
	float Ek;   //��ǰ���
	float Ek_1; //�ϴ����
	float Ek_2; //���ϴ����
	float Sek;  //��ʷ���֮��
	float Out0; //����
	float OUT;  //���ֵ
	uint16_t c10ms;
	uint16_t pwm;
}PID_InitTypeDef;


extern PID_InitTypeDef pid;

void PID_Caculator(void);
void PID_Config(void);

#endif



