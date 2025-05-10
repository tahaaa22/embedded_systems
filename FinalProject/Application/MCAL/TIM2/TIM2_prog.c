/*
 * TIM2_prog.c
 *
 * Created: 9/27/2024 12:06:54 AM
 *  Author: youss
 */ 

#include "TIM2_interface.h"

/* Global Pointer To Function for callback */
void (*TIM2_PTR[2])(void) = {null};

/*****************************************************************************
* Function Name: TIM2_voidInit
* Purpose      : Initializes Timer 2 Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM2_voidInit(void){
	/* Select Mode */
	#if TIM2_MODE == OVF_MODE
	CLR_BIT(TCCR2_REG,WGM21_);
	CLR_BIT(TCCR2_REG,WGM20_);
	SET_BIT(TIMSK_REG,TOIE2_); // Overflow Interrupt Enable
	#elif TIM2_MODE == CTC_MODE
	SET_BIT(TCCR2_REG,WGM21_);
	CLR_BIT(TCCR2_REG,WGM20_);
	SET_BIT(TIMSK_REG,OCIE2_); // Output Compare Match Interrupt Enable
	OCR2_REG = OCR_VAL;
	#endif
	
	/* Select Prescalar */
	TCCR2_REG &= PRESCALER_MASK;
	TCCR2_REG |= TIM2_PRESCALER;
}

/*****************************************************************************
* Function Name: TIM2_voidStop
* Purpose      : Stops Timer 2 Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM2_voidStop(void){
	CLR_BIT(TCCR2_REG,CS22_);
	CLR_BIT(TCCR2_REG,CS21_);
	CLR_BIT(TCCR2_REG,CS20_);
}

/*****************************************************************************
* Function Name: TIM2_voidsetCallback
* Purpose      : Sets the callback from main
* Parameters   : void (*copy_ptr)(void), u8 copy_u8mode
* Return value : void
*****************************************************************************/
void TIM2_voidsetCallback(void (*copy_ptr)(void), u8 copy_u8mode){
	switch(copy_u8mode){
		case OVF_MODE: TIM2_PTR[0] = copy_ptr; break;
		case CTC_MODE: TIM2_PTR[1] = copy_ptr; break;
	}
}

/*****************************************************************************
* Function Name: TIM2_voidFastPWM
* Purpose      : Sets Fast PWM
* Parameters   : u8 copy_u8_duty_cycle
* Return value : void
*****************************************************************************/
void TIM2_voidFastPWM(u8 copy_u8_duty_cycle){
	/* Select Mode */
	SET_BIT(TCCR2_REG,WGM20_);
	SET_BIT(TCCR2_REG,WGM21_);
	
	/* Compare Output Mode */
	SET_BIT(TCCR2_REG,COM21_); // Clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode)
	CLR_BIT(TCCR2_REG,COM20_);
	
	/* Select Prescalar */
	TCCR2_REG &= PRESCALER_MASK;
	TCCR2_REG |= TIM2_PRESCALER;
	
	/* Set Preload Value */
	OCR2_REG = (copy_u8_duty_cycle) * (TIM2_TOP_VAL / 100);
}

void TIM2_voidFastPWMFrequencyAdjust(u8 copy_u8_duty_cycle, u8 frequency){
	/* Select Mode */
	SET_BIT(TCCR2_REG,WGM20_);
	SET_BIT(TCCR2_REG,WGM21_);
	
	/* Compare Output Mode */
	SET_BIT(TCCR2_REG,COM21_); // Clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode)
	CLR_BIT(TCCR2_REG,COM20_);
	
	/* Select Prescalar */
	TCCR2_REG &= PRESCALER_MASK;
	TCCR2_REG |= TIM2_PRESCALER;
	
	/* Set Preload Value */
	OCR2_REG = (copy_u8_duty_cycle) * (frequency / 100);
}


ISR(TIMER2_OVF_){
	if (TIM2_PTR[0] != null)
	{
		TIM2_PTR[0]();
	}
}

ISR(TIMER2_COMP_){
	if (TIM2_PTR[1] != null)
	{
		TIM2_PTR[1]();
	}
}