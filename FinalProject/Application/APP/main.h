#ifndef MAIN_H_
#define MAIN_H_

/* Section: Includes */
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SSD/SSD_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/Keypad/KEYPAD_interface.h"
#include "../MCAL/GI/GI_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/TIM0/TIM0_interface.h"
#include "../MCAL/TIM1/TIM1_interface.h"
#include "../MCAL/TIM2/TIM2_interface.h"
#include "../MCAL/WDT/WDT_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/TWI/TWI_interface.h"
#include "../HAL/DC_MOTOR/DC_MOTOR_interface.h"
#include "../HAL/SERVO_MOTOR/SERVO_MOTOR_interface.h"
#include "../HAL/BUZZER/BUZZER_interface.h"
#include "../HAL/EEPROM/EEPROM_interface.h"
#include "../HAL/ULTRASONIC/ULTRASONIC_interface.h"

/* Section: Macro Declaration */
#define F_CPU 16000000UL
#include <util/delay.h>

#define PORT_LED_1 DIO_PORTC
#define PORT_LED_2 DIO_PORTC
#define PORT_LED_3 DIO_PORTD

#define LED_1 DIO_PIN2
#define LED_2 DIO_PIN7
#define LED_3 DIO_PIN3

/* Section: Data Type Declaration*/
Bool low_level = False;
Bool normal_level = False;
Bool extreme_level = False;

typedef enum {lowHealth, normalHealth, extremeHealth} healthType;
/* Section: Function Declaration */

#endif /* MAIN_H_ */