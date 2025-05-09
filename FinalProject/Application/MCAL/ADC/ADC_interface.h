/*
 * ADC_interface.h
 *
 * Created: 9/7/2024 6:47:33 PM
 *  Author: youss
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/* Section: Includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/interrupt_vector.h"
#include "ADC_reg.h"
#include "ADC_config.h"

/* Section: Macro Declaration */

/* ADC Enable */



/* ADMUX Bits */
#define REFS1_    7 //Reference selection bit1
#define REFS0_    6 //Reference selection bit0
#define ADLAR_    5 //ADC left adjust result

/* ADCSRA Bits */
#define ADEN_     7 //ADC enable
#define ADSC_     6 //Start conversion 
#define ADATE_    5 //Auto trigger enable
#define ADIF_     4 //Interrupt flag
#define ADIE_     3 //Interrupt enable
#define ADPS2_	  2 //Prescaler bit2
#define ADPS1_	  1 //Prescaler bit1
#define ADPS0_	  0 //Prescaler bit0

/* SFIOR Bits */
#define  ADTS0_   5 //Trigger Source bit0
#define  ADTS1_   6//Trigger Source bit1
#define  ADTS2_   7 //Trigger Source bit2

/* Bit Masking Macros  */
#define ADC_PRE_MASK	0b11111000
#define ADC_CH_MASK		0b11100000

/* Division Factor */
#define ADC_PRESCALLER _128PRESCALER


/* Trigger Source */
#define ADC_TRIGGER_MODE  Free_Running_mode

/* ADC Interrupt Enable */
#define INT_STATUS   INT_ENABLE


/* Interrupt Flag */
#define ADC_POLLING   0
#define ADC_INTERRUPT 1

#define ADC_INT       ADC_POLLING
 
 

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */


/*****************************************************************************
* Function Name: ADC_voidInit
* Purpose      : Initializes ADC Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void ADC_voidInit(void);

/*****************************************************************************
* Function Name: ADC_u16ReadChannel
* Purpose      : Gets the Converted analog signal
* Parameters   : copy_u8channel
* Return value : u16
*****************************************************************************/
u16 ADC_u16ReadChannel(u8 copy_u8channel);



void ADC_voidSetCallback(u8 copy_u8channel,u16* Copy_u16Result,void (*copy_ADC_INT_PTR)(void));


#endif /* ADC_INTERFACE_H_ */