#include "BIT_MATH.h"
#include "STD_TYPES.h"

extern u16 _EndOfSRAM;
extern u16 _erodata;
extern u16 _sdata;
extern u16 _edata;
extern u16 _sbss;
extern u16 _ebss;

#define     SP      *((volatile u16*) 0x5D)

void main(void);

void Start(void);
void _initalize_Data(void);
void _initalize_Bss(void);

void bad_vector(void);

void __vector_1(void)  __attribute__ ((weak, alias("bad_vector")));
void __vector_2(void)  __attribute__ ((weak, alias("bad_vector")));
void __vector_3(void)  __attribute__ ((weak, alias("bad_vector")));
void __vector_4(void)  __attribute__ ((weak, alias("bad_vector")));
void __vector_5(void)  __attribute__ ((weak, alias("bad_vector")));
void __vector_6(void)  __attribute__ ((weak, alias("bad_vector")));
void __vector_7(void)  __attribute__ ((weak, alias("bad_vector")));
void __vector_8(void)  __attribute__ ((weak, alias("bad_vector")));
void __vector_9(void)  __attribute__ ((weak, alias("bad_vector")));
void __vector_10(void) __attribute__ ((weak, alias("bad_vector")));
void __vector_11(void) __attribute__ ((weak, alias("bad_vector")));
void __vector_12(void) __attribute__ ((weak, alias("bad_vector")));
void __vector_13(void) __attribute__ ((weak, alias("bad_vector")));
void __vector_14(void) __attribute__ ((weak, alias("bad_vector")));
void __vector_15(void) __attribute__ ((weak, alias("bad_vector")));
void __vector_16(void) __attribute__ ((weak, alias("bad_vector")));
void __vector_17(void) __attribute__ ((weak, alias("bad_vector")));
void __vector_18(void) __attribute__ ((weak, alias("bad_vector")));
void __vector_19(void) __attribute__ ((weak, alias("bad_vector")));
void __vector_20(void) __attribute__ ((weak, alias("bad_vector")));

void (*VectorTable[])(void) __attribute__((section(".isr_section_input"))) = 
{
    Start,
    __vector_1,
    __vector_2,
    __vector_3,
    __vector_4,
    __vector_5,
    __vector_6,
    __vector_7,
    __vector_8,
    __vector_9,
    __vector_10,
    __vector_11,
    __vector_12,
    __vector_13,
    __vector_14,
    __vector_15,
    __vector_16,
    __vector_17,
    __vector_18,
    __vector_19,
    __vector_20,
};

void Start(void)
{
    // Initalize Stack Pointer
    SP = _EndOfSRAM;
    // Initailize Vector Table
    // Initalize data
    _initalize_Data();
    // Initalize bss
    _initalize_Bss();
    // Call main
    main();
    // Infinite Loop
    while(1);
}

void _initalize_Data(void)
{
    u16* Source = (u16*)&_erodata;
    u16* Distination = (u16*)&_sdata;

    while (Distination < (u16*)_edata)
    {
        *Distination = *Source;
        Distination++;
        Source++;
    }
    
}

void _initalize_Bss(void)
{
    u16* Distination = (u16*)&_sbss;

    while (Distination < (u16*)_ebss)
    {
        *Distination = 0;
        Distination++;
    }
    

}

void bad_vector(void)
{
    while(1);
}