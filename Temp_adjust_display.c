
#include "C8051F020.h"
#include "absacc.h"
#include "data_define.c"
#define    CS1  XBYTE[0x20AA]
#include "Init_Device.c"
unsigned char num[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x7f};
#define    LED1      XBYTE[0x0000]
#define    LED2      XBYTE[0x0001]
#define    LED3      XBYTE[0x0002]
#define    LED4      XBYTE[0x0003]
void delay(uint x);

void main(void)
{ 
  unsigned char x=0;
  int i=0;
  Init_Device();
  LED1=LED2=LED3=LED4=0xff;
	while(1)
	{ 
		CS1=x; 
		delay(10); 
		x=CS1; 
		delay(10);
		x = (x*100)/255;
		x = x*2 + 0.5;
		x = (int)(x/2);
		i = x%10;
		LED4 = num[i];
		x = (x-i)/10;
		LED3 = num[x];
		delay(10);
		
		 
	}
}

void delay(uint x)
{ 
  unsigned long i=0;
	for(i=0;i<1000*x;++i) i=i; 
}
