/*
 * TWI_interface.h
 *
 * Created: 10/11/2024 6:53:54 PM
 *  Author: AMIT
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


typedef enum {
	  NOErr , 
	  SendStartConditionErr , 
	  RepeatedStartErr , 
	  SendSlaveAddressWithWriteErr , 
	  SendSlaveAddressWithReadErr , 
	  MasterSendDataErr , 
	  MasterReciveDataErr , 
	 
	
	
	
	}Status_Err;




/* address : 0 */
void TWI_voidMasterInit(u8  copy_u8address) ; 

void TWI_voidSlaveInit(u8  copy_u8address) ;


Status_Err TWI_Status_ERRSendStartCondition(void) ; 
Status_Err TWI_Status_ErrRepeatedStart(void) ;

Status_Err TWI_Status_ErrSendSlaveAddressWithWrite( u8 copy_u8adress) ; 
Status_Err TWI_Status_ErrSendSlaveAddressWithRead( u8 copy_u8adress) ;

Status_Err TWI_Status_ErrMasterSendData( u8 copy_u8data) ;
Status_Err TWI_Status_ErrMasterReciveData(u8 *copy_u8data) ;

void TWI_Status_ERRSendStopCondition(void) ;











#endif /* TWI_INTERFACE_H_ */