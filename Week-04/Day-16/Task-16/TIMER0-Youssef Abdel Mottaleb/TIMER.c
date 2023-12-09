/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: ADC						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Saturday, August 27, 2023******************************/
/*********************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER.h"

void (*TIMER0_PFvoidOVFCall) (void) = ((void *)0);
void (*TIMER0_PFvoidCTCCall) (void) = ((void *)0);

void TIMER0_voidInit(){
    #if TIMER0_MODE == TIMER0_OVF_MODE
        /* 1-select timer0 mode ==> normal mode*/
        CLR_BIT(TCCR0,WGM00);
        CLR_BIT(TCCR0,WGM01);

        /* 2-select prescaler ==> /8 */
        CLR_BIT(TCCR0, CS00);
        SET_BIT(TCCR0, CS01);
        CLR_BIT(TCCR0, CS02);

        /* 3-set preload value ==> 192* */
        TCNT0 = 192;

        /* 4-Enable of Interrupt */
        SET_BIT(TIMSK, TOIE0);

    #elif   TIMER0_MODE == TIMER0_CTC_MODE
        /* 1-select timer0 mode ==> CTC mode*/
        CLR_BIT(TCCR0,WGM00);
        SET_BIT(TCCR0,WGM01);

        /* 2-select prescaler ==> /8 */
        CLR_BIT(TCCR0, CS00);
        SET_BIT(TCCR0, CS01);
        CLR_BIT(TCCR0, CS02);

        /* 3-set preload value ==> 99* */
        OCR0 = 99;

        /* 4-Enable CTC Interrupt */
        SET_BIT(TIMSK, OCIE0);

	#elif   TIMER0_MODE == TIMER0_FPWM_MODE
        /* 1-select timer0 mode ==> Fast PWM mode*/
        SET_BIT(TCCR0, WGM00);
        SET_BIT(TCCR0, WGM01);

        /* 2-Select 0C0 Action */
        CLR_BIT(TCCR0, COM00);
        SET_BIT(TCCR0, COM01);

        /* 3-select prescaler ==> /8 */
        CLR_BIT(TCCR0, CS00);
        SET_BIT(TCCR0, CS01);
        CLR_BIT(TCCR0, CS02);

	#elif   TIMER0_MODE == TIMER0_PHC_MODE;
		/* 1-select timer0 mode ==> PHC PWM mode*/
		SET_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);

		/* 2-Select 0C0 Action */
		CLR_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);

		/* 3-select prescaler ==> /8 */
		CLR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);



	#endif

}

void TIMER0_voidSetCallBack(void (*Copy_PFvoidName) (void)){

    #if TIMER0_MODE == TIMER0_OVF_MODE
        TIMER0_PFvoidOVFCall = Copy_PFvoidName;
    #elif TIMER0_MODE == TIMER0_CTC_MODE
        TIMER0_PFvoidCTCCall = Copy_PFvoidName;
	#endif

}

void TIMER0_voidSetOCR0Value(u8 Copy_OCR0Value){
	OCR0 = Copy_OCR0Value;
}


ISR(TIMER0_OVF_vect){

	static u16 Local_u16OVFCounter = 0;
	Local_u16OVFCounter++;
	if(Local_u16OVFCounter == 3907){
		/* set preload value ==> 192 */
		TCNT0 = 192;
		/* clear counter */
		Local_u16OVFCounter = 0;
		/* action */
		TIMER0_PFvoidOVFCall();
	}
}   

ISR(TIMER0_COMP_vect){

	static u16 Local_u16CTCCounter = 0;
	Local_u16CTCCounter++;
    if(Local_u16CTCCounter == 10000){
        /* Action */
        TIMER0_PFvoidCTCCall();
        /* clear counter */
        Local_u16CTCCounter = 0;
    }
}
