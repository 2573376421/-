#ifndef __PID_H
#define	__PID_H

#include "stm32f10x.h"
extern u8 p,x;
typedef  struct
{
  float Sv;   //设定值
	float Pv;   //状态值
	float Kp;   //放大系数
	float T;    //采样周期
	float Ti;   //积分时间常数
	float Td;   //微分时间常数
	float Ek;   //当前误差
	float Ek_1; //上次误差
	float Ek_2; //上上次误差
	float Sek;  //历史误差之和
	float Out0; //常数
	float OUT;  //输出值
	uint16_t c10ms;
	uint16_t pwm;
}PID_InitTypeDef;


extern PID_InitTypeDef pid;

void PID_Caculator(void);
void PID_Config(void);

#endif



