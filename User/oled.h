#ifndef __OLED_H
#define __OLED_H

#include "stm32f10x.h"

#define XLevelL		0x00
#define XLevelH		0x10
#define XLevel		((XLevelH&0x0F)*16+XLevelL)
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xCF
#define X_WIDTH		128
#define Y_WIDTH		64
#define XLevelL		0x00
#define XLevelH		0x10
#define XLevel		((XLevelH&0x0F)*16+XLevelL)
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xCF
#define X_WIDTH		128
#define Y_WIDTH		64

#define OLED_GPIO_CLK		RCC_APB2Periph_GPIOB
#define OLED_GPIO_Port		GPIOB
#define OLED_SCL_GPIO_Pin	GPIO_Pin_13
#define OLED_SDA_GPIO_Pin	GPIO_Pin_15
#define OLED_RST_GPIO_Pin	GPIO_Pin_12
#define OLED_DC_GPIO_Pin	GPIO_Pin_14

#define LCD_SCL_H	{GPIO_SetBits(OLED_GPIO_Port,OLED_SCL_GPIO_Pin);}
#define LCD_SCL_L	{GPIO_ResetBits(OLED_GPIO_Port,OLED_SCL_GPIO_Pin);}

#define LCD_SDA_H	{GPIO_SetBits(OLED_GPIO_Port,OLED_SDA_GPIO_Pin);}
#define LCD_SDA_L	{GPIO_ResetBits(OLED_GPIO_Port,OLED_SDA_GPIO_Pin);}

#define LCD_RST_H	{GPIO_SetBits(OLED_GPIO_Port,OLED_RST_GPIO_Pin);}
#define LCD_RST_L	{GPIO_ResetBits(OLED_GPIO_Port,OLED_RST_GPIO_Pin);}

#define LCD_DC_H	{GPIO_SetBits(OLED_GPIO_Port,OLED_DC_GPIO_Pin);}
#define LCD_DC_L	{GPIO_ResetBits(OLED_GPIO_Port,OLED_DC_GPIO_Pin);}

void LCD_WrDat(unsigned char dat);
void LCD_WrCmd(unsigned char cmd);
void LCD_Set_Pos(unsigned char x, unsigned char y);
void LCD_Fill(unsigned char bmp_dat);
void LCD_CLS(void);      
void LCD_Init(void);
void LCD_P6x8Str(unsigned char x,unsigned char y,char ch[]);
void LCD_P6x8integer(unsigned short int num,unsigned char len,unsigned char x,unsigned char y); 

void LCD_PrintValueFP(uint8_t x, uint8_t y, uint16_t data, uint8_t num);
void LCD_P6x8integer(unsigned short int num,unsigned char len,unsigned char x,unsigned char y); 
void LCD_PrintValueF1(uint8_t x, uint8_t y, float data);
void LCD_PrintValueF(uint8_t x, uint8_t y, float data, uint8_t num);


#endif




