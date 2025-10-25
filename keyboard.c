#include "C8051F020.h"
#include "absacc.h"
#include "delay.h"
#include "data_define.c"
#include "Init_Device.c"
#define   DP1   XBYTE[0x0000]
#define   DP2   XBYTE[0x0001]
#define   DP3   XBYTE[0x0002]
#define   DP4   XBYTE[0x0003]
#define   TIMER 0x8000
unsigned char table[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
unsigned char place_table[4][4]={{0,1,2,3},{4,5,6,7},{8,9,0x0A,0x0B},{0x0C,0x0D,0x0E,0x0F}};
unsigned char press_prestate[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
unsigned char press_curstate[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
void display(unsigned char x,unsigned char y,unsigned char *dp)//指定数码管显示坐标对应字符
{
    int num=place_table[x][y];//从位置-数字对应数组中取出应该显示的数字
 	*dp=table[num];//指定显示数字的数码管并显示num
}     
   
int read_from_keyboard(unsigned char *row_value,unsigned char *column_value)//读键盘，看是否有键被按下
{ 
	unsigned char row_state,check_num,counter,decoder_output;
    int addr;
	int i;

    addr=0x0004;//设置单片机待访问地址
    for(i=1;i<5;i++,addr++)//对每行轮询
    {  
        decoder_output=XBYTE[addr];//获取待访问地址输入译码器的输出结果
        row_state=~decoder_output&0x0f;//处理输出结果后作为行状态
        if(row_state)//该行有按键被按下
        {
            for(counter=1,check_num=0x01;counter<5;++counter,check_num=check_num<<1)//检测哪列被按下
                if((row_state&check_num)!=0)//找到被按下的列
                {
                    *row_value=counter;
                    *column_value=i;
                    return 1;
                }
        }
    }
    return 0;
}
  	
void key_process(unsigned char *row_value,unsigned char *column_value,int *tens_digit,int *ones_digit)//某键被按下后，先进行防抖动处理，再更新按键状态并显示数字
{
    unsigned char digit;
    int j,k;

    if(press_prestate[row_value][column_value])//该键之前没被按，则疑似按下
    {
        delay(10);
        if(!read_from_keyboard(&row_value,&column_value))//等待一小段时间后再次检测，若按键被松开，说明是抖动引起，不处理
            return;
    }
    else//该键一直被按着，不重复处理
        return;

    for(j=0;j<4;j++)
    {
        for(k=0;k<4;k++)
        {
            if(j==row_value-1&&k==column_value-1)//被按下的键单独处理
            {
                press_curstate[j][k]=0;//记录被按下的状态
                if(!digit)//输入十位
                {
                    *tens_digit=place_table[j][k];
                    display(j+1,k+1,&DP3);
                    digit++;//让digit不为0，使下次不再输入十位而输入个位
                }
                else//输入个位
                {
                    *ones_digit=place_table[j][k];
                    display(j+1,k+1,&DP4);
                }
            }
            else
                press_curstate[j][k]=1;
            press_prestate[j][k]=press_curstate[j][k];//更新按键状态
        }
    }    
}