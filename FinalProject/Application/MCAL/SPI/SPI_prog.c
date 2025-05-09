/*
 * SPI_prog.c
 *
 * Created: 9/28/2024 10:03:03 PM
 *  Author: youss
 */ 

#include "SPI_interface.h"

/*****************************************************************************
* Function Name: SPI_voidMasterInit
* Purpose      : Initializes SPI - Master Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void SPI_voidMasterInit(void){
	/* Set MOSI and SCK output */
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN4,OUTPUT); // SS
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN5,OUTPUT); // MOSI
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN6,INPUT);  // MISO
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN7,OUTPUT); // SCK
	
	
	/* Select Master */
	SET_BIT(SPCR_REG,MSTR_);
	
	/* set clock rate: Fck / 128 */
	SET_BIT(SPCR_REG,SPR1_);
	SET_BIT(SPCR_REG,SPR0_);
	
	/* Enable SPI */
	SET_BIT(SPCR_REG,SPE_);
	
}

/*****************************************************************************
* Function Name: SPI_voidSlaveInit
* Purpose      : Initializes SPI - Slave Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void SPI_voidSlaveInit(void){
	/* Set MISO and SCK input */
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN4,INPUT);  // SS
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN5,INPUT);  // MOSI
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN6,OUTPUT); // MISO
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN7,INPUT);  // SCK
	
	/* Select Slave */
	CLR_BIT(SPCR_REG,MSTR_);
	
	/* Enable SPI */
	SET_BIT(SPCR_REG,SPE_);
}

/*****************************************************************************
* Function Name: SPI_voidMasterSendData
* Purpose      : Master Send Data
* Parameters   : u8 copy_u8data
* Return value : void
*****************************************************************************/
void SPI_voidMasterSendData(u8 copy_u8data){
	/* Start transmission */
	SPDR_REG = copy_u8data;
	
	/* Wait for transmission complete */
	while(GET_BIT(SPSR_REG,SPIF_) == 0);
}

/*****************************************************************************
* Function Name: SPI_u8SlaveReceiveData
* Purpose      : Slave Receive Data
* Parameters   : void
* Return value : u8
*****************************************************************************/
u8 SPI_u8SlaveReceiveData(void){
	/* Wait for reception complete */
	while(GET_BIT(SPSR_REG,SPIF_) == 0);
	
	/* Return data register */
	return SPDR_REG;
}