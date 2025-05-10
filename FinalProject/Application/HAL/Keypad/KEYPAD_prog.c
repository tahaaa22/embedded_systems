/*
 * KEYPAD_prog.c
 *
 * Created: 8/30/2024 6:55:08 PM
 * Author: Ahmed taha
 */ 

#include "KEYPAD_interface.h"

/*2D - Array that maps the coordinates of the press with the value it should represent */
u8 KEYPAD_ARR[ROW][COL] = {
	{7,8,9,'A'},
	{4,5,6,'B'},
	{1,2,3,'C'},
	{'C',0,'=','+'},
	
};

/*****************************************************************************
* Function Name: KEYPAD_voidInit
* Purpose      : Initializes KEYPAD
* Parameters   : void
* Return value : void
*****************************************************************************/
void KEYPAD_voidInit(void){
	u8 LOC_row_arr[ROW] = {KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};
	u8 LOC_col_arr[COL] = {KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};
	u8 LOC_i = 0;	
	for (LOC_i = 0 ; LOC_i < ROW; LOC_i++)
	{
		/* Set the row port input high to activate the internally pull-up resistors */
		DIO_voidSetPinDir(KEYPAD_ROW_PORT,LOC_row_arr[LOC_i],INPUT);
		DIO_voidSetPinVal(KEYPAD_ROW_PORT,LOC_row_arr[LOC_i],HIGH);
		
		/* Set the col port output high to disable the push buttons */
		DIO_voidSetPinDir(KEYPAD_COL_PORT,LOC_col_arr[LOC_i],OUTPUT);
		DIO_voidSetPinVal(KEYPAD_COL_PORT,LOC_col_arr[LOC_i],HIGH);
	}
}						   
						   

/*****************************************************************************
* Function Name: KEYPAD_u8GetKey
* Purpose      : Gets KEYPAD row,col and maps it to keypad array map
* Parameters   : void
* Return value : u8
*****************************************************************************/
u8 KEYPAD_u8GetKey(void){
	u8 LOC_row_arr[ROW] = {KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};
	u8 LOC_col_arr[COL] = {KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};
	u8 LOC_row,LOC_col;
	LOC_row = 0; 
	LOC_col = 0;
	
	u8 LOC_key = 0xff;
	for(LOC_col = 0 ; LOC_col < COL ;LOC_col++){
		/* Set this column to 0v (GND) */
		DIO_voidSetPinVal(KEYPAD_COL_PORT,LOC_col_arr[LOC_col],LOW);
		for (LOC_row = 0 ; LOC_row < ROW; LOC_row++)
		{
			/* Check if any buttons of all the rows int this column is pressed */
			if (DIO_u8ReadPinVal(KEYPAD_ROW_PORT,LOC_row_arr[LOC_row]) == 0)
			{
				LOC_key = KEYPAD_ARR[LOC_row][LOC_col];                             // Gets the mapped value
				while(DIO_u8ReadPinVal(KEYPAD_ROW_PORT,LOC_row_arr[LOC_row]) == 0); // Busy Wait for button debouncing
				_delay_ms(100);
				return LOC_key;                                                     // Key press detected 
			}
		}
		DIO_voidSetPinVal(KEYPAD_COL_PORT,LOC_col_arr[LOC_col],HIGH);               // No buttons pressed in this col so make it high to avoid S.C
	}
	return LOC_key; // Oxff key press not detected
}
