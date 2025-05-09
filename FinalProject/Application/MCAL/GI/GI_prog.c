/*
 * GI_prog.c
 *
 * Created: 8/31/2024 8:57:12 PM
 * Author: Youssef Bassem
 */

#include "GI_interface.h" 

/*****************************************************************************
* Function Name: GI_voidEnable
* Purpose      : Enables Global Interrupt (GIE)
* Parameters   : void
* Return value : void
*****************************************************************************/
void GI_voidEnable(void){
	SET_BIT(SREG_REG,I_BIT);
}

/*****************************************************************************
* Function Name: GI_voidDisable
* Purpose      : Disables Global Interrupt (GIE)
* Parameters   : void
* Return value : void
*****************************************************************************/
void GI_voidDisable(void){
	CLR_BIT(SREG_REG,I_BIT);
}