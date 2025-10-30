#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#define   DP1   XBYTE[0x0000]
#define   DP2   XBYTE[0x0001]
#define   DP3   XBYTE[0x0002]
#define   DP4   XBYTE[0x0003]
#define   TIMER 0x8000

extern unsigned char table[];
extern unsigned char place_table[4][4];
extern unsigned char press_prestate[4][4];
extern unsigned char press_curstate[4][4];
extern int set_temperature;//在main.c定义更好

int read_from_keyboard(unsigned char *row_value,unsigned char *column_value);
void key_process(unsigned char *row_value,unsigned char *column_value,int *tens_digit,int *ones_digit,unsigned char *process_flag);

#endif