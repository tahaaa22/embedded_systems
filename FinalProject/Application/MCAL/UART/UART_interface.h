/*
 * UART_interface.h
 *
 * Created: 9/27/2024 9:51:27 PM
 *  Author: youss
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/* Section: Includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"

#include "UART_reg.h"
#include "UART_config.h"


/* Section: Macro Declaration */

/* UCSRA - Bits */
#define RXC_       7
#define TXC_	   6
#define UDRE_	   5
#define FE_		   4
#define DOR_	   3
#define PE_		   2
#define U2X_	   1
#define MPCM_	   0

/* UCSRB - Bits */
#define RXCIE_     7 
#define TXCIE_	   6
#define UDRIE_	   5
#define RXEN_	   4
#define TXEN_	   3
#define UCSZ2_	   2
#define RXB8_	   1
#define TXB8_	   0

/* UCSRB - Bits */
#define URSEL_     7
#define UMSEL_	   6
#define UPM1_	   5
#define UPM0_	   4
#define USBS_	   3
#define UCSZ1_	   2
#define UCSZ0_	   1
#define UCPOL_     0

/* Select Mode */
#define MODE       ASYNCHRONOUS_MODE

/* Parity Mode */
#define PARITY      PARITY_DISABLE
#define PARITY_MASK 0b11001111

/* Stop Bit Select */
#define STOP_BIT   STOP_BIT_ONE

/* Character Size */
#define CHAR_SIZE  _8_BITS

/* Baud Rate (bps) */
#define BAUD_RATE_9600BPS  103

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: UART_voidInit
* Purpose      : Initializes UART Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void UART_voidInit(void);

/*****************************************************************************
* Function Name: UART_voidTx
* Purpose      : Transmitter Send Data
* Parameters   : u8 copy_u8data
* Return value : void
*****************************************************************************/
void UART_voidTx(u8 copy_u8data);

/*****************************************************************************
* Function Name: UART_u8Rx
* Purpose      : Receiving Data
* Parameters   : void
* Return value : u8
*****************************************************************************/
u8 UART_u8Rx(void);


#endif /* UART_INTERFACE_H_ */