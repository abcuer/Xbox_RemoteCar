#ifndef _motor_h
#define _motor_h
#include "headfile.h"

#define CARSPEED 400
#define CARSPEEDOFFSET 200

#define AIN1_OUT(X)  ( (X) ? (DL_GPIO_setPins(Motor_left_PORT,Motor_left_AIN1_PIN)) : (DL_GPIO_clearPins(Motor_left_PORT,Motor_left_AIN1_PIN)) )
#define AIN2_OUT(X)  ( (X) ? (DL_GPIO_setPins(Motor_left_PORT,Motor_left_AIN2_PIN)) : (DL_GPIO_clearPins(Motor_left_PORT,Motor_left_AIN2_PIN)) )

#define BIN1_OUT(X)  ( (X) ? (DL_GPIO_setPins(Motor_right_PORT,Motor_right_BIN1_PIN)) : (DL_GPIO_clearPins(Motor_right_PORT,Motor_right_BIN1_PIN)) )
#define BIN2_OUT(X)  ( (X) ? (DL_GPIO_setPins(Motor_right_PORT,Motor_right_BIN2_PIN)) : (DL_GPIO_clearPins(Motor_right_PORT,Motor_right_BIN2_PIN)) )

void Motor_left_duty(uint8_t dir, uint32_t speed);;
void Motor_right_duty(uint8_t dir, uint32_t speed);

void Motor_left_Control(float speed);
void Motor_right_Control(float speed);

void CarForward(void);
void CarBackward(void);
void CarTurnLeft(void);
void CarLeftForward(void);
void CarLeftBackward(void);
void CarTurnRight(void);
void CarRightForward(void);
void CarRightBackward(void);
void CarStop(void);

#endif
