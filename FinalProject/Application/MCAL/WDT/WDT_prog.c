/*
 * WDT_prog.c
 *
 * Created: 9/26/2024 7:04:16 PM
 *  Author: youss
 */ 

#include "WDT_interface.h"

/*****************************************************************************
* Function Name: WDT_voidStart
* Purpose      : Initializes Watchdog Timer
* Parameters   : u8 copy_u8time
* Return value : void
*****************************************************************************/
void WDT_voidStart(u8 copy_u8time){
	/* Watchdog Enable */
	SET_BIT(WDTCR_REG,WDE_);
	
	/* Watchdog Timer Prescaler Select */
	WDTCR_REG &= WDT_PRESCALER_MASK;
	WDTCR_REG |= copy_u8time;
	
}

/*****************************************************************************
* Function Name: WDT_voidStop
* Purpose      : Stop Watchdog Timer
* Parameters   : void
* Return value : void
*****************************************************************************/
void WDT_voidStop(void){
	/* Write logical one to WDTOE and WDE */
	WDTCR_REG |= (1<<WDTOE_) | (1<<WDE_);
	/* Turn off WDT */
	WDTCR_REG = 0x00;
}