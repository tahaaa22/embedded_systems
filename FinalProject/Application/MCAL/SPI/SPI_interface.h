/*
 * SPI_interface.h
 *
 * Created: 9/28/2024 10:02:26 PM
 *  Author: youss
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/* Section: Includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../DIO/DIO_interface.h"

#include "SPI_reg.h"
#include "SPI_config.h"

/* Section: Macro Declaration */

/* SPCR - Bits */
#define SPIE_      7  
#define SPE_	   6
#define DORD_	   5
#define MSTR_	   4
#define CPOL_	   3
#define CPHA_	   2
#define SPR1_	   1
#define SPR0_	   0

/* SPSR - Bits */
#define SPIF_      7
#define WCOL_      6
#define SPI2X_     0

/* SPSR - Bits */
#define MSB_       7
#define LSB_       0

/* Section: Function Declaration */

/*****************************************************************************
* Function Name: SPI_voidMasterInit
* Purpose      : Initializes SPI - Master Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void SPI_voidMasterInit(void);

/*****************************************************************************
* Function Name: SPI_voidSlaveInit
* Purpose      : Initializes SPI - Slave Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void SPI_voidSlaveInit(void);

/*****************************************************************************
* Function Name: SPI_voidMasterSendData
* Purpose      : Master Send Data
* Parameters   : u8 copy_u8data
* Return value : void
*****************************************************************************/
void SPI_voidMasterSendData(u8 copy_u8data);

/*****************************************************************************
* Function Name: SPI_u8SlaveReceiveData
* Purpose      : Slave Receive Data
* Parameters   : void
* Return value : u8
*****************************************************************************/
u8 SPI_u8SlaveReceiveData(void);

#endif /* SPI_INTERFACE_H_ */