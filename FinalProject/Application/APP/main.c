/*
 * main.c
 *
 * Created: 8/17/2024 7:08:28 PM
 * Author : Youssef Bassem
 */ 

/* Section: Includes */
#include "main.h"




int main(void) {


	DC_MOTOR_voidCW(70);

	while(1){
		u16 dist = ULTRASONIC_u16GetDistance();

		_delay_ms(100);
		if (dist < 10)
		{

			
	
			LED_voidOn(DIO_PORTC,DIO_PIN2);
		}else{
			
			LED_voidOff(DIO_PORTC,DIO_PIN2);
		}
			
	
	}
		
		
			
		
		
	
	
	
}