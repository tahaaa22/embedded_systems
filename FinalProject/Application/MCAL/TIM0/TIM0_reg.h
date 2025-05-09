/*
 * TIM0_reg.h
 *
 * Created: 9/13/2024 8:02:36 PM
 *  Author: youss
 */ 


#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define  TCCR0_REG      *((volatile u8*)(0x53)) // Reference to Timer/Counter Control Register 0
#define  TCNT0_REG      *((volatile u8*)(0x52)) // Reference to Timer/Counter Register 0
#define  TIMSK_REG		*((volatile u8*)(0x59)) // Reference to Timer/Counter Interrupt Mask Register 0
#define  TIFR_REG		*((volatile u8*)(0x58)) // Reference to Timer/Counter Interrupt Flag Register 0
#define  OCR0_REG       *((volatile u8*)(0x5C)) // Reference to Output Compare Register 0

#endif /* TIMER_REG_H_ */