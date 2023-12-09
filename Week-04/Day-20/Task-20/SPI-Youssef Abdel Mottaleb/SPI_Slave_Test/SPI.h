/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: SPI						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Thursday, August 31, 2023 ******************************/
/*********************************************************************************/

#ifdef      SPI_H
#define     SPI_H

#define     SPI_SLAVE       0
#define     SPI_MSTR        1
#define     SPI_MODE        SPI_SLAVE

void SPI_voidInit(void);
//void SPI_voidTransmit(u8 Copy_u8Data);
u8 SPI_u8Tranceive(u8 Copy_u8Data);
//u8 SPI_u8Receive(void);



#endif
