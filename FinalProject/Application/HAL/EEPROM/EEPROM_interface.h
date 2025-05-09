/*
 * EEPROM_interface.h
 *
 * Created: 10/11/2024 9:05:26 PM
 *  Author: youss
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TWI/TWI_interface.h"

/* Delay Library */
#define F_CPU 16000000UL
#include <util/delay.h>

void EEPROM_voidSendData(u16 copy_u16address,u8 copy_u8data);

void EEPROM_voidSendPage(u16 copy_u16address,u8* copy_u8data,u8 arr_size);


u8 EEPROM_u8ReceiveData(u16 copy_u16address);




#endif /* EEPROM_INTERFACE_H_ */