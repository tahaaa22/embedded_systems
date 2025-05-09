#include "main.h"

// Keypad setup function
void KeypadSetup(void) {
	// Set keypad column pins (e.g., PC1–PC3) as input
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN1, INPUT);
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN2, INPUT);
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN3, INPUT);

	// Initialize keypad
	KEYPAD_voidInit();
}

// LCD setup function
void LCDSetup(void) {
	// Set LCD data port (e.g., PORTD) upper nibble as output
	DIO_voidSetPortDir(LCD_DPORT, 0xF0); // Upper nibble as output

	// Set LCD control pins (e.g., RS=P1, RW=P2, EN=P3) as output
	DIO_voidSetPortDir(LCD_CPORT, 0x0E);

	// Initialize LCD
	LCD_voidInit();

	// Set row pins (PC0–PC3) as output for keypad (if needed)
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN0, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN1, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN2, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN3, OUTPUT);
}

void start(void)
{
	
	LCD_voidClearScreen();
	LCD_voidGoto(0, 0);
	LCD_voidSendString("Welcome Dr");
	_delay_ms(1000);
	LCD_voidClearScreen();
	LCD_voidGoto(0, 0);
	LCD_voidSendString("Manual test: 0");
	LCD_voidGoto(0, 1);
	LCD_voidSendString("Auto test: 1");
	
}

// Function to show welcome message and wait for test mode selection
void WelcomeMessage(void) 
{
	
		start();

		while (1) 
		{
			
			u8 key = KEYPAD_u8GetKey();

			if (key == 0)
			 {
				LCD_voidClearScreen();
				LCD_voidGoto(0, 0);
				LCD_voidSendString("Manual test");
				LCD_voidGoto(0, 1);
				LCD_voidSendString("has started");

				while (1)
				 {
					key = KEYPAD_u8GetKey();
					if (key == 'C') 
					{
						start();
						/*rest all functions inside this scope*/
						break;
					}
			      }
			
			 }
			else if (key == 1) 
			{
				LCD_voidClearScreen();
				LCD_voidGoto(0, 0);
				LCD_voidSendString("Automatic test");
				LCD_voidGoto(0, 1);
				LCD_voidSendString("has started");

				
				while (1) 
				{
					key = KEYPAD_u8GetKey();
					if (key == 'C') 
					{   start();
						/*rest all functions inside this scope*/
						break;
						
					} 
				}
				 
			}
		}
	
}



int main(void) {
	LCDSetup();
	KeypadSetup();
	while(1)
	{
		WelcomeMessage();
		
	}
	

	return 0;
}
