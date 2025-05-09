/*
 * EXTI_prog.c
 *
 * Created: 8/31/2024 10:27:22 PM
 *  Author: youss
 */ 

#include "EXTI_interface.h"


/* Array of Pointer to functions for callback functions in ISR */
void (*INT_PTR[EXTI_NUM])(void) = {null}; 


/*****************************************************************************
* Function Name: EXTI_voidInit
* Purpose      : Initializes EXT INT
* Parameters   : u8 copy_u8interrupt_num , u8 copy_u8sense
* Return value : void
*****************************************************************************/
void EXTI_voidInit(u8 copy_u8interrupt_num,u8 copy_u8sense){
	switch(copy_u8interrupt_num){
		case INT0_:
			switch(copy_u8sense){
				case LOW_LEVEL: CLR_BIT(MCUCR_REG,ISC00); CLR_BIT(MCUCR_REG,ISC01);          break;
				case ANY_LOGICAL_CHANGE: SET_BIT(MCUCR_REG,ISC00); CLR_BIT(MCUCR_REG,ISC01); break;
				case FALLING_EDGE: CLR_BIT(MCUCR_REG,ISC00); SET_BIT(MCUCR_REG,ISC01);       break;
				case RISING_EDGE: SET_BIT(MCUCR_REG,ISC00); SET_BIT(MCUCR_REG,ISC01);        break;
				default:                                                                     break; //Invalid Sense
			}
			break;
		case INT1_:
			switch(copy_u8sense){
				case LOW_LEVEL: CLR_BIT(MCUCR_REG,ISC10); CLR_BIT(MCUCR_REG,ISC11);          break;
				case ANY_LOGICAL_CHANGE: SET_BIT(MCUCR_REG,ISC10); CLR_BIT(MCUCR_REG,ISC11); break;
				case FALLING_EDGE: CLR_BIT(MCUCR_REG,ISC10); SET_BIT(MCUCR_REG,ISC11);       break;
				case RISING_EDGE: SET_BIT(MCUCR_REG,ISC10); SET_BIT(MCUCR_REG,ISC11);        break;
				default:                                                                     break; //Invalid Sense
			}
			break;
		case INT2_:
			switch(copy_u8sense){
				case FALLING_EDGE: CLR_BIT(MCUCSR_REG,ISC2);							     break;
				case RISING_EDGE: SET_BIT(MCUCSR_REG,ISC2);			      				     break;
				default:                                                                     break; //Invalid Sense
			}
			break;
		default:
			// Invalid INT number
			break;
	}
}

/*****************************************************************************
* Function Name: EXTI0_voidEnable
* Purpose      : INT0 Enable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI0_voidEnable(void){
	SET_BIT(GICR_REG,GICR_INT0);
}

/*****************************************************************************
* Function Name: EXTI0_voidDisable
* Purpose      : INT0 Disable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI0_voidDisable(void){
	CLR_BIT(GICR_REG,GICR_INT0);
}

/*****************************************************************************
* Function Name: EXTI1_voidEnable
* Purpose      : INT1 Enable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI1_voidEnable(void){
	SET_BIT(GICR_REG,GICR_INT1);
}

/*****************************************************************************
* Function Name: EXTI1_voidDisable
* Purpose      : INT1 Disable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI1_voidDisable(void){
	CLR_BIT(GICR_REG,GICR_INT1);
}

/*****************************************************************************
* Function Name: EXTI2_voidEnable
* Purpose      : INT2 Enable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI2_voidEnable(void){
	SET_BIT(GICR_REG,GICR_INT2);
}

/*****************************************************************************
* Function Name: EXTI2_voidDisable
* Purpose      : INT2 Disable
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXTI2_voidDisable(void){
	CLR_BIT(GICR_REG,GICR_INT2);
}

/*****************************************************************************
* Function Name: EXTI_voidSetCallback
* Purpose      : Stores the address of the function passed in the main to be called in the ISR
* Parameters   : void (*copy_ptr)(void), u8 copy_u8interrupt_num
* Return value : void
*****************************************************************************/
void EXTI_voidSetCallback(void (*copy_ptr)(void),u8 copy_u8interrupt_num){
	switch(copy_u8interrupt_num){
		case INT0_: INT_PTR[INT0_] = copy_ptr;break;
		case INT1_: INT_PTR[INT1_] = copy_ptr;break;
		case INT2_: INT_PTR[INT2_] = copy_ptr;break;
		default:                              break;
	}
}


ISR(INT_0_){
	INT_PTR[INT0_]();
}

ISR(INT_1_){
	INT_PTR[INT1_]();
}

ISR(INT_2_){
	INT_PTR[INT2_]();
}