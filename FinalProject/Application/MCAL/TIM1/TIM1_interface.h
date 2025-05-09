/*
 * TIM1_inteface.h
 *
 * Created: 9/14/2024 8:56:09 PM
 *  Author: youss
 */ 


#ifndef TIM1_INTEFACE_H_
#define TIM1_INTEFACE_H_

/* Section: Includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/interrupt_vector.h"

#include "TIM1_config.h"
#include "TIM1_reg.h"


/* Section: Macro Declaration */

/* TCCR1A - Bits */
#define COM1A1_    7   
#define COM1A0_    6
#define COM1B1_    5
#define COM1B0_    4
#define FOC1A_     3
#define FOC1B_     2
#define WGM11_     1
#define WGM10_     0

/* TCCR1B - Bits */
#define ICNC1_     7  
#define ICES1_     6
#define WGM13_     4
#define WGM12_     3
#define CS12_      2
#define CS11_      1
#define CS10_      0

/* TIMSK - Bits */
#define TICIE1_    5 
#define OCIE1A_    4
#define OCIE1B_    3
#define TOIE1_     2

/* TIFR - Bits */
#define ICF1_      5 
#define OCF1A_	   4
#define OCF1B_	   3
#define TOV1_	   2
 
/* Prescaler */
#define TIM1_PRESCALER  _8PRESCALER_
#define PRESCALER_MASK  0b11111000

/* PWM Pins */
#define  OC1A_PIN      0
#define  OC1B_PIN      1
#define  TIM1_TOP_VAL  1024

#define  SERVO_TOP_VAL 40000

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: TIMER1_voidFastPWM10BitRes
* Purpose      : Initializes Fast PWM for Timer 1
* Parameters   : u8 copy_u8pin , u8 copy_u8duty_cycle
* Return value : void
*****************************************************************************/
void TIM1_voidFastPWM10BitRes(u8 copy_u8pin , u8 copy_u8duty_cycle);

/*****************************************************************************
* Function Name: TIM1_voidStart
* Purpose      : Initializes Normal Mode for Timer 1
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM1_voidStart(void);

/*****************************************************************************
* Function Name: TIM1_voidStop
* Purpose      : Stops Timer 1 Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM1_voidStop(void);

/*****************************************************************************
* Function Name: TIM1_voidReset
* Purpose      : Resets Timer 1 to zero
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM1_voidReset(void);

/*****************************************************************************
* Function Name: TIM1_u16ReadVal
* Purpose      : Returns Timer 1 value
* Parameters   : void
* Return value : u16
*****************************************************************************/
u16 TIM1_u16ReadVal(void);

/*****************************************************************************
* Function Name: TIM1_voidSetOCRVal
* Purpose      : Returns Timer 1 value
* Parameters   : u16 copy_u16val
* Return value : void
*****************************************************************************/
void TIM1_voidSetOCRVal(u16 copy_u16val);

/*****************************************************************************
* Function Name: TIM1_voidFastPWMICR1
* Purpose      : Fast PWM using ICR1 
* Parameters   : f32 copy_u8duty_cycle
* Return value : void
*****************************************************************************/
void TIM1_voidFastPWMICR1(f32 copy_u8duty_cycle);

/*****************************************************************************
* Function Name: TIM1_voidICUDutyCycle
* Purpose      : ICU to Calculate the Duty Cycle between rising and falling edges
* Parameters   : f32 copy_u8duty_cycle
* Return value : void
*****************************************************************************/
void TIM1_voidICUDutyCycle(u16* copy_u16t1 , u16* copy_u16t2);

#endif /* TIM1_INTEFACE_H_ */