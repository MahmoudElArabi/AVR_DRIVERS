################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_MCAL/TWI/TWI_Program.c 

OBJS += \
./_MCAL/TWI/TWI_Program.o 

C_DEPS += \
./_MCAL/TWI/TWI_Program.d 


# Each subdirectory must supply rules for building sources it contributes
_MCAL/TWI/%.o: ../_MCAL/TWI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


