#include "oled.h"

const char  F6x8[][6] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,// sp
	0x00, 0x00, 0x00, 0x2f, 0x00, 0x00,// !
	0x00, 0x00, 0x07, 0x00, 0x07, 0x00,// "
	0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14,// #
	0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12,// $
	0x00, 0x62, 0x64, 0x08, 0x13, 0x23,// %
	0x00, 0x36, 0x49, 0x55, 0x22, 0x50,// &
	0x00, 0x00, 0x05, 0x03, 0x00, 0x00,// '
	0x00, 0x00, 0x1c, 0x22, 0x41, 0x00,// (
	0x00, 0x00, 0x41, 0x22, 0x1c, 0x00,// )
	0x00, 0x14, 0x08, 0x3E, 0x08, 0x14,// *
	0x00, 0x08, 0x08, 0x3E, 0x08, 0x08,// +
	0x00, 0x00, 0x00, 0xA0, 0x60, 0x00,// ,
	0x00, 0x08, 0x08, 0x08, 0x08, 0x08,// -
	0x00, 0x00, 0x60, 0x60, 0x00, 0x00,// .
	0x00, 0x20, 0x10, 0x08, 0x04, 0x02,// /
	0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
	0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,// 1
	0x00, 0x42, 0x61, 0x51, 0x49, 0x46,// 2
	0x00, 0x21, 0x41, 0x45, 0x4B, 0x31,// 3
	0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,// 4
	0x00, 0x27, 0x45, 0x45, 0x45, 0x39,// 5
	0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
	0x00, 0x01, 0x71, 0x09, 0x05, 0x03,// 7
	0x00, 0x36, 0x49, 0x49, 0x49, 0x36,// 8
	0x00, 0x06, 0x49, 0x49, 0x29, 0x1E,// 9
	0x00, 0x00, 0x36, 0x36, 0x00, 0x00,// :
	0x00, 0x00, 0x56, 0x36, 0x00, 0x00,// ;
	0x00, 0x08, 0x14, 0x22, 0x41, 0x00,// <
	0x00, 0x14, 0x14, 0x14, 0x14, 0x14,// =
	0x00, 0x00, 0x41, 0x22, 0x14, 0x08,// >
	0x00, 0x02, 0x01, 0x51, 0x09, 0x06,// ?
	0x00, 0x32, 0x49, 0x59, 0x51, 0x3E,// @
	0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,// A
	0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,// B
	0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,// C
	0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C,// D
	0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,// E
	0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,// F
	0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A,// G
	0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,// H  
	0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,// I
	0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,// J
	0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,// K
	0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,// L
	0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,// M
	0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,// N
	0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,// O
	0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,// P
	0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
	0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,// R
	0x00, 0x46, 0x49, 0x49, 0x49, 0x31,// S
	0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,// T
	0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,// U
	0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,// V
	0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,// W
	0x00, 0x63, 0x14, 0x08, 0x14, 0x63,// X
	0x00, 0x07, 0x08, 0x70, 0x08, 0x07,// Y
	0x00, 0x61, 0x51, 0x49, 0x45, 0x43,// Z
	0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,// [
	0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55,// 55
	0x00, 0x00, 0x41, 0x41, 0x7F, 0x00,// ]
	0x00, 0x04, 0x02, 0x01, 0x02, 0x04,// ^
	0x00, 0x40, 0x40, 0x40, 0x40, 0x40,// _
	0x00, 0x00, 0x01, 0x02, 0x04, 0x00,// '
	0x00, 0x20, 0x54, 0x54, 0x54, 0x78,// a
	0x00, 0x7F, 0x48, 0x44, 0x44, 0x38,// b
	0x00, 0x38, 0x44, 0x44, 0x44, 0x20,// c
	0x00, 0x38, 0x44, 0x44, 0x48, 0x7F,// d
	0x00, 0x38, 0x54, 0x54, 0x54, 0x18,// e
	0x00, 0x08, 0x7E, 0x09, 0x01, 0x02,// f
	0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C,// g
	0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,// h
	0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,// i
	0x00, 0x40, 0x80, 0x84, 0x7D, 0x00,// j
	0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,// k
	0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,// l
	0x00, 0x7C, 0x04, 0x18, 0x04, 0x78,// m
	0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,// n
	0x00, 0x38, 0x44, 0x44, 0x44, 0x38,// o
	0x00, 0xFC, 0x24, 0x24, 0x24, 0x18,// p
	0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,// q
	0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,// r
	0x00, 0x48, 0x54, 0x54, 0x54, 0x20,// s
	0x00, 0x04, 0x3F, 0x44, 0x40, 0x20,// t
	0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,// u
	0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,// v
	0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,// w
	0x00, 0x44, 0x28, 0x10, 0x28, 0x44,// x
	0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C,// y
	0x00, 0x44, 0x64, 0x54, 0x4C, 0x44,// z
	0x14, 0x14, 0x14, 0x14, 0x14, 0x14,// horiz lines
};
void OLED_GPIO_Config(void)
{
	GPIO_InitTypeDef OLED_GPIO_init;
	
	RCC_APB2PeriphClockCmd(OLED_GPIO_CLK,ENABLE);
	
	OLED_GPIO_init.GPIO_Mode=GPIO_Mode_Out_PP;
	OLED_GPIO_init.GPIO_Pin=OLED_SCL_GPIO_Pin|
							OLED_SDA_GPIO_Pin|
							OLED_RST_GPIO_Pin|
							OLED_DC_GPIO_Pin;
	OLED_GPIO_init.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(OLED_GPIO_Port,&OLED_GPIO_init);
}
void LCD_WrDat(uint8_t dat)
{
	uint8_t i=8;
	LCD_DC_H;
	for(i=0;i<8;i++) //发送一个八位数据
	{
		//LCD_SCL=0; 
		LCD_SCL_L;
		//LCD_SDA=dat&0x80;
		if(dat&0x80)
		LCD_SDA_H;
		if((dat&0x80)==0)
		LCD_SDA_L;
		//LCD_SCL=1;
		LCD_SCL_H;
		dat<<=1;
	}
}
void LCD_WrCmd(uint8_t cmd)
{
	uint8_t i=8;
	//LCD_DC=0;
	LCD_DC_L;
	for(i=0;i<8;i++) //发送一个八位数据
	{
		//LCD_SCL=0;
		LCD_SCL_L;
		//LCD_SDA=cmd&0x80;
		//x=cmd&0x80;
		if(cmd&0x80)
		LCD_SDA_H;
		if((cmd&0x80)==0)
		LCD_SDA_L;
		//LCD_SCL=1;
		LCD_SCL_H;
		cmd<<=1;;
	}
}
void LCD_Set_Pos(uint8_t x, uint8_t y)
{
	LCD_WrCmd(0xb0+y);
	LCD_WrCmd(((x&0xf0)>>4)|0x10);
	LCD_WrCmd((x&0x0f)|0x01);
}
/*********************LCD全屏************************************/
void LCD_Fill(uint8_t bmp_dat)
{
	uint8_t y,x;
	for(y=0;y<8;y++)
	{
		LCD_WrCmd(0xb0+y);
		LCD_WrCmd(0x01);
		LCD_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
		LCD_WrDat(bmp_dat);
	}
}
/*********************LCD复位************************************/
void LCD_CLS(void)
{
	uint8_t y,x;
	for(y=0;y<8;y++)
	{
		LCD_WrCmd(0xb0+y);
		LCD_WrCmd(0x01);
		LCD_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
		LCD_WrDat(0);
	}
}
/*********************LCD初始化************************************/
void LCD_Init(void)
{
	OLED_GPIO_Config();
	//LCD_SCL=1;
	LCD_SCL_H;
	//LCD_RST=0;
	LCD_RST_L;
	for(int i=10000;i>0;i--);
	//LCD_RST=1;       //从上电到下面开始初始化要有足够的时间，即等待RC复位完毕
	LCD_RST_H;
	LCD_WrCmd(0xae);//--turn off oled panel
	LCD_WrCmd(0x00);//---set low column address
	LCD_WrCmd(0x10);//---set high column address
	LCD_WrCmd(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	LCD_WrCmd(0x81);//--set contrast control register
	LCD_WrCmd(0xcf); // Set SEG Output Current Brightness
	LCD_WrCmd(0xa1);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	LCD_WrCmd(0xc8);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
	LCD_WrCmd(0xa6);//--set normal display
	LCD_WrCmd(0xa8);//--set multiplex ratio(1 to 64)
	LCD_WrCmd(0x3f);//--1/64 duty
	LCD_WrCmd(0xd3);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	LCD_WrCmd(0x00);//-not offset
	LCD_WrCmd(0xd5);//--set display clock divide ratio/oscillator frequency
	LCD_WrCmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	LCD_WrCmd(0xd9);//--set pre-charge period
	LCD_WrCmd(0xf1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	LCD_WrCmd(0xda);//--set com pins hardware configuration
	LCD_WrCmd(0x12);
	LCD_WrCmd(0xdb);//--set vcomh
	LCD_WrCmd(0x40);//Set VCOM Deselect Level
	LCD_WrCmd(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
	LCD_WrCmd(0x02);//
	LCD_WrCmd(0x8d);//--set Charge Pump enable/disable
	LCD_WrCmd(0x14);//--set(0x10) disable
	LCD_WrCmd(0xa4);// Disable Entire Display On (0xa4/0xa5)
	LCD_WrCmd(0xa6);// Disable Inverse Display On (0xa6/a7)
	LCD_WrCmd(0xaf);//--turn on oled panel
	LCD_Fill(0x00);  //初始清屏
	LCD_Set_Pos(0,0);
}

/***************功能描述：显示6*8一组标准ASCII字符串	显示的坐标（x,y），y为页范围0～7****************/
void LCD_P6x8Str(unsigned char x,unsigned char y, char ch[])
{
	unsigned char c=0,i=0,j=0;
	while (ch[j]!='\0')
	{    
		c =ch[j]-32;
		if(x>126){x=0;y++;}
		LCD_Set_Pos(x,y);
		for(i=0;i<6;i++)
		LCD_WrDat(F6x8[c][i]);
		x+=6;
		j++;
   }
}
//==============================================================
//函数名：void LED_P6x8Char(unsigned 	char x,unsigned 	char y,unsigned 	char ch);
//功能描述：显示一个6x8标准ASCII字符
//参数：x为显示的横坐标0~122，y为页范围0～7，ch要显示的字符
//返回：无
//============================================================== 
void LCD_P6x8Char(unsigned 	char x,unsigned 	char y,unsigned 	char ch)
  {
    unsigned 	char c=0,i=0;//,j=0;     
    
    c =ch-32;
    if(x>122)
      {
        x=0;
        y++;
      }
    LCD_Set_Pos(x,y);    
    for(i=0;i<6;i++)
      {     
        LCD_WrDat(F6x8[c][i]);  
      }
  }
void LCD_PrintValueFP(uint8_t x, uint8_t y, uint16_t data, uint8_t num)
  {
    uint8_t m,i,j,k;  	
    LCD_P6x8Char(x, y, '.');
    m= data/1000;
    i = (data%1000)/100;
    j = (data%100)/10;
    k = data%10;
    switch(num)
      {
       case 1:  	LCD_P6x8Char(x+6,y,k+48);
       break;
       case 2:  	LCD_P6x8Char(x+6,y,j+48);
       LCD_P6x8Char(x+12,y,k+48);
       break;
       case 3:	        LCD_P6x8Char(x+6,y,i+48);
       LCD_P6x8Char(x+12,y,j+48);
       LCD_P6x8Char(x+18,y,k+48);
       break;
       case 4: 	LCD_P6x8Char(x+6,y,m+48);
       LCD_P6x8Char(x+12,y,i+48);
       LCD_P6x8Char(x+18,y,j+48);
       LCD_P6x8Char(x+24,y,k+48);
       break;	
      }
  }
//==============================★★★★★========================================
// ★功能：oled直接传入数据
// ★输入：数据，数值最大位数，行数，列数
// ★输出：无
//================================================================================
void LCD_P6x8integer(uint16_t num,uint8_t len,uint8_t x,uint8_t y)
{
  char num1[6]="000000";
  uint32_t decimal_multiple=1;
  for(uint8_t i=len; i>1; i--)
      decimal_multiple=decimal_multiple*10;
  num1[0]=num/decimal_multiple+'0';
  num1[1]=num%decimal_multiple/(decimal_multiple/10)+'0';
  num1[2]=num%(decimal_multiple/10)/(decimal_multiple/100)+'0';
  num1[3]=num%(decimal_multiple/100)/(decimal_multiple/1000)+'0';
  num1[4]=num%(decimal_multiple/1000)/(decimal_multiple/10000)+'0';
  num1[len]='\0';
  LCD_P6x8Str(y,x,num1);
}
//==============================================================
//函数名：   void LED_PrintValueF1(uchar x, uchar y, float data);
//功能描述：将一个float型数转换成整数部分5位带小数和符号的数据并进行显示
//参数：x的范围为0～62，y为页的范围0～7，data为需要转化显示的数值整数部分最多位5位  num表示保留的小数位0~4
//返回：无
//==============================================================
void LCD_PrintValueF1(uint8_t x, uint8_t y, float data)
  {
    uint8_t l,m,i,j,k;  //百十个
    uint8_t databiti = 3; //整数位数
    uint16_t tempdataui = 0;
    int tempdataii = (int)data; //整数部分
    unsigned long int tempdatalp = (unsigned long int)((data - (long int)data)*100000); //取小数位后5位
    
    //整数部分显示
    if(tempdataii < 0)tempdataii = - tempdataii;  //去掉整数部分负号
    tempdataui = tempdataii;
    i = (tempdataui%1000)/100;
    j = (tempdataui%100)/10;
    k = tempdataui%10;
    LCD_P6x8Char(x,y,i+48);
    LCD_P6x8Char(x+8,y,j+48);
    LCD_P6x8Char(x+16,y,k+48);
//    if(tempdatalp < 0)tempdatalp = - tempdatalp;	//去掉小数部分负号
//    LED_PrintValueFP1(x + databiti * 8, y, tempdatalp);
    x=x + databiti * 8;
    if(data < 0.0000001)  
    {
          if(data <-999.0)
                LCD_P6x8Char(x, y, '/');
          else
                LCD_P6x8Char(x, y, '-');
    }
    else 
    {
          if(data <999.0)
                LCD_P6x8Char(x, y, '+');
          else
                LCD_P6x8Char(x, y,'*');
    }
    l  = tempdatalp/10000;
    m= (tempdatalp%10000)/1000;
    i = (tempdatalp%1000)/100;
    j = (tempdatalp%100)/10;
    k = tempdatalp%10;
    LCD_P6x8Char(x+8,y,l+48);
    LCD_P6x8Char(x+16,y,m+48);
    LCD_P6x8Char(x+24,y,i+48);
    LCD_P6x8Char(x+32,y,j+48);
    LCD_P6x8Char(x+40,y,k+48);
  }
//==============================================================
//函数名：   void LED_PrintValueF(uchar x, uchar y, float data, uchar num);
//功能描述：将一个float型数转换成整数部分5位带小数和符号的数据并进行显示
//参数：x的范围为0～62，y为页的范围0～7，data为需要转化显示的数值整数部分最多位5位  num表示保留的小数位0~4
//返回：无
//==============================================================
void LCD_PrintValueF(uint8_t x, uint8_t y, float data, uint8_t num)
  {
    uint8_t l,m,i,j,k;  //万千百十个
    uint8_t databiti = 6; //整数位数
    uint16_t tempdataui = 0;
    int tempdataii = (int)data; //整数部分
    long int tempdatalp = (long int)((data - (int)data)*10000); //取小数位后4位
    
    //整数部分显示
    if(data < 0.0000001)  LCD_P6x8Char(x, y,'-'); 
    else LCD_P6x8Char(x, y,'+');
    if(tempdataii < 0)tempdataii = - tempdataii;  //去掉整数部分负号
    tempdataui = tempdataii;
    l  = tempdataui/10000;
    m= (tempdataui%10000)/1000;
    i = (tempdataui%1000)/100;
    j = (tempdataui%100)/10;
    k = tempdataui%10;
    if (l != 0)  //五位
      {
        LCD_P6x8Char(x+6,y,l+48);
        LCD_P6x8Char(x+12,y,m+48);
        LCD_P6x8Char(x+18,y,i+48);
        LCD_P6x8Char(x+24,y,j+48);
        LCD_P6x8Char(x+30,y,k+48);
      }
    else if(m != 0) //四位
      {
        databiti = 5;
        LCD_P6x8Char(x+6,y,m+48);
        LCD_P6x8Char(x+12,y,i+48);
        LCD_P6x8Char(x+18,y,j+48);
        LCD_P6x8Char(x+24,y,k+48);
      }
    else if(i != 0) //三位
      {
        databiti = 4;
        LCD_P6x8Char(x+6,y,i+48);
        LCD_P6x8Char(x+12,y,j+48);
        LCD_P6x8Char(x+18,y,k+48);
      }
    else if(j != 0) //两位
      {
        databiti = 3;	
        LCD_P6x8Char(x+6,y,j+48);
        LCD_P6x8Char(x+12,y,k+48);
      }
    else 	
      {
        databiti = 2;
        LCD_P6x8Char(x+6,y,k+48);
      }	
    if(tempdatalp < 0)tempdatalp = - tempdatalp;	//去掉小数部分负号
    switch(num)
      {
       case 0: break;
       case 1:  LCD_PrintValueFP(x + databiti * 6, y, (unsigned int)(tempdatalp / 1000),num);break;
       case 2:  LCD_PrintValueFP(x + databiti * 6, y, (unsigned int)(tempdatalp / 100),num);break;
       case 3:  LCD_PrintValueFP(x + databiti * 6, y, (unsigned int)(tempdatalp / 10),num);break;
       case 4:  LCD_PrintValueFP(x + databiti * 6, y, (unsigned int)(tempdatalp),num);break;					
      }
  }
	

