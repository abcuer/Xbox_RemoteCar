#include "headfile.h"


pid_t trackLine1;   // 单级寻迹环
pid_t trackLine2;	// 串级寻迹环

float left[4]  = {-1,-2, -3, -4};  // L1 ~ L4
float right[4] = {1, 2, 3, 4}; // R1 ~ R4

/***** 单级寻迹环 ****/
void track1_pid_control(float targetValue, float basespeed)
{ 	
	Gray_Read();
	float sum = sensor.left[3] + sensor.left[2] + sensor.left[1] + sensor.left[0] + sensor.right[0]+ sensor.right[1] + sensor.right[2] + sensor.right[3];
	if (sum < 0.001f) sum = 1.0f; // 或者其他默认值，防止除零
	float currentValue = (sensor.left[3]*left[3] + sensor.left[2]*left[2] + sensor.left[1]*left[1] + sensor.left[0]*left[0] + sensor.right[0]*right[0] + sensor.right[1]*right[1] + sensor.right[2]*right[2] + sensor.right[3]*right[3]) / sum;
	trackLine1.now = currentValue;
	trackLine1.target = targetValue;
	pid_cal(&trackLine1);
	// 电机输出限幅
	pidout_limit(&trackLine1, 1000);
	Motor_left_Control(basespeed - trackLine1.out);
	Motor_right_Control(basespeed + trackLine1.out);
}

/***** 串级寻迹环 ****/
int track2_pid_control(float targetValue)
{
	Gray_Read();
	float sum = sensor.left[3] + sensor.left[2] + sensor.left[1] + sensor.left[0] + sensor.right[0]+ sensor.right[1] + sensor.right[2] + sensor.right[3];
	if (sum < 0.001f) sum = 1.0f; // 或者其他默认值，防止除零
	float currentValue = (sensor.left[3]*left[3] + sensor.left[2]*left[2] + sensor.left[1]*left[1] + sensor.left[0]*left[0] + sensor.right[0]*right[0] + sensor.right[1]*right[1] + sensor.right[2]*right[2] + sensor.right[3]*right[3]) / sum;	trackLine2.now = currentValue;
	trackLine2.target = targetValue;
	pid_cal(&trackLine2);
	// 电机输出限幅
	pidout_limit(&trackLine2, 1000);
	return trackLine2.out;
}

/*  串级寻迹环  */
/* track_tar一般为0 */
void trackloop_pid_control(float track_tar, int base)
{
	Gray_Read();
	int speed_tar = track2_pid_control(track_tar);
	speed_pid_control(speed_tar, base);
}
