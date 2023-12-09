/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: I2C						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Sunday, September 3, 2023 ******************************/
/*********************************************************************************/

#ifdef      EEPROM_H
#define     EEPROM_H

#define     A2_PIN              0
#define     UNIQUE_ADDRESS      0x50

void EEPROM_voidWriteDataByte(u16 Copy_u16ByteAddress, u8 Copy_u8Data);
u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress);




#endif
