/*
 * LED_prog.c
 *
 * Created: 8/17/2024 10:01:49 PM
 * Author:	Ahmed taha
 */ 

#include "LED_interface.h"

/*********************** LED Functions Implementation ***********************/

/*****************************************************************************
* Function Name: LED_voidOn
* Purpose      : LED ON
* Parameters   : u8 copy_u8port, u8 copy_u8pin
* Return value : void
*****************************************************************************/
void LED_voidOn(u8 copy_u8port, u8 copy_u8pin){
	DIO_voidSetPinDir(copy_u8port, copy_u8pin,OUTPUT); // Sets the pin direction to be OUTPUT
	DIO_voidSetPinVal(copy_u8port, copy_u8pin,HIGH);   // Sets the pin value to be HIGH (5v)
}

void LED_voidOff(u8 copy_u8port, u8 copy_u8pin){
	DIO_voidSetPinDir(copy_u8port, copy_u8pin,OUTPUT); // Sets the pin direction to be OUTPUT
	DIO_voidSetPinVal(copy_u8port, copy_u8pin,LOW);	   // Sets the pin value to be LOW (0v)
}

void LED_voidToggle(u8 copy_u8port, u8 copy_u8pin){
	DIO_voidSetPinDir(copy_u8port, copy_u8pin,OUTPUT); // Sets the pin direction to be OUTPUT
	DIO_voidTogglePinVal(copy_u8port, copy_u8pin);	   // Toggles the pin value
}