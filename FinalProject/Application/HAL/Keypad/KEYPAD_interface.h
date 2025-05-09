/*
 * KEYPAD_interface.h
 *
 * Created: 8/30/2024 6:54:49 PM
 * Author: Youssef Bassem
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

/* Section: Includes */
#include "KEYPAD_config.h"

/* Section: Macro Function Declaration */
#define F_CPU 16000000UL
#include <util/delay.h>

/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: KEYPAD_voidInit
* Purpose      : Initializes KEYPAD
* Parameters   : void
* Return value : void
*****************************************************************************/
void KEYPAD_voidInit(void);



/*****************************************************************************
* Function Name: KEYPAD_u8GetKey
* Purpose      : Gets KEYPAD row,col and maps it to keypad array map
* Parameters   : void
* Return value : u8
*****************************************************************************/
u8 KEYPAD_u8GetKey(void);

#endif /* KEYPAD_INTERFACE_H_ */