#ifndef LCD_H
#define LCD_H

// Port configuration
#define LCD_Data_PORT  DIO_PORTC
#define LCD_CONTROL_PORT  DIO_PORTB

// Pin configuration
#define RS      DIO_PIN0
#define RW      DIO_PIN1
#define E       DIO_PIN2

#define FUNCTION_SET     0b00111000
#define ON_OFF_DISPLAY   0b00001111
#define CLEAR_DISPLAY    0b00000001
#define CG_BASE_ADDRESS     0b01000000


void LCD_voidInit(void);
void LCD_voidSendChar(u8 Copy_u8Char);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendString(u8* Copy_u8PString);
void LCD_voidSendSpecialChar(u8 Copy_u8CharAddress, u8* Copy_u8PASpecialChar);
void LCD_voidSendNumber(s32 Copy_s32Number);

#endif
