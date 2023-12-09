/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: I2C						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Sunday, September 3, 2023 ******************************/
/*********************************************************************************/

#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C.h"

void I2C_voidMasterInit(void){
    // Select I2C Frequency = 200 KHZ
    // 1-Set Prescaler --> 1
    CLR_BIT(TWSR, TWPS0);
    CLR_BIT(TWSR, TWPS1);

    // 2-Set Bit Rate Value Register = 12
    TWBR = 12;

    // 3-Enable ACK
    SET_BIT(TWCR, TWEA);

    // 3-Enable I2C
    SET_BIT(TWCR, TWEN);

}
void I2C_voidSlaveInit(u8 Copy_u8SlaveAddress){
    // Write Slave Address
    TWAR = Copy_u8SlaveAddress << 1;

    // 3-Enable ACK
    SET_BIT(TWCR, TWEA);

    // 3-Enable I2C
    SET_BIT(TWCR, TWEN);
}

void I2C_voidStartCondition(void){

    // 1-Clear Flag + Enable Start Condition
    SET_BIT(TWCR, TWSTA);
    SET_BIT(TWCR, TWINT);

    // 2-Check Flag
    while((GET_BIT(TWCR, TWINT)) == 0);
}
void I2C_voidStopCondition(void){

    // 1-Clear Flag + Enable Stop Condition
    SET_BIT(TWCR, TWINT);
    SET_BIT(TWCR, TWSTO);
}

void I2C_voidSlaveAddressWrite(u8 Copy_u8SlaveAddress){

    // 1-Clear Start Condition
    CLR_BIT(TWCR, TWSTA);

    // 2-Select Slave Address + Write Bit
    TWDR = Copy_u8SlaveAddress << 1;
    CLR_BIT(TWDR, 0); // TWD0 Bit

    // 3-Clear Flag
    SET_BIT(TWCR, TWINT);

    // 4-Wait Flag
    while((GET_BIT(TWCR, TWINT)) == 0);

    // 5-Check ACK (It was done by HW Already)

}
void I2C_voidSlaveAddressRead(u8 Copy_u8SlaveAddress){

    // 1-Clear Start Condition
    CLR_BIT(TWCR, TWSTA);

    // 2-Select Slave Address + Read Bit
    TWDR = Copy_u8SlaveAddress << 1;
    SET_BIT(TWDR, 0); // TWD0 Bit

    // 3-Clear Flag
    SET_BIT(TWCR, TWINT);

    // 4-Wait Flag
    while((GET_BIT(TWCR, TWINT)) == 0);

    // 5-Check ACK (It was done by HW Already)
}

void I2C_voidMasterSendData(u8 Copy_u8Data){

    // 1-Write Data in TWDR
    TWDR = Copy_u8Data;

    // 2-Clear Flag
    SET_BIT(TWCR, TWINT);

    // 3-Wait Flag
    while((GET_BIT(TWCR, TWINT)) == 0);
}

u8 I2C_u8MasterReceiveData(void){

    // 1-Clear Flag
    SET_BIT(TWCR, TWINT);

    // 2-Wait Flag
    while((GET_BIT(TWCR, TWINT)) == 0);

    return TWDR;

}
u8 I2C_u8SlaveReceiveData(void){
    
    // Wait to Master Write Address
    while((TWSR & 0xf8) != 0x60);

    // Clear Flag
    SET_BIT(TWCR, TWINT);

    // Wait to Master Write Data
    while((TWSR & 0xf8) != 0x80);

    return TWDR;

}



// while(TWSR & 0xf8 != 08);
