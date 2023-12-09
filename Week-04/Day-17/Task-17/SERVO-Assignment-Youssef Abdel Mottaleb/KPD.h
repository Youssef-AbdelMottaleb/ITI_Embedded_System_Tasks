/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: KPD						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Friday, August 25, 2023   ******************************/
/*********************************************************************************/

#ifndef     KPD_H
#define     KPD_H

#define     KPD_PORT        DIO_PORTA

#define     KPD_R1_PIN      DIO_PIN0
#define     KPD_R2_PIN      DIO_PIN1
#define     KPD_R3_PIN      DIO_PIN2
#define     KPD_R4_PIN      DIO_PIN3

#define     KPD_C1_PIN      DIO_PIN4
#define     KPD_C2_PIN      DIO_PIN5
#define     KPD_C3_PIN      DIO_PIN6
#define     KPD_C4_PIN      DIO_PIN7


#define     OUTPUTROWS_INPUTCOLUMNS     0b00001111
#define     INPUTROWS_OUTPUTCOLUMNS     0b11110000

//  CONFIGURATION
/*************************************************************/
/**                 KPD Options:                            **/
/**                 OUTPUTROWS_INPUTCOLUMNS                 **/
/**                 INPUTROWS_OUTPUTCOLUMNS                 **/
/*************************************************************/

#define     KPD_CONTROL     OUTPUTROWS_INPUTCOLUMNS

#define     KPD_CHECK_KEY       0xff

void KPD_voidInit(void);
u8 KPD_u8GetPressedKey(void);

#endif
