/*
 * UART_prog.c
 *
 * Created: 9/27/2024 9:52:53 PM
 *  Author: youss
 */ 

#include "UART_interface.h"

/*****************************************************************************
* Function Name: UART_voidInit
* Purpose      : Initializes UART Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void UART_voidInit(void){
	/* Baud Rate (bps) */
	UBRRL_REG = BAUD_RATE_9600BPS;
	
	/* USART Mode Select */
	#if MODE == ASYNCHRONOUS_MODE
	CLR_BIT(UCSRC_REG,UMSEL_);
	#elif MODE == SYNCHRONOUS_MODE
	SET_BIT(UCSRC_REG,UMSEL_);
	#endif
	
	/* Parity Mode */
	UCSRC_REG &= PARITY_MASK;
	UCSRC_REG |= PARITY;
	
	/* Stop Bit Select */
	#if STOP_BIT == STOP_BIT_ONE
	CLR_BIT(UCSRC_REG,USBS_);
	#elif STOP_BIT == STOP_BIT_TWO
	SET_BIT(UCSRC_REG,USBS_);
	#endif
	
	/* Character Size */
	UCSRC_REG |= (1<<URSEL_) | (1<<UCSZ1_) | (1<<UCSZ0_);
	
	
	/* Receiver Enable */
	SET_BIT(UCSRB_REG,RXEN_);
	
	/* Transmitter Enable */
	SET_BIT(UCSRB_REG,TXEN_);
	
}

/*****************************************************************************
* Function Name: UART_voidTx
* Purpose      : Transmitter Send Data
* Parameters   : u8 copy_u8data
* Return value : void
*****************************************************************************/
void UART_voidTx(u8 copy_u8data){
	/* Wait for empty transmit buffer */
	while ( !(	UCSRA_REG & (1<<UDRE_)) );
	
	/* Put data into buffer, sends the data */
	UDR_REG = copy_u8data;
}

/*****************************************************************************
* Function Name: UART_u8Rx
* Purpose      : Receiving Data
* Parameters   : void
* Return value : u8
*****************************************************************************/
u8 UART_u8Rx(void){
	/* Wait for data to be received */
	while ( !(UCSRA_REG & (1<<RXC_)) );
	
	/* Get and return received data from buffer */
	return UDR_REG;
}