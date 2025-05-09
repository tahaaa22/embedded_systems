/*
 * TWI_reg.h
 *
 * Created: 10/11/2024 6:53:41 PM
 *  Author: AMIT
 */ 


#ifndef TWI_REG_H_
#define TWI_REG_H_


#define TWBR_REG     *((volatile  u8*)0x20)
#define TWSR_REG     *((volatile  u8*)0x21)
#define TWCR_REG     *((volatile  u8*)0x56)
#define TWAR_REG     *((volatile  u8*)0x22)
#define TWDR_REG     *((volatile  u8*)0x23)



/* TWI STATUS */

#define START_ACK                             0x08   /* start has been send */
#define REP_START                             0x10   /* repeated start*/
#define SLAVE_ADD_AND_WR_ACK                  0x18   /*MASTER transmit (slave address +write request  */
#define SLAVE_ADD_AND_RR_ACK                  0x40  /*MASTER transmit (slave address +write request  */
#define MASTER_WR_BYTE_ACK                    0x28   /*MASTER transmit Data ack  */
#define MASTER_RD_BYTE_WITH_ACK               0x50   /*MASTER  receive data with ack  */
#define MASTER_RD_BYTE_WITH_NACK              0x58   /*MASTER  receive data with ack  */
#define SLAVE_ADD_RCVD_RD_REQ                 0xA8   /* MEANS that slave address is received with read request  */
#define SLAVE_ADD_RCVD_WD_REQ                 0x60   /* MEANS that slave address is received with Write request  */
#define SLAVE_DATA_RECEIVED                   0x80  /* MEANS that data byte is recevied */
#define SLAVE_BYTE_TRANSMITTIED               0xB8  /* MEANS that data byte  are transmitted  */



#endif /* TWI_REG_H_ */