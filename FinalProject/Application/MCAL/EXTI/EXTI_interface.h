/*
 * EXTI_interface.h
 *
 * Created: 8/31/2024 10:26:48 PM
 *  Author: youss
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/* Section: Includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/interrupt_vector.h"
#include "EXTI_reg.h"

/* Section: Macro Declaration */

/* Sense Control Bits */
#define  ISC00     0 // INT0 Sense Control Bit
#define  ISC01     1 // INT0 Sense Control Bit
#define  ISC10     2 // INT1 Sense Control Bit
#define  ISC11     3 // INT1 Sense Control Bit
#define  ISC2      6 // INT2 Sense Control Bit
				   
/* EXT INT Enable Bits */
#define GICR_INT0  6  
#define GICR_INT1  7 
#define GICR_INT2  5 

/* Interrupt Number */
#define INT0_      0
#define INT1_      1
#define INT2_      2
#define EXTI_NUM   3

/* Interrupt Sense Control*/
#define LOW_LEVEL           0
#define ANY_LOGICAL_CHANGE  1
#define FALLING_EDGE        2      
#define RISING_EDGE         3


/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */


/*****************************************************************************
* Function Name: EXTI_voidInit
* Purpose      : Initializes EXT INT
* Parameters   : u8 copy_u8interrupt_num , u8 copy_u8sense
* Return value : void
*****************************************************************************/
void EXTI_voidInit(u8 copy_u8interrupt_num,u8 copy_u8sense);

/*****************************************************************************
* Function Name: EXTI0_voidEnable
* Purpose      : INT0 Enable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI0_voidEnable(void);

/*****************************************************************************
* Function Name: EXTI0_voidDisable
* Purpose      : INT0 Disable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI0_voidDisable(void);

/*****************************************************************************
* Function Name: EXTI1_voidEnable
* Purpose      : INT1 Enable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI1_voidEnable(void);

/*****************************************************************************
* Function Name: EXTI1_voidDisable
* Purpose      : INT1 Disable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI1_voidDisable(void);

/*****************************************************************************
* Function Name: EXTI2_voidEnable
* Purpose      : INT2 Enable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI2_voidEnable(void);

/*****************************************************************************
* Function Name: EXTI2_voidDisable
* Purpose      : INT2 Disable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI2_voidDisable(void);

/*****************************************************************************
* Function Name: EXTI_voidSetCallback
* Purpose      : Stores the address of the function passed in the main to be called in the ISR
* Parameters   : void (*copy_ptr)(void), u8 copy_u8interrupt_num
* Return value : void
*****************************************************************************/
void EXTI_voidSetCallback(void (*copy_ptr)(void),u8 copy_u8interrupt_num);




#endif /* EXTI_INTERFACE_H_ */