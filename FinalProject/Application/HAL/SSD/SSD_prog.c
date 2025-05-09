/*
 * SSD_prog.c
 *
 * Created: 8/18/2024 12:32:55 AM
 * Author: Youssef Bassem
 */ 

#include "SSD_interface.h"


/*********************** SSD Functions Implementation ***********************/
/*****************************************************************************
* Function Name: SSD_voidSendNum
* Purpose      : Sets the number on 7-Segment display
* Parameters   : u8 copy_u8num
* Return value : void
*****************************************************************************/
void SSD_voidSendNum(u8 copy_u8num){
	DIO_voidSetPortDir(DIO_PORTA,0xf0);                   // Sets the MSB of PORTA to be OUTPUT
	DIO_voidSetPortVal(DIO_PORTA,(copy_u8num<<SSD_PINS)); // Sets the MSB of PORTA to the provided numbers
}


/*****************************************************************************
* Function Name: SSD_voidMuxSSDs
* Purpose      : Multiplexes the 2 SSDs
* Parameters   : u8 copy_u8num,u8 copy_u8SSDnum
* Return value : void
*****************************************************************************/
void SSD_voidMuxSSDs(u8 copy_u8num,u8 copy_u8SSDnum){
	
	SSD_voidSendNum(copy_u8num);                      // Displays number on both SSDs
	
	if (copy_u8SSDnum == SSD_ONE) {
		DIO_voidSetPinVal(DIO_PORTB, DIO_PIN1, HIGH); // Enables SSD one
		DIO_voidSetPinVal(DIO_PORTB, DIO_PIN2, LOW);  // Disables SSD two
	} else if (copy_u8SSDnum == SSD_TWO) {
		DIO_voidSetPinVal(DIO_PORTB, DIO_PIN1, LOW);  // Enables SSD two
		DIO_voidSetPinVal(DIO_PORTB, DIO_PIN2, HIGH); // Disables SSD one
	}
	_delay_ms(5);
	
	
}