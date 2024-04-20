# Serial_assistant
基于 QT5 编写的上位机，最大支持同时绘制 4 条波形

## 数据显示格式案例：
> HR=70.80 
> SpO2=99.64 
> MH=9.35
> SBP=125.04 
> DBP=71.89
> BF=3.5 
> end

## 波形绘制通信协议案例：
- =======================QT.h============================
#ifndef __QT_H
#define __QT_H

#include "stm32f4xx_hal.h"

void Sent_Data_DMA_Qt(float data1, float data2, uint8_t len);

#endif

- =======================QT.c============================
include "QT.h"
// cpu为小端模式存储，也就是在存储的时候，低位被存在0字节，高位在1字节
#define BYTE0(dwTemp) (*(char *)(&dwTemp))		 // 取出int型变量的低字节
#define BYTE1(dwTemp) (*((char *)(&dwTemp) + 1)) //	取存储在此变量下一内存字节的内容，高字节
#define BYTE2(dwTemp) (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp) (*((char *)(&dwTemp) + 3))

// 传输波形数据到 QT 上位机
void Sent_Data_DMA_Qt(float data1, float data2, uint8_t len)
{
	int i;
	uint8_t sumcheck = 0;
	uint8_t _cnt = 0;
	uint8_t Buff[20];

	Buff[_cnt++] = 0x3A; // 帧头 3A
	Buff[_cnt++] = 0x3B; // 帧头 3B
	Buff[_cnt++] = 0x01; // 功能码
	Buff[_cnt++] = len; // 有效字长度

	Buff[_cnt++] = BYTE0(data1); // 数据内容,小段模式，低位在前
	Buff[_cnt++] = BYTE1(data1); // 需要将字节进行拆分，调用上面的宏定义即可。
	Buff[_cnt++] = BYTE2(data1);
	Buff[_cnt++] = BYTE3(data1);

	Buff[_cnt++] = BYTE0(data2); // 数据内容,小段模式，低位在前
	Buff[_cnt++] = BYTE1(data2); // 需要将字节进行拆分，调用上面的宏定义即可。
	Buff[_cnt++] = BYTE2(data2);
	Buff[_cnt++] = BYTE3(data2);

	// SC和AC的校验
	for (i = 0; i < (len+4); i++)
	{
		sumcheck += Buff[i];  // 从帧头开始，对每一字节进行求和，直到DATA区结束
	}
	Buff[_cnt++] = sumcheck;

    HAL_UART_Transmit_DMA(&huart1, Buff, _cnt);   // DMA 方式发送数据
    HAL_Delay(20);
}
