/*
 * WDT_interface.h
 *
 * Created: 9/26/2024 7:03:42 PM
 *  Author: youss
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

/* Section: Includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"

#include "WDT_reg.h"
#include "WDT_config.h"

/* Section: Macro Declaration */

/* WDTCR - Bits */
#define WDTOE_    4
#define WDE_	  3
#define WDP2_	  2
#define WDP1_	  1
#define WDP0_	  0

/* Prescaler */
#define WDT_PRESCALER_MASK  0b11111000  

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: WDT_voidStart
* Purpose      : Initializes Watchdog Timer
* Parameters   : u8 copy_u8time
* Return value : void
*****************************************************************************/
void WDT_voidStart(u8 copy_u8time);

/*****************************************************************************
* Function Name: WDT_voidStop
* Purpose      : Stop Watchdog Timer
* Parameters   : void
* Return value : void
*****************************************************************************/
void WDT_voidStop(void);


#endif /* WDT_INTERFACE_H_ */