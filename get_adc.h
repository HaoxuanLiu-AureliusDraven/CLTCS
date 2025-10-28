#ifndef GET_ADC_H
#define GET_ADC_H

#define    CS1       XBYTE[0x20AA]
#define    LED1      XBYTE[0x0000]
#define    LED2      XBYTE[0x0001]
#define    LED3      XBYTE[0x0002]
#define    LED4      XBYTE[0x0003]

extern unsigned char num[];

void delay(uint x);
unsigned char read_adc(void);
unsigned char ave_adc(void);
unsigned char filter(void);
void display(unsigned char x);

#endif