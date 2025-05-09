/*
 * SERVO_MOTOR_interface.h
 *
 * Created: 9/26/2024 1:36:31 PM
 *  Author: youss
 */ 


#ifndef SERVO_MOTOR_INTERFACE_H_
#define SERVO_MOTOR_INTERFACE_H_

/* Section: Includes */
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIM1/TIM1_interface.h"


/* Section: Macro Declaration */




/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: SERVO_MOTOR_voidRotateWithDegree
* Purpose      : Turns the Servo Motor at desired angle
* Parameters   : f32 copy_f32angle
* Return value : void
*****************************************************************************/
void SERVO_MOTOR_voidRotateWithDegree(f32 copy_f32angle);


#endif /* SERVO_MOTOR_INTERFACE_H_ */