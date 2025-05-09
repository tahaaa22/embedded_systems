/*
 * DIO_interface.h
 *
 * Created: 8/17/2024 7:39:25 PM
 *  Author: Youssef Bassem
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Section: Includes */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "DIO_reg.h"

/* Section: Macro Declaration */

/* Pin Direction 1 -> OUTPUT, 0 -> INPUT for DDR */
#define  OUTPUT         1
#define  INPUT          0


/* Pin Value 0v -> LOW, 5v -> HIGH for PORT Register */
#define  HIGH           1
#define  LOW            0

/* PORT Register Index */
#define  DIO_PORTA      0
#define  DIO_PORTB      1
#define  DIO_PORTC      2
#define  DIO_PORTD      3

/* Pin Numbers */
#define  DIO_PIN0       0
#define  DIO_PIN1       1
#define  DIO_PIN2       2
#define  DIO_PIN3       3
#define  DIO_PIN4       4
#define  DIO_PIN5       5
#define  DIO_PIN6       6
#define  DIO_PIN7       7

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: DIO_voidSetPinDir
* Purpose      : set pin dir (OUTPUT , INPUT)
* Parameters   : copy_u8port, u8 copy_u8pin , u8 copy_u8dir
* Return value : void
*****************************************************************************/
void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin , u8 copy_u8dir) ;


/*****************************************************************************
* Function Name: DIO_voidSetPinVal
* Purpose      : set pin value  (HIGH , LOW)
* Parameters   : copy_u8port, u8 copy_u8pin , u8 copy_u8dir
* Return value : void
*****************************************************************************/
void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin , u8 copy_u8val) ;


/*****************************************************************************
* Function Name: DIO_voidTogglePinVal
* Purpose      : toggle pin val 
* Parameters   : copy_u8port, u8 copy_u8pin 
* Return value : void
*****************************************************************************/
void DIO_voidTogglePinVal(u8 copy_u8port, u8 copy_u8pin ) ;


/*****************************************************************************
* Function Name: DIO_u8ReadPinVal
* Purpose      : reads pin val
* Parameters   : copy_u8port, u8 copy_u8pin
* Return value : u8
*****************************************************************************/
u8 DIO_u8ReadPinVal(u8 copy_u8port, u8 copy_u8pin) ;


/*****************************************************************************
* Function Name: DIO_voidSetPortDir
* Purpose      : Sets Port(All Pins) Dir
* Parameters   : u8 copy_u8port, u8 copy_u8dir
* Return value : void
*****************************************************************************/
void DIO_voidSetPortDir(u8 copy_u8port, u8 copy_u8dir);


/*****************************************************************************
* Function Name: DIO_voidSetPortDir
* Purpose      : Sets Port(All Pins) Val
* Parameters   : u8 copy_u8port, u8 copy_u8val
* Return value : void
*****************************************************************************/
void DIO_voidSetPortVal(u8 copy_u8port, u8 copy_u8val);




#endif /* DIO_INTERFACE_H_ */