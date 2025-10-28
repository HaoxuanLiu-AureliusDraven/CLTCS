#ifndef TEMP_ADJUST_DISPLAY_H
#define TEMP_ADJUST_DISPLAY_H

#define    CS1  XBYTE[0x20AA]
#define    LED1      XBYTE[0x0000]
#define    LED2      XBYTE[0x0001]
#define    LED3      XBYTE[0x0002]
#define    LED4      XBYTE[0x0003]

extern unsigned char num[];

void delay(uint x);//可删掉，用delay.h即可

#endif