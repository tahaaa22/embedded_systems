

#include "BUZZER_interface.h"

const unsigned int BUZZER_FREQUENCIES[] = {
	0,      // 0 Hz
	2500,   // 2.5 kHz
	5000,   // 5 kHz
	7500,   // 7.5 kHz
	10000,  // 10 kHz
	12500,  // 12.5 kHz
	15000,  // 15 kHz
	17500,  // 17.5 kHz
	20000,  // 20 kHz
	22500,  // 22.5 kHz
	25000,  // 25 kHz
	27500,  // 27.5 kHz
	30000,  // 30 kHz
	32500,  // 32.5 kHz
	35000,  // 35 kHz
	37500,  // 37.5 kHz
	40000,  // 40 kHz
	42500,  // 42.5 kHz
	45000,  // 45 kHz
	47500,  // 47.5 kHz
	50000   // 50 kHz
};

const unsigned int NUM_BUZZER_FREQUENCIES = sizeof(BUZZER_FREQUENCIES) / sizeof(BUZZER_FREQUENCIES[0]);


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
