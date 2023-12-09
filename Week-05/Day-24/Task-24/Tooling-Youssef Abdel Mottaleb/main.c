#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO.h"

int main(void){

    volatile u16 Local_u16Counter;

    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);

    while (1)
    {
        DIO_voidTogglePin(DIO_PORTA, DIO_PIN0);
        for (Local_u16Counter = 0; Local_u16Counter < 65000; Local_u16Counter++);

        DIO_voidTogglePin(DIO_PORTA, DIO_PIN1);
        for (Local_u16Counter = 0; Local_u16Counter < 65000; Local_u16Counter++);
    }
    



    return 0;
}