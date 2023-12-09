/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: ADC						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Wednesday, August 23, 2023******************************/
/*********************************************************************************/


#ifndef LCD_H
#define LCD_H

// Port configuration
#define LCD_Data_PORT  DIO_PORTC
#define LCD_CONTROL_PORT  DIO_PORTA

// Pin configuration
#define RS      DIO_PIN0
#define RW      DIO_PIN1
#define E       DIO_PIN2

#define FUNCTION_SET     0b00111000
#define ON_OFF_DISPLAY   0b00001111
#define CLEAR_DISPLAY    0b00000001
#define CG_BASE_ADDRESS     0b01000000

#define LCD_LINE1       1
#define LCD_LINE2       2

#define LCD_L1_BASE_ADDRESS     0x80
#define LCD_L2_BASE_ADDRESS     0xC0

#define MAX_AMPLITUDE 	2  		// Maximum amplitude of the sine wave
#define FREQUENCY 		1  		// Frequency of the sine wave (in Hz)
#define PHASE_SHIFT 	0  		// Phase shift of the sine wave (in degrees)

void LCD_voidInit(void);
void LCD_voidSendChar(u8 Copy_u8Char);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendString(u8* Copy_u8PString);
void LCD_voidSendSpecialChar(u8 Copy_u8CharAddress, u8* Copy_u8PASpecialChar);
void LCD_voidSetLocation(u8 Copy_u8Line, u8 Copy_u8CharNum);
void LCD_voidSendNumber(s32 Copy_s32Number);
// Function to update the LCD with the sine wave animation
void LCD_voidSineWave(u8* Copy_u8Text);

#endif
