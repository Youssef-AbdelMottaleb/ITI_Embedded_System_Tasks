/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: SERVO						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Monday, August 28, 2023   ******************************/
/*********************************************************************************/

#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "SERVO.h"

void SERVO_voidInitTimer1M14(void){

    /* select mode 14 */
    CLR_BIT(TCCR1A, WGM10);
    SET_BIT(TCCR1A, WGM11);

    SET_BIT(TCCR1B, WGM12);
    SET_BIT(TCCR1B, WGM13);

    /* select OC1A Action */
    CLR_BIT(TCCR1A, COM1A0);
    SET_BIT(TCCR1A, COM1A1);

    /* Select the prescalar ==> /8 */
    CLR_BIT(TCCR1B, CS10);
    SET_BIT(TCCR1B, CS11);
    CLR_BIT(TCCR1B, CS12);

    /* SET ICR1 Value (20ms) */
    ICR1 = 19999;

    /* Angle Init (1ms) ==> -90 = 0 */
    OCR1A = 999;
}

void SERVO_voidSetAngle(u8 Copy_u8Angle){

    // CAST TO (u32)
    OCR1A = (((Copy_u8Angle * 1000UL) / 180) + 999);
}
