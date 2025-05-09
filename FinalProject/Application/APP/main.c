
/* Section: Includes */
#include "main.h"




int main(void) {

	 ///* LCD INIT  */
	 DIO_voidSetPortDir(LCD_DPORT,0xf0)  ;
	 DIO_voidSetPortDir(LCD_CPORT,0x0E) ;  // 00000111
	 LCD_voidInit() ;
	 DIO_voidSetPinDir(DIO_PORTC, DIO_PIN0,INPUT);
	 DIO_voidSetPinVal(DIO_PORTC, DIO_PIN0,OUTPUT);
	 DIO_voidSetPinDir(DIO_PORTC, DIO_PIN1,INPUT);
	 DIO_voidSetPinVal(DIO_PORTC, DIO_PIN1,OUTPUT);
	 DIO_voidSetPinDir(DIO_PORTC, DIO_PIN2,INPUT);
	 DIO_voidSetPinVal(DIO_PORTC, DIO_PIN2,OUTPUT);
	

	while(1){
	
			
	
	}
		
		
			
		
		
	
	
	
}