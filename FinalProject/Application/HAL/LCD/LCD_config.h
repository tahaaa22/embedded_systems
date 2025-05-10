/*
 * LCD_config.h
 *
 * Created: 8/24/2024 10:46:35 PM
 * Author:  Ahmed taha
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
/* Section: Includes */
#include "../../MCAL/DIO/DIO_interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>

/* Section: Macro Declaration */

/************************************************************************/
/* Data Lines Initialization according to Mode                          */
/************************************************************************/
#if LCD_MODE == _8_BIT_MODE
	#define LCD_DPORT  DIO_PORTA
#elif LCD_MODE == _4_BIT_MODE
	#define LCD_DPORT   DIO_PORTA
	#define LCD_D4_PIN  DIO_PIN4
	#define LCD_D5_PIN  DIO_PIN5
	#define LCD_D6_PIN  DIO_PIN6
	#define LCD_D7_PIN  DIO_PIN7
#endif

/************************************************************************/
/* Control Lines                                                        */
/************************************************************************/
#define LCD_CPORT     DIO_PORTB

#define LCD_RS_PIN	  DIO_PIN1
#define LCD_RW_PIN    DIO_PIN2
#define LCD_EN_PIN    DIO_PIN3

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */



#endif /* LCD_CONFIG_H_ */