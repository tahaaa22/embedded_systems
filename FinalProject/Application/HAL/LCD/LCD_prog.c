/*
 * LCD_prog.c
 *
 * Created: 8/24/2024 10:47:11 PM
 * Author:  Ahmed taha
 */ 

#include "LCD_interface.h"

/*****************************************************************************
* Function Name: LCD_voidSendHalfData
* Purpose      : Sends Half Data to LCD for 4-bit Mode
* Parameters   : u8 copy_u8data
* Return value : void
*****************************************************************************/
void LCD_voidSendHalfData(u8 copy_u8data){
	u8 LCD_arr[4]={LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN} ;               // Array Containing LCD Pins
	u8 LOC_i = 0;
	for (LOC_i = 0; LOC_i < 4 ;LOC_i++)
	{
		DIO_voidSetPinVal(LCD_DPORT,LCD_arr[LOC_i],GET_BIT(copy_u8data,LOC_i)); // Setting the pin with the corresponding bit of the data sent
	}
}

/*****************************************************************************
* Function Name: LCD_voidSendEnablePulse
* Purpose      : Send Enable Pulse for 2 ms
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_voidSendEnablePulse(void){
	DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,HIGH); // E pin -> HIGH
	_delay_ms(2);                                 // Rect Frequency
	DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,LOW);  // E pin -> LOW
}

/*****************************************************************************
* Function Name: LCD_voidInit
* Purpose      : Initializes LCD
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_voidInit(void){
	
	/* Initializing LCD */
	_delay_ms(40);                       // Wait for more than 30ms after VDD rises to 4.5V
	
	/* Checking LCD Operation Mode */
	#if LCD_MODE == _8_BIT_MODE
		LCD_voidSendCommand(0b00111000); // Function Set Command (2 lines, 5x8 dot)
		LCD_voidSendEnablePulse();       // Send Enable Pulse
	#elif LCD_MODE == _4_BIT_MODE
		LCD_voidSendHalfData(0b0010);    // Function Set Command (2 lines, 5x8 dot)
		LCD_voidSendEnablePulse();       // Send Enable Pulse
		LCD_voidSendHalfData(0b0010);    // Function Set Command (2 lines, 5x8 dot)
		LCD_voidSendEnablePulse();       // Send Enable Pulse
		LCD_voidSendHalfData(0b1000);    // Function Set Command (2 lines, 5x8 dot)
		LCD_voidSendEnablePulse();       // Send Enable Pulse
	#endif
	
	LCD_voidSendCommand(0b00001100);     // Display Control Command (Enable display, Cursor OFF, Blinking OFF)
	LCD_voidSendCommand(0b00000001);     // Display Clear Command (Clears the LCD Display)
}

/*****************************************************************************
* Function Name: LCD_voidSendCommand
* Purpose      : Sends Command to LCD
* Parameters   : u8 copy_u8command
* Return value : void
*****************************************************************************/
void LCD_voidSendCommand(u8 copy_u8command){
	/* Set Control Pins */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,LOW);        // RS -> 0 (Command)
	DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW);        // RW -> 0 (Write)
	
	/* Checking LCD Operation Mode */
	#if LCD_MODE == _8_BIT_MODE
		DIO_voidSetPortVal(LCD_DPORT,copy_u8command);
		LCD_voidSendEnablePulse();						// Send Enable Pulse
	#elif LCD_MODE == _4_BIT_MODE
		LCD_voidSendHalfData(copy_u8command>>LCD_PINS); // Sending Highest Nibble
		LCD_voidSendEnablePulse();						// Send Enable Pulse
		LCD_voidSendHalfData(copy_u8command);			// Sending Lowest Nibble
		LCD_voidSendEnablePulse();					    // Send Enable Pulse
		
	#endif
}

/*****************************************************************************
* Function Name: LCD_voidSendData
* Purpose      : Sends Data to LCD
* Parameters   : u8 copy_u8data
* Return value : void
*****************************************************************************/
void LCD_voidSendData(u8 copy_u8data){
	/* Set Control Pins */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,HIGH); // RS -> 1 (Data)
	DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW);  // RW -> 0 (Write)
	
	/* Checking LCD Operation Mode */
	#if LCD_MODE == _8_BIT_MODE
		DIO_voidSetPortVal(LCD_DPORT,copy_u8data);
		LCD_voidSendEnablePulse();                   // Send Enable Pulse
	#elif LCD_MODE == _4_BIT_MODE
		LCD_voidSendHalfData(copy_u8data>>LCD_PINS); // Sending Highest Nibble 
		LCD_voidSendEnablePulse();					 // Send Enable Pulse
		LCD_voidSendHalfData(copy_u8data);			 // Sending Lowest Nibble
		LCD_voidSendEnablePulse();					 // Send Enable Pulse
	#endif
}

/*****************************************************************************
* Function Name: LCD_voidSendString
* Purpose      : Sends String to display on LCD
* Parameters   : u8* copy_u8str_ptr
* Return value : void
*****************************************************************************/
void LCD_voidSendString(const u8* const copy_u8str_ptr){
	u8 LOC_i = 0 ;
	while(copy_u8str_ptr[LOC_i]){                // Loop while copy_u8str_ptr[LOC_i] != '\0'
		LCD_voidSendData(copy_u8str_ptr[LOC_i]); // Send the character to be displayed on LCD
		LOC_i ++;								 // Go to the next character in the string
	}
}

/*****************************************************************************
* Function Name: LCD_voidSendNum
* Purpose      : Sends Number to display on LCD
* Parameters   : u32 copy_u32number
* Return value : void
*****************************************************************************/
void LCD_voidSendNum(u32 copy_u32number){
	if (copy_u32number == 0)                        // Case if the number is zero
	{
		LCD_voidSendData('0');                      // Send zero ASCII
		return;
	}
	
	u8 LOC_arr[DATA_LEN];                           // Array to store the number digits separately
	u8 LOC_i = 0;
	
	while(copy_u32number){							// Loop while the number != 0
		LOC_arr[LOC_i++] = copy_u32number % 10;     // Store in the array the last digit 
		copy_u32number /= 10;						// Integer division to remove the stored digit
	}
	
	for (s32 LOC_pos = LOC_i - 1; LOC_pos >= 0; --LOC_pos)
	{
		LCD_voidSendData(LOC_arr[LOC_pos] + '0');   // Send the digit ASCII by adding the ASCII of zero
	}
}

/*****************************************************************************
* Function Name: LCD_voidSendFloatingNum
* Purpose      : Sends floating Number to display on LCD
* Parameters   : u32 copy_u32number
* Return value : void
*****************************************************************************/
void LCD_voidSendFloatingNum(f64 copy_f64number){
	//32.26513
	u32 LOC_temp = (u32)copy_f64number; //32
	LCD_voidSendNum(LOC_temp);
	
	copy_f64number -= (u32)copy_f64number; // 32.265 - 32 = 0.265
	copy_f64number *= 1000; // 265.000001
	LOC_temp = (u32)copy_f64number; //265
	
	LCD_voidSendData('.');
	
	LCD_voidSendNum(LOC_temp);
	
}
/*****************************************************************************
* Function Name: LCD_voidGoto
* Purpose      : Display the character at a specific position by communicating with DDRAM
* Parameters   : u8 copy_u8x,u8 copy_u8y
* Return value : void
*****************************************************************************/
void LCD_voidGoto(u8 copy_u8x,u8 copy_u8y){
	if (copy_u8y == 0 || copy_u8y == 1){
		u8 LOC_DDRAM_address = copy_u8x + copy_u8y * 0x40; // Set DDRAM Address
		
		SET_BIT(LOC_DDRAM_address,7);                      // Set MSB -> 1
		LCD_voidSendCommand(LOC_DDRAM_address);            // Send Address as a command to DDRAM        
	}else{                                                 // Invalid Address
		LCD_voidSendString("Invalid Position!");
	}
}

/*****************************************************************************
* Function Name: LCD_voidDrawData
* Purpose      : Display the user defined character by communicating with CGRAM
* Parameters   : u8 copy_u8pattern, u8* copy_u8data,u8 copy_u8x,u8 copy_u8y
* Return value : void
*****************************************************************************/
void LCD_voidDrawData(u8 copy_u8pattern, const u8* const copy_u8data,u8 copy_u8x,u8 copy_u8y){
	u8 LOC_CGRAM_address = copy_u8pattern * 8; // Set Pattern Number
	CLR_BIT(LOC_CGRAM_address,7);              // Clear 7th bit
	SET_BIT(LOC_CGRAM_address,6);			   // Set 6th bit
	LCD_voidSendCommand(LOC_CGRAM_address);	   // Set CGRAM address in address counter
	
	for (u8 LOC_i = 0 ; LOC_i < 8 ;++LOC_i)
	{
		LCD_voidSendData(copy_u8data[LOC_i]);  // Send the data representing on and off pixels
	}
	LCD_voidGoto(copy_u8x,copy_u8y);           // Display the character at a specific position by communicating with DDRAM
	LCD_voidSendData(copy_u8pattern);          
	
}

/*****************************************************************************
* Function Name: LCD_voidClearScreen
* Purpose      : Clears LCD Screen
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_voidClearScreen(void){
	LCD_voidSendCommand(1);
}