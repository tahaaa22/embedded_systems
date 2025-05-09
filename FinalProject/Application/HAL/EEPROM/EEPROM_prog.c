/*
 * EEPROM_prog.c
 *
 * Created: 10/11/2024 9:10:09 PM
 *  Author: youss
 */ 

#include "EEPROM_interface.h"

void EEPROM_voidSendData(u16 copy_u16address,u8 copy_u8data){
	u8 LOC_u8deviceAddress = 0b1010000 | copy_u16address >>8;
	
	
	TWI_Status_ERRSendStartCondition();
	
	TWI_Status_ErrSendSlaveAddressWithWrite(LOC_u8deviceAddress);
	
	TWI_Status_ErrMasterSendData((u8)copy_u16address);
	
	TWI_Status_ErrMasterSendData(copy_u8data);
	
	TWI_Status_ERRSendStopCondition();
	_delay_ms(5);
	
	
}

void EEPROM_voidSendPage(u16 copy_u16address,u8* copy_u8data,u8 arr_size){
	u8 LOC_u8deviceAddress = 0b1010000 | copy_u16address >>8;
	
	
	TWI_Status_ERRSendStartCondition();
	
	TWI_Status_ErrSendSlaveAddressWithWrite(LOC_u8deviceAddress);
	
	TWI_Status_ErrMasterSendData((u8)copy_u16address);
	
	for (u8 i = 0; i < arr_size; ++i)
	{
		TWI_Status_ErrMasterSendData(copy_u8data[i]);
	}
	TWI_Status_ERRSendStopCondition();
	_delay_ms(5);
}

u8 EEPROM_u8ReceiveData(u16 copy_u16address){
	u8 LOC_u8deviceAddress = 0b1010000 | copy_u16address >>8;

	
	TWI_Status_ERRSendStartCondition();
	
	TWI_Status_ErrSendSlaveAddressWithWrite(LOC_u8deviceAddress);
	
	TWI_Status_ErrMasterSendData((u8)copy_u16address);
	
	TWI_Status_ErrRepeatedStart();
	
	TWI_Status_ErrSendSlaveAddressWithRead(LOC_u8deviceAddress);
	
	u8 LOC_data = 0;
	
	
	
	TWI_Status_ErrMasterReciveData(&LOC_data);
	
	TWI_Status_ERRSendStopCondition();	
	
	return LOC_data;
}

