/*
 * EXTI_reg.h
 *
 * Created: 8/31/2024 10:27:03 PM
 *  Author: youss
 */ 


#ifndef EXTI_REG_H_
#define EXTI_REG_H_

/* Section: Includes */

/* Section: Macro Declaration */

#define  MCUCR_REG   *((volatile u8*)(0x55)) // Reference to Sense Control Register of INT0, INT1
#define  MCUCSR_REG  *((volatile u8*)(0x54)) // Reference to Sense Control Register of INT2

#define  GICR_REG    *((volatile u8*)(0x5B)) // Reference to General Interrupt Control Register

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */


#endif /* EXTI_REG_H_ */