/*
 * UART_config.h
 *
 * Created: 9/27/2024 9:52:22 PM
 *  Author: youss
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/* Section: Macro Declaration */

/* Select Mode */
#define ASYNCHRONOUS_MODE   0
#define SYNCHRONOUS_MODE    1

/* Parity Mode */
#define PARITY_DISABLE      0
#define PARITY_RESERVED     1
#define PARITY_EVEN         2
#define PARITY_ODD          3

/* Stop Bit Select */
#define STOP_BIT_ONE        0
#define STOP_BIT_TWO        1

/* Character Size */
#define  _5_BITS            0
#define  _6_BITS            1
#define  _7_BITS            2
#define  _8_BITS            3
#define  _9_BITS            7










#endif /* UART_CONFIG_H_ */