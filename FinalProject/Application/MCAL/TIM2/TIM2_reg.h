/*
 * TIM2_reg.h
 *
 * Created: 9/27/2024 12:06:21 AM
 *  Author: youss
 */ 


#ifndef TIM2_REG_H_
#define TIM2_REG_H_

#define TCCR2_REG    *((volatile u8*)(0x45)) // Reference to Timer/Counter Interrupt Mask Register
#define TCNT2_REG    *((volatile u8*)(0x44))
#define OCR2_REG     *((volatile u8*)(0x43))
#define ASSR_REG     *((volatile u8*)(0x42))

#define  TIMSK_REG	 *((volatile u8*)(0x59)) // Reference to Timer/Counter Interrupt Mask Register
#define  TIFR_REG	 *((volatile u8*)(0x58)) // Reference to Timer/Counter Interrupt Flag R
#define SFIOR_REG    *((volatile u8*)(0x50)) // Reference to Special Function I/O Register




#endif /* TIM2_REG_H_ */