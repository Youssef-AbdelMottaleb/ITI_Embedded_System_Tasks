################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ESW_Assignment.lss \

FLASH_IMAGE += \
ESW_Assignment.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ESW_Assignment.elf secondary-outputs

# Tool invocations
ESW_Assignment.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ESW_Assignment.map -mmcu=atmega32 -o "ESW_Assignment.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ESW_Assignment.lss: ESW_Assignment.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ESW_Assignment.elf  >"ESW_Assignment.lss"
	@echo 'Finished building: $@'
	@echo ' '

ESW_Assignment.hex: ESW_Assignment.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ESW_Assignment.elf  "ESW_Assignment.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ESW_Assignment.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ESW_Assignment.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ESW_Assignment.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
