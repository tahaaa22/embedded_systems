/*
 * LED_interface.h
 *
 * Created: 8/17/2024 10:01:30 PM
 * Author: Ahmed taha
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
/* Section: Includes */
#include "../../MCAL/DIO/DIO_interface.h"


/* Section: Macro Declaration */


/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: LED_voidOn
* Purpose      : LED ON
* Parameters   : u8 copy_u8port, u8 copy_u8pin
* Return value : void
*****************************************************************************/
void LED_voidOn(u8 copy_u8port, u8 copy_u8pin);


/*****************************************************************************
* Function Name: LED_voidOf
* Purpose      : LED OFF
* Parameters   : u8 copy_u8port, u8 copy_u8pin
* Return value : void
*****************************************************************************/
void LED_voidOff(u8 copy_u8port, u8 copy_u8pin);


/*****************************************************************************
* Function Name: LED_voidToggle
* Purpose      : LED TOGGLE
* Parameters   : u8 copy_u8port, u8 copy_u8pin
* Return value : void
*****************************************************************************/
void LED_voidToggle(u8 copy_u8port, u8 copy_u8pin);







#endif /* LED_INTERFACE_H_ */