

#include "BUZZER_interface.h"

/*****************************************************************************
* Function Name: BUZZER_voidOn
* Purpose      : Turns buzzer on
* Parameters   : u8 copy_u8duty_cycle
* Return value : void
*****************************************************************************/
void BUZZER_voidOn(u8 copy_u8duty_cycle, u8 frequency){
	DIO_voidSetPinDir(BUZZER_PORT,BUZZER_PIN,OUTPUT);
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN7,OUTPUT);
	
	TIM2_voidFastPWMFrequencyAdjust(copy_u8duty_cycle, frequency);
	
}

/*****************************************************************************
* Function Name: BUZZER_voidOff
* Purpose      : Turns buzzer off
* Parameters   : void
* Return value : void
*****************************************************************************/
void BUZZER_voidOff(void){
	TIM2_voidStop(); 

	// Set pin to output and set it low
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN7,OUTPUT);
	DIO_voidSetPinVal(DIO_PORTD,DIO_PIN7,LOW);
}
