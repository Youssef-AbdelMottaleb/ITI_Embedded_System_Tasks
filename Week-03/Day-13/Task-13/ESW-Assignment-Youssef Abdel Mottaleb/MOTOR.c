/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: MOTOR						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Friday, August 25, 2023   ******************************/
/*********************************************************************************/

#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "LCD.h"
#include "MOTOR.h"


void MOTOR_voidInit(void){
    // set the pin of STPM OUTPUT
	DIO_voidSetPinDirection(MOTOR_PORT, DIO_PIN0, DIO_OUTPUT);
	DIO_voidSetPinDirection(MOTOR_PORT, DIO_PIN1, DIO_OUTPUT);
	DIO_voidSetPinDirection(MOTOR_PORT, DIO_PIN2, DIO_OUTPUT);
	DIO_voidSetPinDirection(MOTOR_PORT, DIO_PIN3, DIO_OUTPUT);
}

void MOTOR_voidClockwiseRotation(u8 Copy_u8Step)
{

	for(u8 Localu8Count = 0; Localu8Count < Copy_u8Step/4; Localu8Count++)
	{
		// blue
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN0, DIO_HIGH);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN1, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN2, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN3, DIO_LOW);
		// because proteus work on 200 ms
		_delay_ms(200);

		// pink
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN0, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN1, DIO_HIGH);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN2, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN3, DIO_LOW);
		// because proteus work on 200 ms
		_delay_ms(200);

		// yellow
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN0, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN1, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN2, DIO_HIGH);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN3, DIO_LOW);
		// because proteus work on 200 ms
		_delay_ms(200);

		// orange
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN0, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN1, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN2, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN3, DIO_HIGH);
		// because proteus work on 200 ms
		_delay_ms(200);
	}
}

void MOTOR_voidCounterClockwiseRotation(u8 Copy_u8Step)
{

	for(u8 Localu8Count = 0; Localu8Count < Copy_u8Step/4; Localu8Count++)
	{
		// blue
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN0, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN1, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN2, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN3, DIO_HIGH);
		// because proteus work on 200 ms
		_delay_ms(200);

		// pink
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN0, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN1, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN2, DIO_HIGH);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN3, DIO_LOW);
		// because proteus work on 200 ms
		_delay_ms(200);

		// yellow
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN0, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN1, DIO_HIGH);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN2, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN3, DIO_LOW);
		// because proteus work on 200 ms
		_delay_ms(200);

		// orange
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN0, DIO_HIGH);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN1, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN2, DIO_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, DIO_PIN3, DIO_LOW);
		// because proteus work on 200 ms
		_delay_ms(200);
	}
}

u8 MOTOR_u8NumOfIterations(u8 Copy_u8CustomAngle){
    u8 Local_u8StepAngle = Copy_u8CustomAngle/(0.1);
    u8 Local_u8NumOfLoops = (Copy_u8CustomAngle / Local_u8StepAngle) / 4;
    return Local_u8NumOfLoops;
}
