#include "main.h"

// Keypad setup function
void KeypadSetup(void) {
	// Set keypad column pins (e.g., PC1�PC3) as input
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
}

void resetLeds(void)
{
	DIO_voidSetPinDir(PORT_LED_1, LED_1 ,OUTPUT);
	DIO_voidSetPinDir(PORT_LED_2, LED_2,OUTPUT);
	DIO_voidSetPinDir(PORT_LED_3, LED_3,OUTPUT);
	
	DIO_voidSetPinVal(PORT_LED_1,LED_1,LOW);
	DIO_voidSetPinVal(PORT_LED_2,LED_2,LOW);
	DIO_voidSetPinVal(PORT_LED_3,LED_3,LOW);
}

void healthChoices(void)
{
	LCD_voidClearScreen();
	LCD_voidGoto(0,0);
	LCD_voidSendString("Choose from :");
	LCD_voidGoto(0,1);
	LCD_voidSendString("A, B, C");
	_delay_ms(500);
	LCD_voidClearScreen();
	LCD_voidGoto(0, 0);
	LCD_voidSendString("A:No B:Normal");
	LCD_voidGoto(0, 1);
	LCD_voidSendString("C:Extreme");
}

void CompletionLevel(u8 u8_currentLevel)
{
	DIO_voidSetPinDir(PORT_LED_1, LED_1 ,OUTPUT);
	DIO_voidSetPinDir(PORT_LED_2, LED_2,OUTPUT);
	DIO_voidSetPinDir(PORT_LED_3, LED_3,OUTPUT);
	
	switch(u8_currentLevel)
	{
		case(3):
		DIO_voidSetPinVal(PORT_LED_3,LED_3,HIGH);
		case(2):
		DIO_voidSetPinVal(PORT_LED_2,LED_2,HIGH);
		case(0):
		DIO_voidSetPinVal(PORT_LED_1,LED_1,HIGH);
		break;
	}		
}

void testChoices(void)
{
	LCD_voidClearScreen();
	LCD_voidGoto(0, 0);
	LCD_voidSendString("Choose test Type");
	_delay_ms(2000);
	LCD_voidClearScreen();
	LCD_voidGoto(0,0);
	LCD_voidSendString("Manual test:0");
	LCD_voidGoto(0, 1);
	LCD_voidSendString("Auto test: 1");
}

healthType updateHealth(void)
{	
	u8 key = 0xFF;
	do {
		key = KEYPAD_u8GetKey();
	} while (key == 0xFF);
	
	switch(key)
	{
		case 'A':
		LCD_voidClearScreen();
		LCD_voidSendString("You chose: No");
		low_level = True;
		return lowHealth;
		case 'B':
		LCD_voidClearScreen();
		LCD_voidSendString("You chose: norm");
		normal_level = True;
		return normalHealth;
		case 'C':
		LCD_voidClearScreen();
		LCD_voidSendString("You chose: V.Ext");
		extreme_level = True;
		return extremeHealth;
		default:
		LCD_voidClearScreen();
		LCD_voidGoto(0,0);
		LCD_voidSendString("Invalid choice");
		LCD_voidGoto(0,1);
		LCD_voidSendString("choose val opt");
		updateHealth();
	}
	_delay_ms(1000);
	
	return normalHealth;
	}

void resetHealth(void)
{
	low_level = False;
	normal_level = False;
	extreme_level = False;
}

void showTestResult(void)
{
	LCD_voidClearScreen();
	LCD_voidGoto(0,0);
	LCD_voidSendString("Test Result :");
	LCD_voidGoto(0,1);
	if(low_level == True)
		LCD_voidSendString("Mild Hearing L");
	else if(normal_level == True)
		LCD_voidSendString("Normal Hearing");
	else if(extreme_level == True)
		LCD_voidSendString("Severe Hearing");
	else
		LCD_voidSendString("check your DR");
	resetHealth();
	_delay_ms(2000);
	LCD_voidClearScreen();
	LCD_voidGoto(0,0);
	LCD_voidSendString("thank you");
	LCD_voidGoto(0,1);
	LCD_voidSendString("for using Biko.")
}

void automaticMode(void)
{
	// ranges of applied frequencies
	u32 frequencies[4] = {5, 50 , 100, 210};
	u8 current_Key = 0xff;
	
	LCD_voidClearScreen();
	LCD_voidGoto(0,0);
	LCD_voidSendString("welcome to Auto");
	LCD_voidGoto(0,1);
	LCD_voidSendString("press # to start");
	
	while(current_Key != '=') current_Key = KEYPAD_u8GetKey();
	
	for(u8 index = 0; index < 4; ++index)
	{
		LCD_voidClearScreen();
		LCD_voidGoto(0,0);
		LCD_voidSendString("freq= ");
		LCD_voidSendNum(frequencies[index]);
		LCD_voidSendString("HZ");
		BUZZER_voidOn(100, frequencies[index]);
		
		// setup led to show completion process
		CompletionLevel(index);
		_delay_ms(2000);
		
	    healthChoices();
		healthType health= updateHealth();
		
		if (health == lowHealth || health == extremeHealth)
		{
			BUZZER_voidOff();
			resetLeds();
			return;
		}
		_delay_ms(1000);
	}
}

void Simulator(void) 
{
	u8 key = 0xff;
	while (1)
	{
		testChoices();
		do 
		{
			key = KEYPAD_u8GetKey();
			_delay_ms(50);
		} while (key == 0xff); // if the key is set to a value exit holding condition
		
		switch(key)
		{
			case(0):
			break;
			case(1):
			automaticMode();
			showTestResult();
			return;
		}
	}
}



int main(void) {
	LCDSetup();
	KeypadSetup();
	
	// intialise buzzer pin to manage pwm and pin value together
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN3,OUTPUT);
	DIO_voidSetPinVal(DIO_PORTA,DIO_PIN3,LOW);
	
	u8 heart_Pattern[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };
		
	while(1)
	{
		LCD_voidClearScreen();
		LCD_voidGoto(0, 0);
		LCD_voidSendString("    Welcome  ");
		LCD_voidGoto(0,1);
		LCD_voidSendString("   To Biko");
		LCD_voidDrawData(0,heart_Pattern,11,1);
		_delay_ms(2000);
		LCD_voidClearScreen();
		LCD_voidGoto(0, 0);
		LCD_voidSendString("Digital Hearing");
		LCD_voidGoto(0,1);
		LCD_voidSendString("Test System");
		_delay_ms(1000);
		Simulator();
	}
	

	return 0;
}
