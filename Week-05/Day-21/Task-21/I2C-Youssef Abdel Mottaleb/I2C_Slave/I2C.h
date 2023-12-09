/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: I2C						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Sunday, September 3, 2023 ******************************/
/*********************************************************************************/

#ifdef      I2C_H
#define     I2C_H

void I2C_voidMasterInit(void);
void I2C_voidSlaveInit(u8 Copy_u8SlaveAddress);

void I2C_voidStartCondition(void);
void I2C_voidStopCondition(void);

void I2C_voidSlaveAddressWrite(u8 Copy_u8SlaveAddress);
void I2C_voidSlaveAddressRead(u8 Copy_u8SlaveAddress);

void I2C_voidMasterSendData(u8 Copy_u8Data);

u8 I2C_u8MasterReceiveData(void);
u8 I2C_u8SlaveReceiveData(void);

#endif