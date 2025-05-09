/*
 * TIM1_reg.h
 *
 * Created: 9/14/2024 8:55:33 PM
 *  Author: youss
 */ 


#ifndef TIM1_REG_H_
#define TIM1_REG_H_

#define  TCCR1A_REG    *((volatile u8*)(0x4F)) // Reference to Timer/Counter1 Control Register A
#define  TCCR1B_REG    *((volatile u8*)(0x4E)) // Reference to Timer/Counter1 Control Register B
#define  TIMSK_REG	   *((volatile u8*)(0x59)) // Reference to Timer/Counter Interrupt Mask Register 
#define  TIFR_REG	   *((volatile u8*)(0x58)) // Reference to Timer/Counter Interrupt Flag Register 


#define  TCNT1L_REG    *((volatile u16*)(0x4E)) // Reference to Timer/Counter1 – Counter Register Low Byte
#define  OCR1AL_REG    *((volatile u16*)(0x4A)) // Reference to Timer/Counter1 – Output Compare Register A Low Byte 
#define  OCR1BL_REG    *((volatile u16*)(0x48)) // Reference to Timer/Counter1 – Output Compare Register B Low Byte 
#define  ICR1L_REG     *((volatile u16*)(0x46)) // Reference to Input Capture Register Low Byte 





#endif /* TIM1_REG_H_ */