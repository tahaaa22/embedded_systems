/*
 * GI_interface.h
 *
 * Created: 8/31/2024 8:56:57 PM
 * Author: Ahmed taha
 */ 


#ifndef GI_INTERFACE_H_
#define GI_INTERFACE_H_

/* Section: Includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "GI_reg.h"

/* Section: Macro Declaration */

#define   I_BIT   7 // I-Bit in SREG

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: GI_voidEnable
* Purpose      : Enables Global Interrupt (GIE)
* Parameters   : void
* Return value : void
*****************************************************************************/
void GI_voidEnable(void);

/*****************************************************************************
* Function Name: GI_voidDisable
* Purpose      : Disables Global Interrupt (GIE)
* Parameters   : void
* Return value : void
*****************************************************************************/
void GI_voidDisable(void);


#endif /* GI_INTERFACE_H_ */