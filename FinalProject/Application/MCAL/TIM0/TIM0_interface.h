/*
 * TIM0_interface.h
 *
 * Created: 9/13/2024 8:02:56 PM
 *  Author: youss
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/* Section: Includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/interrupt_vector.h"
#include "TIM0_config.h"
#include "TIM0_reg.h"



/* Section: Macro Declaration */

/* TCCR0 - Bits */
#define CS00_   0
#define CS01_   1
#define CS02_   2
#define WGM01_	3
#define COM00_	4
#define COM01_	5
#define WGM00_	6
#define FOC0_	7


/* TIMSK - Bits */
#define TOIE0_  0
#define OCIE0_  1

/* TIFR - Bits */
#define TOV0_   0
#define OCF0_   1

/* Prescaler */
#define TIM0_PRESCALER  _64PRESCALER_
#define PRESCALER_MASK  0b11111000
/* Mode */
#define TIM0_MODE       CTC_MODE

#define OCR_VAL         250

#define TIM0_TOP_VAL    256


/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: TIM0_voidInit
* Purpose      : Initializes Timer 0 Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM0_voidInit(void);

/*****************************************************************************
* Function Name: TIM0_voidStop
* Purpose      : Stops Timer 0 Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM0_voidStop(void); 

/*****************************************************************************
* Function Name: TIM0_voidsetCallback
* Purpose      : Sets the callback from main
* Parameters   : void (*copy_ptr)(void), u8 copy_u8mode
* Return value : void
*****************************************************************************/
void TIM0_voidsetCallback(void (*copy_ptr)(void), u8 copy_u8mode);

/*****************************************************************************
* Function Name: TIM0_voidFastPWM
* Purpose      : Sets Fast PWM
* Parameters   : u8 copy_u8_duty_cycle
* Return value : void
*****************************************************************************/
void TIM0_voidFastPWM(u8 copy_u8_duty_cycle); 


#endif /* TIMER_INTERFACE_H_ */