/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: ADC						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Wednesday, August 23, 2023******************************/
/*********************************************************************************/


#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "ADC.h"

void ADC_voidInit(void){
    // enable adc
    SET_BIT(ADCSRA, ADEN);

    // SELECT V ref --> AVCC = 5V
    SET_BIT(ADMUX, REFS0);
    CLR_BIT(ADMUX, REFS1);

    // Right Adjust
    CLR_BIT(ADMUX, ADLAR);

    // Disable Auto Trig
    CLR_BIT(ADCSRA, ADATE);

    // SELECT Prescalar
    CLR_BIT(ADCSRA, ADPS0);
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS2);
}

u16 ADC_u16GetDigitalValue(u8 Copy_u8ChannelNum){

    // SELECT CHANNEL
    ADMUX &= ADC_CHANNEL_RESET;
    ADMUX |= Copy_u8ChannelNum;

    // START CONVERSION
    SET_BIT(ADCSRA, ADSC);

    // WAIT UNTILL THE FLAG EQUAL 1
    while (GET_BIT(ADCSRA, ADIF) == 0);

    //CLEAR THE FLAG
    SET_BIT(ADCSRA, ADIF);

    // READ THE DIGITAL VALUE
    return ADC_REG;
    
}