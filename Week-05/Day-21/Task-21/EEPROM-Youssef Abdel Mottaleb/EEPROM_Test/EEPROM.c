/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: I2C						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Sunday, September 3, 2023 ******************************/
/*********************************************************************************/

#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "I2C.h"
#include "EEPROM.h"



void EEPROM_voidWriteDataByte(u16 Copy_u16ByteAddress, u8 Copy_u8Data){

    I2C_voidStartCondition();
    I2C_voidSlaveAddressWrite(UNIQUE_ADDRESS | (A2_PIN << 2) | (Copy_u16ByteAddress >> 8));
    I2C_voidMasterSendData((u8)Copy_u16ByteAddress);
    I2C_voidMasterSendData(Copy_u8Data);
    I2C_voidStopCondition();

    _delay_ms(10); // not 5 because of simulation
}
u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress){

    u8 Local_u8Data;
    I2C_voidStartCondition();
    I2C_voidSlaveAddressWrite(UNIQUE_ADDRESS | (A2_PIN << 2) | (Copy_u16ByteAddress >> 8));
    I2C_voidMasterSendData((u8)Copy_u16ByteAddress);

    I2C_voidStartCondition();
    I2C_voidSlaveAddressRead(UNIQUE_ADDRESS | (A2_PIN << 2) | (Copy_u16ByteAddress >> 8));

    Local_u8Data = I2C_u8MasterReceiveData();
    I2C_voidStopCondition();
    
    return Local_u8Data;
}
