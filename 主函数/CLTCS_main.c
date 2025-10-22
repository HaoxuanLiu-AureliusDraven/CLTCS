//配置系统文件
#include "C8051F020.h"
#include "absacc.h"
#include "data_define.c"
#include "Init_Device.c"

//给四个数码管配置地址
#define    LED1      XBYTE[0x0000]
#define    LED2      XBYTE[0x0001]
#define    LED3      XBYTE[0x0002]
#define    LED4      XBYTE[0x0003]

int main(void){

    Init_Device(); //单片机初始化配置
    LED1=LED2=LED3=LED4=0xff;//初始状态让四个数码管全灭

    while(1){

        forward_path();
        delay(10);
        feedback();
        delay(10);
    }
}