/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: ADC						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Wednesday, August 23, 2023******************************/
/*********************************************************************************/


#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "LCD.h"

void LCD_voidSendCommand(u8 Copy_u8Command){

    DIO_voidSetPinValue(LCD_CONTROL_PORT, RS, DIO_LOW);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RW, DIO_LOW);

    DIO_voidSetPortValue(LCD_Data_PORT, Copy_u8Command);

    DIO_voidSetPinValue(LCD_CONTROL_PORT, E, DIO_HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, E, DIO_LOW);

}

void LCD_voidSendChar(u8 Copy_u8Char){

    DIO_voidSetPinValue(LCD_CONTROL_PORT, RS, DIO_HIGH);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RW, DIO_LOW);

    DIO_voidSetPortValue(LCD_Data_PORT, Copy_u8Char);

    DIO_voidSetPinValue(LCD_CONTROL_PORT, E, DIO_HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, E, DIO_LOW);
}


void LCD_voidInit(void){
    // Data Port Direction --> OUTPUT
    DIO_voidSetPortDirection(LCD_Data_PORT, 0xff);
    // Control Pins Direction --> OUTPUT
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, E, DIO_OUTPUT);

    // DELAY FOR 30 milliseconds
    _delay_ms(30);

    LCD_voidSendCommand(FUNCTION_SET);
    // DELAY FOR 40 microseconds
    _delay_us(40);

    LCD_voidSendCommand(ON_OFF_DISPLAY);
    // DELAY FOR 40 microseconds
    _delay_us(40);

    LCD_voidSendCommand(CLEAR_DISPLAY);
    // DELAY FOR 2 microseconds
    _delay_ms(2);

}

void LCD_voidSendString(u8* Copy_u8PString){

    u8 Local_u8Counter;
    for ( Local_u8Counter = 0; Copy_u8PString[Local_u8Counter] != "\0"; Local_u8Counter++)
    {
        LCD_voidSendChar(Copy_u8PString[Local_u8Counter]);
    }

}

void LCD_voidSendSpecialChar(u8 Copy_u8CharAddress, u8* Copy_u8PASpecialChar){

    LCD_voidSendCommand(CG_BASE_ADDRESS + Copy_u8CharAddress * 8);
    u8 Local_u8Counter;
    for ( Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
    {
        LCD_voidSendChar(Copy_u8PASpecialChar[Local_u8Counter]);
    }
    //LCD_voidSendCommand(0x80);
}

void LCD_voidSetLocation(u8 Copy_u8Line, u8 Copy_u8CharNum){

    switch (Copy_u8Line)
    {
    case LCD_LINE1:
        LCD_voidSendCommand(LCD_L1_BASE_ADDRESS + Copy_u8CharNum);
        break;

    case LCD_LINE2:
        LCD_voidSendCommand(LCD_L2_BASE_ADDRESS + Copy_u8CharNum);
        break;

    default:
        break;
    }
}


void LCD_voidSendNumber(s32 Copy_s32Number)
{
	u32 Local_u32Counter=1 ;
	u8 Local_u32Digit=0 ;

	/* print (-) if the number is negative */
	if(Copy_s32Number < 0)
	{
		LCD_voidSendChar('-');
		/* return the number to positive */
		Copy_s32Number = -Copy_s32Number;
	}
	if (Copy_s32Number == 0)
		LCD_voidSendChar('0');
	else
	{
		while (Copy_s32Number/Local_u32Counter != 0)
		{
			Local_u32Counter *= 10;
		}
		Local_u32Counter /=10;

		while (Local_u32Counter != 0)
		{
			Local_u32Digit = Copy_s32Number/Local_u32Counter;

			LCD_voidSendChar(Local_u32Digit + '0');

			Copy_s32Number = Copy_s32Number%Local_u32Counter;

			Local_u32Counter /= 10;
		}
	}
}
