#ifndef __DIVER_H
#define __DIVER_H	 
#include "sys.h"
#include "stdbool.h"

//#define LED0 PAout(8)	// PA8
//#define LED1 PDout(2)	// PD2	

void Step_Motor_GPIO_Init(void);
void SetMotor(unsigned char InputData);
void motorNcircle(int n,bool direction);
void motorNspeed(int speed,bool direction);
void zjiaodu(int n);	 
void fjiaodu(int n);
void stop(void);
void XBUJIN(void);
#endif
