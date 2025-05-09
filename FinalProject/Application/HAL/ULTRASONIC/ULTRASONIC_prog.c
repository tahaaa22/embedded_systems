/*
 * ULTRASONIC_prog.c
 *
 * Created: 10/11/2024 8:03:18 PM
 *  Author: youss
 */ 

#include "ULTRASONIC_interface.h"

u16 ULTRASONIC_u16GetDistance(void){
	

	
	/* Clear ICF (Input Capture flag)  */
	SET_BIT(TIFR_REG,ICR1L_REG);
	
	// Configure TRIG as output and ECHO as input
	DIO_voidSetPinDir(DIO_PORTA, TRIG, OUTPUT);
	DIO_voidSetPinDir(US_PORT, ECHO, INPUT);


	// Send a 10us pulse to TRIG
	DIO_voidSetPinVal(DIO_PORTA, TRIG, HIGH);
	_delay_us(10);
	DIO_voidSetPinVal(DIO_PORTA, TRIG, LOW);


	// Start measuring echo pulse duration
	u16 t1 = 0,t2 = 0;
	TIM1_voidICUDutyCycle(&t1,&t2);
	
	// Stop Timer
	TIM1_voidReset();
	TIM1_voidStop(); 
	
	u16 Ton = t2 - t1;

	// Calculate distance in centimeters using integer arithmetic
	u16 distance = ((Ton * 34600) / (F_CPU * 2)); // 25°C
	
	if (distance >= 50)
	{
		return 50;
	}
	
	return distance;
	
	
}