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
	_delay_ms(50);
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
	else if(extreme_level == True)
		LCD_voidSendString("Severe Hearing");
	else if(normal_level == True)
	LCD_voidSendString("Normal Hearing");
	else
		LCD_voidSendString("check your DR");
		
	_delay_ms(2000);
	LCD_voidClearScreen();
	LCD_voidGoto(0,0);
	LCD_voidSendString("thank you");
	LCD_voidGoto(0,1);
	LCD_voidSendString("for using Biko.");
	_delay_ms(1000);
}

void applyFrequency(u8 frequency, u8 led_level)
{
	LCD_voidClearScreen();
	LCD_voidGoto(0,0);
	LCD_voidSendString("freq= ");
	LCD_voidSendNum(frequency);
	LCD_voidSendString("HZ");
	BUZZER_voidOn(100, frequency);
						
	// setup led to show completion process
	CompletionLevel(led_level);
	_delay_ms(2000);
}

Bool applyHealth(void)
{
	healthChoices();
	healthType health= updateHealth();
	BUZZER_voidOff();
	_delay_ms(2000);
	if (health == lowHealth || health == extremeHealth)
	{
		
		resetLeds();
		return True;
	}
	// return false if the user will continue the test
	return False;
}

void automaticMode(void)
{
	// ranges of applied frequencies
	u32 frequencies[4] = {5, 50 , 100, 210};
	u8 current_Key = 0xff;
	Bool health_checked = False;
	LCD_voidClearScreen();
	LCD_voidGoto(0,0);
	LCD_voidSendString("Now in Auto");
	LCD_voidGoto(0,1);
	LCD_voidSendString("press # to start");
	
	while(current_Key != '=') current_Key = KEYPAD_u8GetKey();
	
	for(u8 index = 0; index < 4; ++index)
	{
		applyFrequency(frequencies[index], index);
		health_checked = applyHealth();
		
		if(health_checked == True)
		{
			return;
		}
		_delay_ms(1000);
	}
	return;
}

void manualMode(void)
{
	u32 frequencies[4] = {5, 50 , 100, 210};
	u8 current_Key = 0xff;
	Bool health_checked = False;
	
	LCD_voidClearScreen();
	LCD_voidGoto(0,0);
	LCD_voidSendString("Welcome to");
	LCD_voidGoto(0,1);
	LCD_voidSendString("Manual Test");
	
	while(1)
	{
		current_Key = 0xff;
		health_checked = False;
		
		LCD_voidClearScreen();
		LCD_voidGoto(0,0);
		LCD_voidSendString("Choose a Freq :");
		_delay_ms(10);

		LCD_voidClearScreen();
		LCD_voidGoto(0,0);
		LCD_voidSendString("1: 5Hz 2: 50Hz");
		LCD_voidGoto(0,1);
		LCD_voidSendString("3: 100Hz 4: 210");
		do
		{
			current_Key = KEYPAD_u8GetKey();
			_delay_ms(50);
		} while (current_Key == 0xff); // if the key is set to a value exit holding condition
	
		switch(current_Key)
		{
			case (1):
				applyFrequency(frequencies[0], 0);
				health_checked = applyHealth();
				_delay_ms(500);
				break;
			case (2):
				applyFrequency(frequencies[1], 1);
				health_checked = applyHealth();
				_delay_ms(500);
				break;
			case (3):
				applyFrequency(frequencies[2], 2);
				health_checked = applyHealth();
				_delay_ms(500);
				break;
			case (4):
				applyFrequency(frequencies[3], 3);
				health_checked = applyHealth();
				_delay_ms(500);
				break;
		}
		
		if(health_checked == True)
		{
			return;
		}
	}
}

void Simulator(void) 
{
	u8 key = 0xff;
	Bool is_finished = False;

	while (1)
	{
		 is_finished = False;
		 	BUZZER_voidOff();
		 	_delay_ms(2000);
			 
		testChoices();
		do
		{
			key = KEYPAD_u8GetKey();
			_delay_ms(50);
		} while (key == 0xff); // if the key is set to a value exit holding condition
		
		switch(key)
		{
			case(0):
			manualMode();
			is_finished = True;
			break;
			
			case(1):
			automaticMode();
			is_finished = True;
			break;
			
			default:
			LCD_voidClearScreen();
			LCD_voidGoto(0,0);
			LCD_voidSendString("Invalid choice");
			LCD_voidGoto(0,1);
			LCD_voidSendString("choose val opt");
			_delay_ms(500);
		}
		if(is_finished == True)
		{
			BUZZER_voidOff();
			resetLeds();
			showTestResult();
			resetHealth();
			return;
		}
	}
}


/* ============================== *
 *              MAIN               *
 * ============================== */

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
