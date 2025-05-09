/*
 * TIM1_prog.c
 *
 * Created: 9/14/2024 8:56:34 PM
 *  Author: youss
 */ 

#include "TIM1_interface.h"

/*****************************************************************************
* Function Name: TIMER1_voidFastPWM10BitRes
* Purpose      : Initializes Fast PWM for Timer 1
* Parameters   : u8 copy_u8pin , u8 copy_u8duty_cycle
* Return value : void
*****************************************************************************/
void TIM1_voidFastPWM10BitRes(u8 copy_u8pin , u8 copy_u8duty_cycle){
	/* Select Mode */
	CLR_BIT(TCCR1B_REG,WGM13_);
	SET_BIT(TCCR1B_REG,WGM12_);
	SET_BIT(TCCR1A_REG,WGM11_);
	SET_BIT(TCCR1A_REG,WGM10_);
	
	/* Select Prescalar */
	TCCR1B_REG &= PRESCALER_MASK;
	TCCR1B_REG |= TIM1_PRESCALER;
	
	/* Compare Output Mode, Fast PWM */
	switch(copy_u8pin){
		case OC1A_PIN: SET_BIT(TCCR1A_REG,COM1A1_); CLR_BIT(TCCR1A_REG,COM1A0_); OCR1AL_REG = copy_u8duty_cycle * (TIM1_TOP_VAL / 100); break;
		case OC1B_PIN: SET_BIT(TCCR1A_REG,COM1B1_); CLR_BIT(TCCR1A_REG,COM1B0_); OCR1BL_REG = copy_u8duty_cycle * (TIM1_TOP_VAL / 100); break;
	}
		
}

/*****************************************************************************
* Function Name: TIM1_voidStart
* Purpose      : Initializes Normal Mode for Timer 1
* Parameters   : u8 copy_u8pin , u8 copy_u8duty_cycle
* Return value : void
*****************************************************************************/
void TIM1_voidStart(void){
	/* Select Mode */
	CLR_BIT(TCCR1B_REG,WGM13_);
	CLR_BIT(TCCR1B_REG,WGM12_);
	CLR_BIT(TCCR1A_REG,WGM11_);
	CLR_BIT(TCCR1A_REG,WGM10_);
	
	/* Select Prescalar */
	TCCR1B_REG &= PRESCALER_MASK;
	TCCR1B_REG |= TIM1_PRESCALER;
}

/*****************************************************************************
* Function Name: TIM1_voidStop
* Purpose      : Stops Timer 1 Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM1_voidStop(void){
	CLR_BIT(TCCR1B_REG,CS12_);
	CLR_BIT(TCCR1B_REG,CS11_);
	CLR_BIT(TCCR1B_REG,CS10_);
}

/*****************************************************************************
* Function Name: TIM1_voidReset
* Purpose      : Resets Timer 1 to zero
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIM1_voidReset(void){
	TCNT1L_REG = 0x0000;
}

/*****************************************************************************
* Function Name: TIM1_u16ReadVal
* Purpose      : Returns Timer 1 value
* Parameters   : void
* Return value : u16
*****************************************************************************/
u16 TIM1_u16ReadVal(void){
	return TCNT1L_REG;
}

/*****************************************************************************
* Function Name: TIM1_voidSetOCRVal
* Purpose      : Returns Timer 1 value
* Parameters   : u16 copy_u16val
* Return value : void
*****************************************************************************/
void TIM1_voidSetOCRVal(u16 copy_u16val){
	OCR1AL_REG = copy_u16val;
}

/*****************************************************************************
* Function Name: TIM1_voidFastPWMICR1
* Purpose      : Fast PWM using ICR1
* Parameters   : f32 copy_u8duty_cycle
* Return value : void
*****************************************************************************/
void TIM1_voidFastPWMICR1(f32 copy_u8duty_cycle){
	/* Select Mode */
	SET_BIT(TCCR1B_REG,WGM13_);
	SET_BIT(TCCR1B_REG,WGM12_);
	SET_BIT(TCCR1A_REG,WGM11_);
	CLR_BIT(TCCR1A_REG,WGM10_);
	
	/* Select Prescalar */
	TCCR1B_REG &= PRESCALER_MASK;
	TCCR1B_REG |= TIM1_PRESCALER;
	
	 /* non inverting */
	SET_BIT(TCCR1A_REG,COM1A1_);
	CLR_BIT(TCCR1A_REG,COM1A0_);
	
	/* Set counter TOP value */
	switch(TIM1_PRESCALER){											     
		case _8PRESCALER_    : ICR1L_REG = (0.02 * 16000000UL) / 8;      ; break;
		case _64PRESCALER_   : ICR1L_REG = (0.02 * 16000000UL) / 64;     ; break;
		case _256PRESCALER_  : ICR1L_REG = (0.02 * 16000000UL) / 256;    ; break;
		case _1024PRESCALER_ : ICR1L_REG = (0.02 * 16000000UL) / 1024;   ; break;
	}

	TIM1_voidSetOCRVal((u16)((copy_u8duty_cycle / 100) * ICR1L_REG));
	
	/* 
	
	Tick Time = presc. / 16000000
	
	ICR = 20ms / Tick Time
	
	OCR = Duty cycle * ICR
	
	
	*/
	
	
}

/*****************************************************************************
* Function Name: TIM1_voidICUDutyCycle
* Purpose      : ICU to Calculate the Duty Cycle between rising and falling edges
* Parameters   : f32 copy_u8duty_cycle
* Return value : void
*****************************************************************************/
void TIM1_voidICUDutyCycle(u16* copy_u16t1 , u16* copy_u16t2){
	
	TCCR1B_REG = 0b11000001; // Rising edge, no prescaler
	while(GET_BIT(TIFR_REG,ICF1_) == 0);
	*copy_u16t1 = ICR1L_REG; /* Take value of capture register */
	SET_BIT(TIFR_REG,ICR1L_REG); /* Clear ICF (Input Capture flag)  */
	TCCR1B_REG = 0b10000001; // Falling edge, no prescaler
	while(GET_BIT(TIFR_REG,ICF1_) == 0);
	*copy_u16t2 = ICR1L_REG; /* Take value of capture register */
	SET_BIT(TIFR_REG,ICF1_); /* Clear ICF (Input Capture flag)  */
}