/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: ADC						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Saturday, August 27, 2023******************************/
/*********************************************************************************/


#ifndef     TIMER0_H
#define     TIMER0_H


#define     TIMER0_OVF_MODE     0
#define     TIMER0_CTC_MODE     1
#define     TIMER0_FPWM_MODE    2
#define     TIMER0_PHC_MODE     3

#define     TIMER0_MODE      TIMER0_FPWM_MODE

void TIMER0_voidInit();
void TIMER0_voidSetCallBack(void (*Copy_PFvoidName) (void));
void TIMER0_voidSetOCR0Value(u8 Copy_OCR0Value);


#endif
