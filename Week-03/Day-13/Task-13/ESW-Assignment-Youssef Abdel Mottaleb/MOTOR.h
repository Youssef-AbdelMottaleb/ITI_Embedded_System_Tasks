/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: MOTOR						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Friday, August 25, 2023   ******************************/
/*********************************************************************************/

#ifndef     MOTOR_H
#define     MOTOR_H

#define     MOTOR_PORT      DIO_PORTB

//#define CLOCKWISE           1
//#define COUNTER_CLOCKWISE   2

void MOTOR_voidInit(void);
void MOTOR_voidClockwiseRotation(u8 Copy_u8Step);
void MOTOR_voidCounterClockwiseRotation(u8 Copy_u8Step);
u8 MOTOR_u8NumOfIterations(u8 Copy_u8CustomAngle);

#endif
