/*
 * TIM2_interface.h
 *
 * Created: 9/27/2024 12:06:38 AM
 *  Author: youss
 */ 


#ifndef TIM2_INTERFACE_H_
#define TIM2_INTERFACE_H_

/* Section: Includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/interrupt_vector.h"

#include "TIM2_config.h"
#include "TIM2_reg.h"

/* Section: Macro Declaration */

/* TCCR2 - Bits */
#define CS20_   0
#define CS21_   1
#define CS22_   2
#define WGM21_	3
#define COM20_	4
#define COM21_	5
#define WGM20_	6
#define FOC2_	7

/* ASSR - Bits */
#define AS2_     3
#define TCN2UB_	 2
#define OCR2UB_	 1
#define TCR2UB_	 0
    

/* TIMSK - Bits */
#define OCIE2_  7 
#define TOIE2_  6

/* TIFR - Bits */
#define TOV2_   6
#define OCF2_   7

/* SFIOR - Bits */
#define PSR2_   1

/* Prescaler */
#define TIM2_PRESCALER  _64PRESCALER_
#define PRESCALER_MASK  0b11111000

/* Mode */
#define TIM0_MODE       CTC_MODE

#define OCR_VAL         250

#define TIM2_TOP_VAL    256

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: TIM2_voidInit
* Purpose      : Initializes Timer 2 Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM2_voidInit(void);

/*****************************************************************************
* Function Name: TIM2_voidStop
* Purpose      : Stops Timer 2 Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM2_voidStop(void);

/*****************************************************************************
* Function Name: TIM2_voidsetCallback
* Purpose      : Sets the callback from main
* Parameters   : void (*copy_ptr)(void), u8 copy_u8mode
* Return value : void
*****************************************************************************/
void TIM2_voidsetCallback(void (*copy_ptr)(void), u8 copy_u8mode);

/*****************************************************************************
* Function Name: TIM2_voidFastPWM
* Purpose      : Sets Fast PWM
* Parameters   : u8 copy_u8_duty_cycle
* Return value : void
*****************************************************************************/
void TIM2_voidFastPWM(u8 copy_u8_duty_cycle);

void TIM2_voidFastPWMFrequencyAdjust(u8 copy_u8_duty_cycle, u8 frequency);
#endif /* TIM2_INTERFACE_H_ */