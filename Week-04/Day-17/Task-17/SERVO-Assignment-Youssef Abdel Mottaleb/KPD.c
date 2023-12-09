/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: KPD						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Friday, August 25, 2023   ******************************/
/*********************************************************************************/

#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "KPD.h"


u8 KPD_Au8RowPins [4] = {KPD_R1_PIN , KPD_R2_PIN , KPD_R3_PIN , KPD_R4_PIN} ;
u8 KPD_Au8ColPins [4] = {KPD_C1_PIN , KPD_C2_PIN , KPD_C3_PIN , KPD_C4_PIN} ;

u8 KPD_Au8Keys [4][4] =  {	{'7','8','9','/'} ,
							{'4','5','6','*'} ,
							{'1','2','3','-'} ,
							{'C','0','=','+'}
						 } ;

void KPD_voidInit (void)
{
	/*KPD ==> Output Rows Input Columns*/
	DIO_voidSetPortDirection (KPD_PORT , KPD_CONTROL);
	DIO_voidSetPortValue	 (KPD_PORT , 0xff);	/*PORT Direction ==> Rows=>OUTPUT  / Columns==>PULLUP*/
}

u8 KPD_u8GetPressedKey (void)
{
	u8 Local_u8RowCounter , Local_u8ColCounter , Local_u8PressedKey , Local_u8ReturnedValue = KPD_CHECK_KEY , Local_u8Flag=0 ;
	/*Loop for rows*/
	for (Local_u8RowCounter=0 ; Local_u8RowCounter<4 ; Local_u8RowCounter++)
	{
		/*Set Each Rows pin ==> Low*/
		DIO_voidSetPinValue (KPD_PORT , KPD_Au8RowPins[Local_u8RowCounter] , DIO_LOW);
		/*Loop for Colums*/
		for (Local_u8ColCounter=0 ; Local_u8ColCounter<4 ; Local_u8ColCounter++)
		{
			Local_u8PressedKey = DIO_u8GetPinValue(KPD_PORT , KPD_Au8ColPins[Local_u8ColCounter]);
			if(Local_u8PressedKey == DIO_LOW)
			{
				_delay_ms(20); /*To Avoid Bouncing*/
				Local_u8PressedKey = DIO_u8GetPinValue(KPD_PORT , KPD_Au8ColPins[Local_u8ColCounter]);
				while (Local_u8PressedKey == DIO_LOW)
				{
					Local_u8PressedKey = DIO_u8GetPinValue(KPD_PORT , KPD_Au8ColPins[Local_u8ColCounter]);
				}
				Local_u8ReturnedValue = KPD_Au8Keys[Local_u8RowCounter][Local_u8ColCounter];
				Local_u8Flag = 1 ;
				break ;
			}
		}
		DIO_voidSetPinValue (KPD_PORT , KPD_Au8RowPins[Local_u8RowCounter] , DIO_HIGH);
		if (Local_u8Flag == 1) break ;
	}

	return Local_u8ReturnedValue ;
}
