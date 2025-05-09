/*
 * SSD_interface.h
 *
 * Created: 8/18/2024 12:32:40 AM
 * Author: Youssef Bassem
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_
/* Section: Includes */
#include "../../MCAL/DIO/DIO_interface.h"

/* Section: Macro Declaration */
/* 7-Segment Pins */
#define SSD_PINS        4
#define SSD_ONE         1
#define SSD_TWO         2
#define SSD_ENABLE_PORT DIO_PORTB
#define SSD_ENABLE_1    DIO_PIN1
#define SSD_ENABLE_2    DIO_PIN2



/* Delay Library */
#define F_CPU 16000000UL
#include <util/delay.h>

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: SSD_voidSendNum
* Purpose      : Sets the number on 7-Segment display
* Parameters   : u8 copy_u8num
* Return value : void
*****************************************************************************/
void SSD_voidSendNum(u8 copy_u8num);

/*****************************************************************************
* Function Name: SSD_voidMuxSSDs
* Purpose      : Multiplexes the 2 SSDs
* Parameters   : u8 copy_u8num,u8 copy_u8SSDnum
* Return value : void
*****************************************************************************/
void SSD_voidMuxSSDs(u8 copy_u8num,u8 copy_u8SSDnum);


#endif /* SSD_INTERFACE_H_ */