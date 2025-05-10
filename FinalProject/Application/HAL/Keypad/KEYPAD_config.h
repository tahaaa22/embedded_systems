/*
 * KEYPAD_config.h
 *
 * Created: 8/30/2024 6:54:18 PM
 * Author: Ahmed taha
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


/* Section: Includes */
#include "../../MCAL/DIO/DIO_interface.h"

/* Section: Macro Declaration */

/* Keypad Size */
#define ROW       4
#define COL       4


/* ROW PORT */

#define KEYPAD_ROW_PORT      DIO_PORTC
#define KEYPAD_R0_PIN        DIO_PIN3
#define KEYPAD_R1_PIN        DIO_PIN4
#define KEYPAD_R2_PIN        DIO_PIN5
#define KEYPAD_R3_PIN        DIO_PIN6

/* COL PORT */

#define KEYPAD_COL_PORT      DIO_PORTB
#define KEYPAD_C0_PIN        DIO_PIN4
#define KEYPAD_C1_PIN        DIO_PIN5
#define KEYPAD_C2_PIN        DIO_PIN6
#define KEYPAD_C3_PIN        DIO_PIN7





#endif /* KEYPAD_CONFIG_H_ */