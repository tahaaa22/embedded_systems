/*
 * BUZZER_interface.h
 *
 * Created: 9/28/2024 2:20:10 AM
 *  Author: youss
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

/* Section: Includes */
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIM0/TIM0_interface.h"

/* Section: Macro Declaration */
#define BUZZER_PORT   DIO_PORTA
#define BUZZER_PIN    DIO_PIN3



/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: BUZZER_voidOn
* Purpose      : Turns buzzer on
* Parameters   : u8 copy_u8duty_cycle
* Return value : void
*****************************************************************************/
void BUZZER_voidOn(u8 copy_u8duty_cycle, u8 frequency);

/*****************************************************************************
* Function Name: BUZZER_voidOff
* Purpose      : Turns buzzer off
* Parameters   : void
* Return value : void
*****************************************************************************/
void BUZZER_voidOff(void);


#endif /* BUZZER_INTERFACE_H_ */