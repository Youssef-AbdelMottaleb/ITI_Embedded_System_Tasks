/*
 * main.c
 *
 *  Created on: Aug 29, 2023
 *      Author: youss
 */

#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "LCD.h"
#include "KPD.h"
#include "SERVO.h"

int main(){

    /* Initialize Modules */
    DIO_voidSetPortDirection(KPD_PORT, INPUTROWS_OUTPUTCOLUMNS);  // Keypad Rows as Outputs, Columns as Inputs
    KPD_voidInit();
    LCD_voidInit();
    SERVO_voidInitTimer1M14();

    u8 angleString[4];  // To store user input angle as a string
    u8 angle;           // To store converted angle

    while(1) {
        // Clear LCD and display instructions
        LCD_voidSendCommand(CLEAR_DISPLAY);
        LCD_voidSendString("Enter Angle:");

        // Get user input using keypad
        u8 keyPressed;
        u8 digitCount = 0;
        while (1) {
            keyPressed = KPD_u8GetPressedKey();
            if (keyPressed >= '0' && keyPressed <= '9') {
                // Display the pressed digit on LCD
                LCD_voidSendChar(keyPressed);
                angleString[digitCount] = keyPressed;
                digitCount++;
            } else if (keyPressed == '=') {
                // Convert the angle string to an integer
                angleString[digitCount] = '\0';  // Null-terminate the string
                angle = (u16)(angleString);        // Convert string to integer
                if (angle >= 0 && angle <= 180) {
                    // Set servo angle and exit loop
                    SERVO_voidSetAngle(angle);
                    break;
                } else {
                    // Display error message and wait
                    LCD_voidSendCommand(CLEAR_DISPLAY);
                    LCD_voidSendString("Invalid Angle!");
                    _delay_ms(1000);
                    // Clear error message
                    LCD_voidSendCommand(CLEAR_DISPLAY);
                }
            }
        }

        // Wait for a short time before taking the next input
        _delay_ms(500);
    }

    return 0;
}
