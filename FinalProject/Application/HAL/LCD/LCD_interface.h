/*
 * LCD_interface.h
 *
 * Created: 8/24/2024 10:46:51 PM
 * Author:  Ahmed taha
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



/* Section: Macro Declaration */
#define _4_BIT_MODE  0
#define _8_BIT_MODE  1

#define LCD_MODE	 _4_BIT_MODE
#define LCD_PINS     4

#define DATA_LEN     16
/* Section: Includes */
#include "LCD_config.h"

/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */

/*****************************************************************************
* Function Name: LCD_voidSendData
* Purpose      : Sends Data to LCD
* Parameters   : u8 copy_u8data
* Return value : void
*****************************************************************************/
void LCD_voidSendData(u8 copy_u8data);

/*****************************************************************************
* Function Name: LCD_voidSendCommand
* Purpose      : Sends Command to LCD
* Parameters   : u8 copy_u8command
* Return value : void
*****************************************************************************/
void LCD_voidSendCommand(u8 copy_u8command);

/*****************************************************************************
* Function Name: LCD_voidInit
* Purpose      : Initializes LCD
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_voidInit(void);

/*****************************************************************************
* Function Name: LCD_voidSendEnablePulse
* Purpose      : Send Enable Pulse for 2 ms
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_voidSendEnablePulse(void);

/*****************************************************************************
* Function Name: LCD_voidSendHalfData
* Purpose      : Sends Half Data to LCD for 4-bit Mode
* Parameters   : u8 copy_u8data
* Return value : void
*****************************************************************************/
void LCD_voidSendHalfData(u8 copy_u8data);

/*****************************************************************************
* Function Name: LCD_voidSendString
* Purpose      : Sends String to display on LCD
* Parameters   : u8* copy_u8str_ptr
* Return value : void
*****************************************************************************/
void LCD_voidSendString(const u8* const copy_u8str_ptr);

/*****************************************************************************
* Function Name: LCD_voidSendNum
* Purpose      : Sends Number to display on LCD
* Parameters   : u32 copy_u32number
* Return value : void
*****************************************************************************/
void LCD_voidSendNum(u32 copy_u32number);

/*****************************************************************************
* Function Name: LCD_voidSendFloatingNum
* Purpose      : Sends floating Number to display on LCD
* Parameters   : f64 copy_f64number
* Return value : void
*****************************************************************************/
void LCD_voidSendFloatingNum(f64 copy_f64number);
/*****************************************************************************
* Function Name: LCD_voidGoto
* Purpose      : Display the character at a specific position by communicating with DDRAM
* Parameters   : u8 copy_u8x,u8 copy_u8y
* Return value : void
*****************************************************************************/
void LCD_voidGoto(u8 copy_u8x,u8 copy_u8y);

/*****************************************************************************
* Function Name: LCD_voidDrawData
* Purpose      : Display the user defined character by communicating with CGRAM
* Parameters   : u8 copy_u8pattern, u8* copy_u8data,u8 copy_u8x,u8 copy_u8y
* Return value : void
*****************************************************************************/
void LCD_voidDrawData(u8 copy_u8pattern, const u8* const copy_u8data,u8 copy_u8x,u8 copy_u8y);

/*****************************************************************************
* Function Name: LCD_voidClearScreen
* Purpose      : Clears LCD Screen
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_voidClearScreen(void);

#endif /* LCD_INTERFACE_H_ */