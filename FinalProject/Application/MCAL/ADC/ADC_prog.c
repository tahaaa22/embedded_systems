/*
 * ADC_prog.c
 *
 * Created: 9/7/2024 6:47:52 PM
 *  Author: youss
 */ 
#include "ADC_interface.h"


/*Global pointer to function to carry the function called by ISR*/
static void (*ADC_INT_PTR)(void) = null;

/*Global pointer to carry the conversion result in the Interrupt execution*/
static u16* ADC_u16Result = null;

/*****************************************************************************
* Function Name: ADC_voidInit
* Purpose      : Initializes ADC Peripheral
* Parameters   : void
* Return value : void
*****************************************************************************/
void ADC_voidInit(void){
	/* Reference Voltage Selection */
	CLR_BIT(ADMUX_REG,REFS1_);   // AVCC with external capacitor at AREF pin
	SET_BIT(ADMUX_REG,REFS0_);   // AVCC with external capacitor at AREF pin
							     
	/* Right Adjust Result Register */     
	CLR_BIT(ADMUX_REG,ADLAR_);   // Right Adjustment
							     
	/* ADC Prescaler Select */   
	ADCSRA_REG &= ADC_PRE_MASK;    // Clear ADPS[2:0]
	ADCSRA_REG |= ADC_PRESCALLER;  // Set ADPS[2:0] to corresponding Division factor
	
	
	
	/* ADC Enable */
	SET_BIT(ADCSRA_REG,ADEN_); 
	
	/*Enable ADC Interrupt*/
	#if INT_STATUS == INT_DISABLE
		CLR_BIT(ADCSRA_REG,ADIE_);
	#elif INT_STATUS == INT_ENABLE  // INTERRUPT ENABLED
		/* Enable Auto Trigger and set Free Running Mode */
		SET_BIT(ADCSRA_REG, ADATE_);   // Enable Auto Trigger
		SFIOR_REG &= 0b00001111;       // Clear ADTS[7:5] bits
		SFIOR_REG |= (ADC_TRIGGER_MODE << 5); // Sets ADTS[7:5] to corresponding Input channel
		SET_BIT(ADCSRA_REG,ADIE_);
	#endif
}

/*****************************************************************************
* Function Name: ADC_u16ReadChannel
* Purpose      : Gets the Converted analog signal
* Parameters   : copy_u8channel
* Return value : u16
*****************************************************************************/
u16 ADC_u16ReadChannel(u8 copy_u8channel){
	/* Analog Channel and Gain Selection Bits */
	ADMUX_REG &= ADC_CH_MASK;     // Clears MUX[4:0]
	ADMUX_REG |= copy_u8channel; // Sets MUX[4:0] to corresponding Input channel
	
	/* ADC Start Conversion */
	SET_BIT(ADCSRA_REG,ADSC_);		
	while(GET_BIT(ADCSRA_REG,ADIF_) == 0); // Wait until ADIF rises a flag when Conversion is finished
	
 	/*Clear the interrupt flag*/
	SET_BIT(ADCSRA_REG,ADIF_); 
	
	return ADC_REG; 
}


void ADC_voidSetCallback(u8 copy_u8channel,u16* Copy_u16Result,void (*copy_ADC_INT_PTR)(void)){
	/*Initialize the global result pointer*/
	ADC_u16Result = Copy_u16Result;
	
	/*Initialize the global notification function pointer*/
	ADC_INT_PTR = copy_ADC_INT_PTR; 
	
	
	/* Analog Channel and Gain Selection Bits */
	ADMUX_REG &= ADC_CH_MASK;     // Clears MUX[4:0]
	ADMUX_REG |= copy_u8channel; // Sets MUX[4:0] to corresponding Input channel
	
 	/* ADC Start Conversion */
 	SET_BIT(ADCSRA_REG,ADSC_);
	
	/*ADC Conversion Complete Interrupt Enable*/
	SET_BIT(ADCSRA_REG,ADIE_);
		
}

ISR(ADC_INT_){
	if(ADC_INT_PTR != null){
		/*Return Conversion Result*/
		*ADC_u16Result = ADC_REG;
		
		/*Call Pointer to Function*/
		ADC_INT_PTR();
		
		/*Disable the Conversion Complete Interrupt*/
		CLR_BIT(ADCSRA_REG,ADIE_);
		
	}
}