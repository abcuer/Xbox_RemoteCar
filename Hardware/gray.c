#include "gray.h"

#define LineFlagTime 3000

int16_t baisetime = 0;
int16_t Line_flag = 0;
int16_t LineFlagCNT = 0;

gray_t sensor;

void Gray_Read(void) 
{
    sensor.right[3] = DL_GPIO_readPins(Gray_IOA_PORT, Gray_IOA_R4_PIN) ? 0 : 1;
    sensor.right[2] = DL_GPIO_readPins(Gray_IOB_PORT, Gray_IOB_R3_PIN) ? 0 : 1;
    sensor.right[1] = DL_GPIO_readPins(Gray_IOA_PORT, Gray_IOA_R2_PIN) ? 0 : 1;
    sensor.right[0] = DL_GPIO_readPins(Gray_IOA_PORT, Gray_IOA_R1_PIN) ? 0 : 1;
    sensor.left[0] = DL_GPIO_readPins(Gray_IOA_PORT, Gray_IOA_L1_PIN) ? 0 : 1;
    sensor.left[1] = DL_GPIO_readPins(Gray_IOA_PORT, Gray_IOA_L2_PIN) ? 0 : 1;
    sensor.left[2] = DL_GPIO_readPins(Gray_IOA_PORT, Gray_IOA_L3_PIN) ? 0 : 1;
	sensor.left[3] = DL_GPIO_readPins(Gray_IOA_PORT, Gray_IOA_L4_PIN) ? 0 : 1;
}

void Get_Light_TTL(void)
{
	baisetime++;
	if(sensor.right[3] == 1 || sensor.right[2] == 1 || sensor.right[1] == 1 || sensor.right[0] == 1 || sensor.left[0] == 1 || sensor.left[1] == 1 || sensor.left[2] == 1 || sensor.left[3] == 1)
	{
		LineFlagCNT++;
		// 空白识别
		if(LineFlagCNT >= 3)
		{
			Line_flag = 1;
			baisetime = 0;
			LineFlagCNT = 0;
		}
	}
	else if(baisetime >= LineFlagTime)
	{
		Line_flag = 0;
		baisetime = 0;
	}
}