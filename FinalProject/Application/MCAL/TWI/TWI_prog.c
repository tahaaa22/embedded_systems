/*
 * TWI_prog.c
 *
 * Created: 10/11/2024 6:54:06 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "TWI_interface.h"
#include "TWI_reg.h"




void TWI_voidMasterInit(u8  copy_u8address) {
	
	/*TWBR selects the division factor :  scl : 400khz , f : 16mhz */
	
	  TWBR_REG=12 ; 
	    /* SET prescaler : 1 */
	    
	    CLR_BIT(TWSR_REG,0) ;
	    CLR_BIT(TWSR_REG,1) ;
	  if (copy_u8address !=0)
	  {
		  TWAR_REG=copy_u8address<<1 ; 
	  }
	  else{
		  // do nothing 
	  }
	
	/*  enable ACK */
   SET_BIT(TWCR_REG,6) ; 
   /* enable TWI */	
   SET_BIT(TWCR_REG,2) ;
   
}

void TWI_voidSlaveInit(u8  copy_u8address){
	
	/* set slave address*/
	
		  TWAR_REG=copy_u8address<<1 ;

	
	
	/*  enable ACK */
	SET_BIT(TWCR_REG,6) ;
	/* enable TWI */
	SET_BIT(TWCR_REG,2) ;
	
	
}


Status_Err TWI_Status_ERRSendStartCondition(void){
	
	Status_Err loc_temp=NOErr ; 
	
	
	/* send start condition*/
	
	 SET_BIT(TWCR_REG,5) ; 
	 /* CLR Flag*/
	SET_BIT(TWCR_REG,7) ; 
	
	while(GET_BIT(TWCR_REG,7)==0) ; 
	
	
	if ((TWSR_REG &0xF8) != START_ACK)
	{
		
		loc_temp=SendStartConditionErr ; 
	}
	  else {
		  
		  // do nothing 
	  }
	
	return loc_temp ; 
	
}
	
Status_Err TWI_Status_ErrRepeatedStart(void){
	
	
	Status_Err loc_temp=NOErr ;
	
	
	/* send start condition*/
	
	SET_BIT(TWCR_REG,5) ;
	/* CLR Flag*/
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	
	if ((TWSR_REG &0xF8) != REP_START)
	{
		
		loc_temp=RepeatedStartErr ;
	}
	else {
		
		// do nothing
	}
	
	return loc_temp ;
	
	
	
}

Status_Err TWI_Status_ErrSendSlaveAddressWithWrite( u8 copy_u8adress){
	
	
	Status_Err loc_temp=NOErr ;
	
	
	/*send slave address on bus */
	
	TWDR_REG=copy_u8adress<<1 ; 
	CLR_BIT(TWDR_REG,0) ;  /* TO write */
	
	
	
	/* clr  start condition*/
	
	CLR_BIT(TWCR_REG,5) ;
	/* CLR Flag*/
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	
	if ((TWSR_REG &0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		
		loc_temp=SendSlaveAddressWithWriteErr ;
	}
	else {
		
		// do nothing
	}
	
	return loc_temp ;
	
	
}
Status_Err TWI_Status_ErrSendSlaveAddressWithRead( u8 copy_u8adress){
	
	Status_Err loc_temp=NOErr ;
	
	
	/*send slave address on bus */
	
	TWDR_REG=copy_u8adress<<1 ;
	 SET_BIT(TWDR_REG,0) ;  /* TO read */
	
	
	
	/* clr  start condition*/
	
	CLR_BIT(TWCR_REG,5) ;
	/* CLR Flag*/
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	
	if ((TWSR_REG &0xF8) != SLAVE_ADD_AND_RR_ACK)
	{
		
		loc_temp=SendSlaveAddressWithReadErr ;
	}
	else {
		
		// do nothing
	}
	
	return loc_temp ;
	
	
	
	
}

Status_Err TWI_Status_ErrMasterSendData( u8 copy_u8data){
	
	Status_Err loc_temp=NOErr ;
	
	
	/*send  data  on bus */
	
	TWDR_REG=copy_u8data ;
	/* CLR Flag*/
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	
	if ((TWSR_REG &0xF8) != MASTER_WR_BYTE_ACK)
	{
		
		loc_temp=MasterSendDataErr ;
	}
	else {
		
		// do nothing
	}
	
	return loc_temp ;
	
	
	
	
	
	
}
Status_Err TWI_Status_ErrMasterReciveData(u8 *copy_u8data){
	
	Status_Err loc_temp=NOErr ;
	

	/* CLR Flag*/
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	
	if ((TWSR_REG &0xF8) != MASTER_RD_BYTE_WITH_ACK)
	{
		
		loc_temp=MasterReciveDataErr ;
	}
	else {
		
		   *copy_u8data=TWDR_REG ; 
	}
	
	return loc_temp ;
}

void TWI_Status_ERRSendStopCondition(void){
	
	
	/*StopCondition*/
	
	SET_BIT(TWCR_REG,4) ; 
	
	
	
	/* CLR Flag*/
	SET_BIT(TWCR_REG,7) ;
	
}