/*
 * BUZZER_prog.c
 *
 * Created: 9/28/2024 2:20:22 AM
 *  Author: youss
 */ 

#include "BUZZER_interface.h"

/*****************************************************************************
* Function Name: BUZZER_voidOn
* Purpose      : Turns buzzer on
* Parameters   : u8 copy_u8duty_cycle
* Return value : void
*****************************************************************************/
void BUZZER_voidOn(u8 copy_u8duty_cycle){
	DIO_voidSetPinDir(BUZZER_PORT,BUZZER_PIN,OUTPUT);
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN3,OUTPUT);
	
	TIM0_voidFastPWM(copy_u8duty_cycle);
	
}

/*****************************************************************************
* Function Name: BUZZER_voidOff
* Purpose      : Turns buzzer off
* Parameters   : void
* Return value : void
*****************************************************************************/
void BUZZER_voidOff(void){
	DIO_voidSetPinDir(BUZZER_PORT,BUZZER_PIN,OUTPUT);
	DIO_voidSetPinVal(BUZZER_PORT,BUZZER_PIN,LOW);
}