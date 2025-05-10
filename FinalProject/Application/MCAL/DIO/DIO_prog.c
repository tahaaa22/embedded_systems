/*
 * DIO_prog.c
 *
 * Created: 8/17/2024 7:39:42 PM
 *  Author: Ahmed taha
 */ 


#include "DIO_interface.h"

/*********************** Pin Functions Implementation ***********************/

/*****************************************************************************
* Function Name: DIO_voidSetPinDir
* Purpose      : set pin dir (OUTPUT , INPUT)
* Parameters   : copy_u8port, u8 copy_u8pin , u8 copy_u8dir
* Return value : void
*****************************************************************************/
void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin , u8 copy_u8dir){
	if (copy_u8dir == OUTPUT || copy_u8dir == INPUT)
	{
		if(copy_u8dir == OUTPUT){
			switch(copy_u8port){
				case DIO_PORTA: SET_BIT(DDRA_REG,copy_u8pin); break;
				case DIO_PORTB:	SET_BIT(DDRB_REG,copy_u8pin); break;
				case DIO_PORTC:	SET_BIT(DDRC_REG,copy_u8pin); break;
				case DIO_PORTD: SET_BIT(DDRD_REG,copy_u8pin); break;
				default:                                      break; //do nothing (Invalid Port)
			}							
		}else if(copy_u8dir == INPUT){	
			switch(copy_u8port){		
				case DIO_PORTA: CLR_BIT(DDRA_REG,copy_u8pin); break;
				case DIO_PORTB:	CLR_BIT(DDRB_REG,copy_u8pin); break;
				case DIO_PORTC:	CLR_BIT(DDRC_REG,copy_u8pin); break;
				case DIO_PORTD: CLR_BIT(DDRD_REG,copy_u8pin); break;
				default:                                      break; //do nothing (Invalid Port)
			}
		}else{
			//do nothing (Invalid Direction)
		}
	}else{
		//do nothing (Invalid Direction)
	}
}


/*****************************************************************************
* Function Name: DIO_voidSetPinVal
* Purpose      : set pin value  (HIGH , LOW)
* Parameters   : copy_u8port, u8 copy_u8pin , u8 copy_u8dir
* Return value : void
*****************************************************************************/
void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin , u8 copy_u8val){
	if (copy_u8val == HIGH || copy_u8val == LOW)
	{
		if(copy_u8val == HIGH){
			switch(copy_u8port){
				case DIO_PORTA: SET_BIT(PORTA_REG,copy_u8pin); break;
				case DIO_PORTB:	SET_BIT(PORTB_REG,copy_u8pin); break;
				case DIO_PORTC:	SET_BIT(PORTC_REG,copy_u8pin); break;
				case DIO_PORTD: SET_BIT(PORTD_REG,copy_u8pin); break;
				default:                                       break; //do nothing (Invalid Port)
			}
		}else if(copy_u8val == LOW){
			switch(copy_u8port){
				case DIO_PORTA: CLR_BIT(PORTA_REG,copy_u8pin); break;
				case DIO_PORTB:	CLR_BIT(PORTB_REG,copy_u8pin); break;
				case DIO_PORTC:	CLR_BIT(PORTC_REG,copy_u8pin); break;
				case DIO_PORTD: CLR_BIT(PORTD_REG,copy_u8pin); break;
				default:                                       break; //do nothing (Invalid Port)
			}
		}else{
			//do nothing (Invalid Direction)
		}
	}else{
		//do nothing (Invalid Direction)
	}
}


/*****************************************************************************
* Function Name: DIO_voidTogglePinVal
* Purpose      : toggle pin val
* Parameters   : copy_u8port, u8 copy_u8pin
* Return value : void
*****************************************************************************/
void DIO_voidTogglePinVal(u8 copy_u8port, u8 copy_u8pin ){
	switch(copy_u8port){
		case DIO_PORTA: TOGGLE_BIT(PORTA_REG,copy_u8pin); break;
		case DIO_PORTB:	TOGGLE_BIT(PORTB_REG,copy_u8pin); break;
		case DIO_PORTC:	TOGGLE_BIT(PORTC_REG,copy_u8pin); break;
		case DIO_PORTD: TOGGLE_BIT(PORTD_REG,copy_u8pin); break;
		default:                                          break; //do nothing (Invalid Port)
	}
}


/*****************************************************************************
* Function Name: DIO_u8ReadPinVal
* Purpose      : reads pin val
* Parameters   : copy_u8port, u8 copy_u8pin
* Return value : u8
*****************************************************************************/
u8 DIO_u8ReadPinVal(u8 copy_u8port, u8 copy_u8pin){
	u8 LOC_u8val = -1;
	switch(copy_u8port){
		case DIO_PORTA:LOC_u8val = (u8)GET_BIT(PINA_REG,copy_u8pin); break;
		case DIO_PORTB:LOC_u8val = (u8)GET_BIT(PINB_REG,copy_u8pin); break;
		case DIO_PORTC:LOC_u8val = (u8)GET_BIT(PINC_REG,copy_u8pin); break;
		case DIO_PORTD:LOC_u8val = (u8)GET_BIT(PIND_REG,copy_u8pin); break;
		default:                                                     break; //do nothing (Invalid Port)
	}
	return LOC_u8val;
}

/*********************** Port Functions Implementation ***********************/

/*****************************************************************************
* Function Name: DIO_voidSetPortDir
* Purpose      : Sets Port(All Pins) Dir
* Parameters   : u8 copy_u8port, u8 copy_u8dir
* Return value : void
*****************************************************************************/
void DIO_voidSetPortDir(u8 copy_u8port, u8 copy_u8dir){
	switch(copy_u8port){
		case DIO_PORTA:  DDRA_REG = copy_u8dir; break;
		case DIO_PORTB:	 DDRB_REG = copy_u8dir; break;
		case DIO_PORTC:	 DDRC_REG = copy_u8dir; break;
		case DIO_PORTD:  DDRD_REG = copy_u8dir; break;
		default:                                break; //do nothing (Invalid Port)
	}
}


/*****************************************************************************
* Function Name: DIO_voidSetPortDir
* Purpose      : Sets Port(All Pins) Val
* Parameters   : u8 copy_u8port, u8 copy_u8val
* Return value : void
*****************************************************************************/
void DIO_voidSetPortVal(u8 copy_u8port, u8 copy_u8val){
	switch(copy_u8port){
		case DIO_PORTA:  PORTA_REG = copy_u8val; break;
		case DIO_PORTB:	 PORTB_REG = copy_u8val; break;
		case DIO_PORTC:	 PORTC_REG = copy_u8val; break;
		case DIO_PORTD:  PORTD_REG = copy_u8val; break;
		default:                                 break; //do nothing (Invalid Port)
	}
}



