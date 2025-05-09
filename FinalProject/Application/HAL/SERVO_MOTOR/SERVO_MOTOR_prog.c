/*
 * SERVO_MOTOR_prog.c
 *
 * Created: 9/26/2024 1:36:49 PM
 *  Author: youss
 */ 

#include "SERVO_MOTOR_interface.h"


/*****************************************************************************
* Function Name: SERVO_MOTOR_voidRotateWithDegree
* Purpose      : Turns the Servo Motor at desired angle
* Parameters   : s8 copy_s8angle
* Return value : void
*****************************************************************************/
void SERVO_MOTOR_voidRotateWithDegree(f32 copy_f32angle){
	TIM1_voidFastPWMICR1((copy_f32angle + 270) / 36);
}