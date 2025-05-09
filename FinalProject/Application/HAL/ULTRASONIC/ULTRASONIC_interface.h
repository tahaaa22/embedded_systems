/*
 * ULTRASONIC_interface.h
 *
 * Created: 10/11/2024 8:02:19 PM
 *  Author: youss
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIM1/TIM1_interface.h"

/* Delay Library */
#define F_CPU 16000000UL
#include <util/delay.h>


// Define sensor pins
#define US_PORT  DIO_PORTD
#define TRIG	 DIO_PIN0
#define ECHO     DIO_PIN6




u16 ULTRASONIC_u16GetDistance(void);


#endif /* ULTRASONIC_INTERFACE_H_ */