/*
 * DIO_reg.h
 *
 * Created: 8/17/2024 7:39:04 PM
 * Author:  Ahmed taha
 */ 


#ifndef DIO_REG_H_
#define DIO_REG_H_

/* Section: Macro Declaration */

/* Group A*/
#define PORTA_REG		*((volatile u8* )0x3B) /* Reference to Data Registers (Read/Write) */
#define DDRA_REG		*((volatile u8* )0x3A) /* Reference to Data Direction Control Registers (Read/Write) */
#define PINA_REG		*((volatile u8* )0x39) /* Reference to Pin Status Registers (Read Only)*/

/* Group B*/
#define PORTB_REG		*((volatile u8* )0x38) /* Reference to Data Registers (Read/Write) */
#define DDRB_REG		*((volatile u8* )0x37) /* Reference to Data Direction Control Registers (Read/Write) */
#define PINB_REG		*((volatile u8* )0x36) /* Reference to Pin Status Registers (Read Only)*/

/* Group C*/
#define PORTC_REG		*((volatile u8* )0x35) /* Reference to Data Registers (Read/Write) */
#define DDRC_REG		*((volatile u8* )0x34) /* Reference to Data Direction Control Registers (Read/Write) */
#define PINC_REG		*((volatile u8* )0x33) /* Reference to Pin Status Registers (Read Only)*/

/* Group D*/
#define PORTD_REG		*((volatile u8* )0x32) /* Reference to Data Registers (Read/Write) */
#define DDRD_REG		*((volatile u8* )0x31) /* Reference to Data Direction Control Registers (Read/Write) */
#define PIND_REG		*((volatile u8* )0x30) /* Reference to Pin Status Registers (Read Only)*/



/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */



#endif /* DIO_REG_H_ */