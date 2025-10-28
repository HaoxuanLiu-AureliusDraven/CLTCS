#ifndef __INPUT_CONTROL_H__
#define __INPUT_CONTROL_H__

#define DAC XBYTE[0x4000] //为DAC分配地址
#define DAC_MAX 0xFF //设定DAC最大和最小输出，防止数据溢出
#define DAC_MIN 0x00

#define Kp 1.2 //比例系数
#define Ki 0.05 //积分系数
#define Kd 0.3 //微分系数

//测试完后把main改名添加到这里

#endif