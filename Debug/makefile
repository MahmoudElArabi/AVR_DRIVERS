################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include _MY_LIBS/LINKED_LIST/subdir.mk
-include _MCAL/WDT/subdir.mk
-include _MCAL/UART/subdir.mk
-include _MCAL/TWI/subdir.mk
-include _MCAL/TIMER2/subdir.mk
-include _MCAL/TIMER1/subdir.mk
-include _MCAL/TIMER0/subdir.mk
-include _MCAL/SPI/subdir.mk
-include _MCAL/PORT/subdir.mk
-include _MCAL/HICU/subdir.mk
-include _MCAL/GI/subdir.mk
-include _MCAL/EXTI/subdir.mk
-include _MCAL/DIO/subdir.mk
-include _MCAL/ADC/subdir.mk
-include _HAL/ULTRA_SONIC/subdir.mk
-include _HAL/Shceduler/subdir.mk
-include _HAL/SERVO/subdir.mk
-include _HAL/LCD/subdir.mk
-include _HAL/KEYPAD/subdir.mk
-include _HAL/EXT_EEPROM/subdir.mk
-include _HAL/DCMotor/subdir.mk
-include _HAL/7SEGMENTS/subdir.mk
-include _APPL/subdir.mk
-include FreeRTOS/Source/portable/MemMang/subdir.mk
-include FreeRTOS/Source/portable/GCC/ATMega323/subdir.mk
-include FreeRTOS/Source/subdir.mk
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
AVR_DRIVERS.lss \

FLASH_IMAGE += \
AVR_DRIVERS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVR_DRIVERS.elf secondary-outputs

# Tool invocations
AVR_DRIVERS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_DRIVERS.map -mmcu=atmega32 -o "AVR_DRIVERS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_DRIVERS.lss: AVR_DRIVERS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_DRIVERS.elf  >"AVR_DRIVERS.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_DRIVERS.hex: AVR_DRIVERS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_DRIVERS.elf  "AVR_DRIVERS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_DRIVERS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_DRIVERS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_DRIVERS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
