/*
 * DC_MOTOR_prog.c
 *
 * Created: 9/25/2024 2:46:18 PM
 *  Author: youss
 */ 

#include "DC_MOTOR_interface.h"


/*****************************************************************************
* Function Name: DC_MOTOR_voidCW
* Purpose      : Rotates DC Motor Clockwise Direction
* Parameters   : u8 copy_u8speed
* Return value : void
*****************************************************************************/
void DC_MOTOR_voidCW(u8 copy_u8speed){
	#if ELECTRICAL_SWITCH == H_BRIDGE_CONNECTION
		//#if H_BRIDGE == H_BRIDGE_1
		DIO_voidSetPinDir(DC_MOTOR_H_EN1_PORT,DC_MOTOR_H_EN1_PIN,OUTPUT);
		DIO_voidSetPinDir(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,OUTPUT);
		DIO_voidSetPinDir(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,OUTPUT);
		
		TIM1_voidFastPWM10BitRes(OC1B_PIN,copy_u8speed);
		DIO_voidSetPinVal(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,HIGH);
		DIO_voidSetPinVal(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,LOW);
		//#elif H_BRIDGE == H_BRIDGE_2
		DIO_voidSetPinDir(DC_MOTOR_H_EN2_PORT,DC_MOTOR_H_EN2_PIN,OUTPUT);
		DIO_voidSetPinDir(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,OUTPUT);
		DIO_voidSetPinDir(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,OUTPUT);
		
		TIM1_voidFastPWM10BitRes(OC1A_PIN,copy_u8speed);
		DIO_voidSetPinVal(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,HIGH);
		DIO_voidSetPinVal(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,LOW);
		//#endif
	#elif ELECTRICAL_SWITCH == RELAY_CONNECTION
	DIO_voidSetPinDir(DC_MOTOR_H_EN1_PORT,DC_MOTOR_H_EN1_PIN,OUTPUT);
	TIM1_voidFastPWM10BitRes(OC1B_PIN,copy_u8speed);
	#endif
	
	
}

/*****************************************************************************
* Function Name: DC_MOTOR_voidACW
* Purpose      : Rotates DC Motor Anti-Clockwise Direction
* Parameters   : u8 copy_u8speed
* Return value : void
*****************************************************************************/
void DC_MOTOR_voidACW(u8 copy_u8speed){
	#if ELECTRICAL_SWITCH == H_BRIDGE_CONNECTION
		//#if H_BRIDGE == H_BRIDGE_1
		DIO_voidSetPinDir(DC_MOTOR_H_EN1_PORT,DC_MOTOR_H_EN1_PIN,OUTPUT);
		DIO_voidSetPinDir(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,OUTPUT);
		DIO_voidSetPinDir(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,OUTPUT);
		
		TIM1_voidFastPWM10BitRes(OC1B_PIN,copy_u8speed);
		DIO_voidSetPinVal(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,LOW);
		DIO_voidSetPinVal(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,HIGH);
		//#elif H_BRIDGE == H_BRIDGE_2
		DIO_voidSetPinDir(DC_MOTOR_H_EN2_PORT,DC_MOTOR_H_EN2_PIN,OUTPUT);
		DIO_voidSetPinDir(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,OUTPUT);
		DIO_voidSetPinDir(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,OUTPUT);
		
		TIM1_voidFastPWM10BitRes(OC1A_PIN,copy_u8speed);
		DIO_voidSetPinVal(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,LOW);
		DIO_voidSetPinVal(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,HIGH);
		//#endif
	#elif ELECTRICAL_SWITCH == RELAY_CONNECTION
		DIO_voidSetPinDir(DC_MOTOR_H_EN1_PORT,DC_MOTOR_H_EN1_PIN,OUTPUT);
		TIM1_voidFastPWM10BitRes(OC1B_PIN,copy_u8speed);
	#endif
}

/*****************************************************************************
* Function Name: DC_MOTOR_voidStop
* Purpose      : Stops DC Motor
* Parameters   : u8 copy_u8speed
* Return value : void
*****************************************************************************/
void DC_MOTOR_voidStop(void){
	//#if H_BRIDGE == H_BRIDGE_1
	DIO_voidSetPinDir(DC_MOTOR_H_EN1_PORT,DC_MOTOR_H_EN1_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,OUTPUT);
	
	TIM1_voidFastPWM10BitRes(OC1B_PIN,0);
	DIO_voidSetPinVal(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,LOW);
	DIO_voidSetPinVal(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,LOW);
	//#elif H_BRIDGE == H_BRIDGE_2
	DIO_voidSetPinDir(DC_MOTOR_H_EN2_PORT,DC_MOTOR_H_EN2_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,OUTPUT);
	
	TIM1_voidFastPWM10BitRes(OC1A_PIN,0);
	DIO_voidSetPinVal(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,LOW);
	DIO_voidSetPinVal(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,LOW);
	//#endif
}

void DC_MOTOR_voidMoveForward_1(u8 copy_u8speed){
	DIO_voidSetPinDir(DC_MOTOR_H_EN1_PORT,DC_MOTOR_H_EN1_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,OUTPUT);
	
	TIM2_voidFastPWM(copy_u8speed);
	DIO_voidSetPinVal(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,HIGH);
	DIO_voidSetPinVal(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,LOW);
}

void DC_MOTOR_voidMoveBackward_1(u8 copy_u8speed){
	DIO_voidSetPinDir(DC_MOTOR_H_EN1_PORT,DC_MOTOR_H_EN1_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,OUTPUT);
	
	TIM2_voidFastPWM(copy_u8speed);
	DIO_voidSetPinVal(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,LOW);
	DIO_voidSetPinVal(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,HIGH);
}

void DC_MOTOR_voidStop_1(void){
	DIO_voidSetPinDir(DC_MOTOR_H_EN1_PORT,DC_MOTOR_H_EN1_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,OUTPUT);
	
	TIM2_voidFastPWM(0);
	DIO_voidSetPinVal(DC_MOTOR_H_A1_PORT,DC_MOTOR_H_A1_PIN,LOW);
	DIO_voidSetPinVal(DC_MOTOR_H_A2_PORT,DC_MOTOR_H_A2_PIN,LOW);
}

void DC_MOTOR_voidMoveForward_2(u8 copy_u8speed){
	DIO_voidSetPinDir(DC_MOTOR_H_EN2_PORT,DC_MOTOR_H_EN2_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,OUTPUT);
	
	TIM0_voidFastPWM(copy_u8speed);
	DIO_voidSetPinVal(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,HIGH);
	DIO_voidSetPinVal(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,LOW);
}

void DC_MOTOR_voidMoveBackward_2(u8 copy_u8speed){
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN3,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,OUTPUT);
	
	TIM0_voidFastPWM(copy_u8speed);
	DIO_voidSetPinVal(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,LOW);
	DIO_voidSetPinVal(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,HIGH);
}

void DC_MOTOR_voidStop_2(void){
	DIO_voidSetPinDir(DC_MOTOR_H_EN2_PORT,DC_MOTOR_H_EN2_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,OUTPUT);
	DIO_voidSetPinDir(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,OUTPUT);
	
	TIM0_voidFastPWM(0);
	DIO_voidSetPinVal(DC_MOTOR_H_A3_PORT,DC_MOTOR_H_A3_PIN,LOW);
	DIO_voidSetPinVal(DC_MOTOR_H_A4_PORT,DC_MOTOR_H_A4_PIN,LOW);
}

