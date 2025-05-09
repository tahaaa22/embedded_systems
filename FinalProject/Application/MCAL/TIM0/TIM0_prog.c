/*
 * TIM0_prog.c
 *
 * Created: 9/13/2024 8:03:09 PM
 *  Author: youss
 */ 

#include "TIM0_interface.h"

/* Global Pointer To Function for callback */
void (*TIM0_PTR[2])(void) = {null};

/*****************************************************************************
* Function Name: TIM0_voidInit
* Purpose      : Initializes Timer 0 Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM0_voidInit(void){
	
	/* Select Mode */
	#if TIM0_MODE == OVF_MODE
	CLR_BIT(TCCR0_REG,WGM01_);
	CLR_BIT(TCCR0_REG,WGM00_);
	SET_BIT(TIMSK_REG,TOIE0_); // Overflow Interrupt Enable
	#elif TIM0_MODE == CTC_MODE
	SET_BIT(TCCR0_REG,WGM01_);
	CLR_BIT(TCCR0_REG,WGM00_);
	SET_BIT(TIMSK_REG,OCIE0_); // Output Compare Match Interrupt Enable
	OCR0_REG = OCR_VAL;
	#endif
	
	/* Select Prescalar */
	TCCR0_REG &= PRESCALER_MASK;
	TCCR0_REG |= TIM0_PRESCALER;
	
}

/*****************************************************************************
* Function Name: TIM0_voidStop
* Purpose      : Stops Timer 0 Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM0_voidStop(void){
	CLR_BIT(TCCR0_REG,CS02_);
	CLR_BIT(TCCR0_REG,CS01_);
	CLR_BIT(TCCR0_REG,CS00_);
}

/*****************************************************************************
* Function Name: TIM0_setCallback
* Purpose      : Sets the callback from main
* Parameters   : void (*copy_ptr)(void), u8 copy_u8mode
* Return value : void
*****************************************************************************/
void TIM0_voidsetCallback(void (*copy_ptr)(void), u8 copy_u8mode){
	switch(copy_u8mode){
		case OVF_MODE: TIM0_PTR[0] = copy_ptr; break;
		case CTC_MODE: TIM0_PTR[1] = copy_ptr; break;
	}
}


/*****************************************************************************
* Function Name: TIM0_voidFastPWM
* Purpose      : Sets Fast PWM
* Parameters   : u8 copy_u8_duty_cycle
* Return value : void
*****************************************************************************/
void TIM0_voidFastPWM(u8 copy_u8_duty_cycle){
	/* Select Mode */
	SET_BIT(TCCR0_REG,WGM00_);
	SET_BIT(TCCR0_REG,WGM01_);
	
	/* Compare Output Mode */
	SET_BIT(TCCR0_REG,COM01_); // Clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode)
	CLR_BIT(TCCR0_REG,COM00_);
	
	/* Select Prescalar */
	TCCR0_REG &= PRESCALER_MASK;
	TCCR0_REG |= TIM0_PRESCALER;
	
	/* Set Preload Value */
	OCR0_REG = (copy_u8_duty_cycle) * (TIM0_TOP_VAL / 100);
}

ISR(TIMER0_OVF_){
	if (TIM0_PTR[0] != null)
	{
		TIM0_PTR[0]();
	}
}

ISR(TIMER0_COMP_){
	if (TIM0_PTR[1] != null)
	{
		TIM0_PTR[1]();
	}
}