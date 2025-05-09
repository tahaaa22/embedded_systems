/*
 * ADC_reg.h
 *
 * Created: 9/7/2024 6:33:26 PM
 *  Author: youss
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_

/* Section: Macro Declaration */
#define ADMUX_REG    *((volatile u8*)(0x27))  // Reference to ADC Multiplexer Register
#define ADCSRA_REG   *((volatile u8*)(0x26))  // Reference to ADC Status and Control Register
#define ADC_REG      *((volatile u16*)(0x24)) // Reference to ADC Converted Data Register (ADCL-ADCH)
#define ADCH_REG	 *((volatile u8*)0x25)	  //ADC high register
#define ADCL_REG	 *((volatile u8*)0x24)	  //ADC Low register
#define SFIOR_REG    *((volatile u8*)(0x50))  // Reference to Special Function I/O Register


/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */


#endif /* ADC_REG_H_ */