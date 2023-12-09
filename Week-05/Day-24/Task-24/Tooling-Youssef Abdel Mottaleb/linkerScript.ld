

MEMORY
{
    FLASH (rx) : ORIGIN = 0x0000, LENGTH = 32K
    SRAM (rw) : ORIGIN = 0x0060, LENGTH = 2K
}

_EndOfSRAM = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS
{
    .isr_section :
    {
        . = ALIGN(2);
        *(.isr_section_input)
        . = ALIGN(2);
    }> FLASH

    .text :
    {
        . = ALIGN(2);
        *(.text)
        *(.text*)
        . = ALIGN(2);
    }> FLASH

    .rodata :
    {
        . = ALIGN(2);
        *(.rodata)
        . = ALIGN(2);
        _erodata = .;
    }> FLASH


    .data :
    {
        . = ALIGN(2);
        _sdata = .;
        *(.data)
        _edata = .;
        . = ALIGN(2);
    }> SRAM AT> FLASH

    .bss :
    {
        . = ALIGN(2);
        _sbss = .;
        *(.bss)
        *(COMMON)
        _ebss = .;
        . = ALIGN(2);
    }> SRAM
}