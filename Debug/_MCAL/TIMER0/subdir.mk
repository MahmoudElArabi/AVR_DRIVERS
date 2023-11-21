################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_MCAL/TIMER0/TMR0_Program.c 

OBJS += \
./_MCAL/TIMER0/TMR0_Program.o 

C_DEPS += \
./_MCAL/TIMER0/TMR0_Program.d 


# Each subdirectory must supply rules for building sources it contributes
_MCAL/TIMER0/%.o: ../_MCAL/TIMER0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI_PRO\WS\AVR_DRIVERS\FreeRTOS" -I"D:\NTI_PRO\WS\AVR_DRIVERS\FreeRTOS\Source\include" -I"D:\NTI_PRO\WS\AVR_DRIVERS\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


