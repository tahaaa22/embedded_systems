/*
 * UART_reg.h
 *
 * Created: 9/27/2024 9:52:40 PM
 *  Author: youss
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_

#define UDR_REG      *((volatile u8*)(0x2C)) // Reference to USART I/O Data Register
#define UCSRA_REG    *((volatile u8*)(0x2B)) // Reference to USART Control and Status Register A
#define UCSRB_REG    *((volatile u8*)(0x2A)) // Reference to USART Control and Status Register B
#define UCSRC_REG    *((volatile u8*)(0x40)) // Reference to USART Control and Status Register C
#define UBRRH_REG    *((volatile u8*)(0x40)) // Reference USART Baud Rate Registers High-Byte
#define UBRRL_REG    *((volatile u8*)(0x29)) // Reference USART Baud Rate Registers Low-Byte






#endif /* UART_REG_H_ */