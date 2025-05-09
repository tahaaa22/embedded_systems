/*
 * interrupt_vector.h
 *
 * Created: 9/6/2024 7:51:16 PM
 *  Author: youss
 */ 


#ifndef INTERRUPT_VECTOR_H_
#define INTERRUPT_VECTOR_H_


#define ISR(__vector_NUM)  void __vector_NUM(void) __attribute__ ((signal));\
						   void __vector_NUM(void)
						   


#define INT_0_           __vector_1
#define INT_1_           __vector_2
#define INT_2_           __vector_3
#define TIMER2_COMP_     __vector_4
#define TIMER2_OVF_      __vector_5
#define TIMER1_CAPT_     __vector_6
#define TIMER1_COMPA_    __vector_7
#define TIMER1_COMPB_    __vector_8
#define TIMER1_OVF       __vector_9
#define TIMER0_COMP_     __vector_10
#define TIMER0_OVF_      __vector_11
#define SPI_STC_         __vector_12
#define USART_RXC_       __vector_13
#define USART_UDRE_      __vector_14
#define USART_TXC_       __vector_15
#define ADC_INT_         __vector_16
     








#endif /* INTERRUPT_VECTOR_H_ */