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

	// Set row pins (PC0�PC3) as output for keypad (if needed)
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

void StartAutomaticTest(void) {
    const u32 frequencies[] = {500, 5000, 10000, 20000, 30000, 50000};
    u8 freq_count = 6;

    for (u8 i = 0; i < freq_count; i++) {
        LCD_voidClearScreen();
        LCD_voidGoto(0, 0);
        LCD_voidSendString("Freq: ");
        LCD_voidSendNum(frequencies[i]);
        LCD_voidSendString(" Hz");
		BUZZER_voidOn(50);
        
        //_delay_ms(200); // Ensure F_CPU is defined correctly!
        TIM0_voidStop();
		BUZZER_voidOff();
		LCD_voidClearScreen();
		_delay_ms(1000);
		
        LCD_voidGoto(0, 1);
        LCD_voidSendString("Resp within 5s");
		_delay_ms(500);
        u8 user_input = 0xFF;
        u32 timeout = 0;

        while (timeout < 5000) {
            user_input = KEYPAD_u8GetKey();
            if (user_input == '+' || user_input == '-' || user_input == '=') {
                break;
            }
            _delay_ms(100);
            timeout += 100;
        }

        if (user_input == 0xFF) {
            LCD_voidClearScreen();
            LCD_voidSendString("Press +, -, or =");
            while (1) {
                user_input = KEYPAD_u8GetKey();
                if (user_input == '+' || user_input == '-' || user_input == '=') {
                    break;
                }
            }
        }

        if (user_input == '=') {
            i--; // Replay same frequency
        }
    }

    LCD_voidClearScreen();
    LCD_voidSendString("Auto Test Complete");
    _delay_ms(2000);
}

// Function to show welcome message and wait for test mode selection
void WelcomeMessage(void) {
	start();
	while (1) {
		u8 key = KEYPAD_u8GetKey();
		if (key == 0) {
			// Manual test logic remains unchanged
			LCD_voidClearScreen();
			LCD_voidGoto(0, 0);
			LCD_voidSendString("Manual test");
			LCD_voidGoto(0, 1);
			LCD_voidSendString("has started");
			while (1) {
				key = KEYPAD_u8GetKey();
				if (key == 'C') {
					start();
					break;
				}
			}
			} else if (key == 1) {
			LCD_voidClearScreen();
			LCD_voidGoto(0, 0);
			LCD_voidSendString("Automatic test");
			LCD_voidGoto(0, 1);
			LCD_voidSendString("has started");
			_delay_ms(1000);
			StartAutomaticTest(); 
			start();
			
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
