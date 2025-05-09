/*
 * DC_MOTOR_interface.h
 *
 * Created: 9/25/2024 2:45:31 PM
 *  Author: youss
 */ 


#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_


/* Section: Includes */
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIM1/TIM1_interface.h"
#include "../../MCAL/TIM0/TIM0_interface.h"
#include "../../MCAL/TIM2/TIM2_interface.h"
#include "DC_MOTOR_config.h"

/* Section: Macro Declaration */
#define ELECTRICAL_SWITCH   H_BRIDGE_CONNECTION

#if ELECTRICAL_SWITCH == H_BRIDGE_CONNECTION
#define H_BRIDGE            H_BRIDGE_1
#endif



/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: DC_MOTOR_voidCW
* Purpose      : Rotates DC Motor Clockwise Direction
* Parameters   : u8 copy_u8speed
* Return value : void
*****************************************************************************/
void DC_MOTOR_voidCW(u8 copy_u8speed);

/*****************************************************************************
* Function Name: DC_MOTOR_voidACW
* Purpose      : Rotates DC Motor Anti-Clockwise Direction
* Parameters   : u8 copy_u8speed
* Return value : void
*****************************************************************************/
void DC_MOTOR_voidACW(u8 copy_u8speed);

/*****************************************************************************
* Function Name: DC_MOTOR_voidStop
* Purpose      : Stops DC Motor
* Parameters   : void
* Return value : void
*****************************************************************************/
void DC_MOTOR_voidStop(void);

void DC_MOTOR_voidMoveForward_1(u8 copy_u8speed);

void DC_MOTOR_voidMoveBackward_1(u8 copy_u8speed);

void DC_MOTOR_voidStop_1(void);

void DC_MOTOR_voidMoveForward_2(u8 copy_u8speed);

void DC_MOTOR_voidMoveBackward_2(u8 copy_u8speed);

void DC_MOTOR_voidStop_2(void);

#endif /* DC_MOTOR_INTERFACE_H_ */