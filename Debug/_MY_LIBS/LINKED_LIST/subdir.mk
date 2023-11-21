################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_MY_LIBS/LINKED_LIST/linked_list.c 

OBJS += \
./_MY_LIBS/LINKED_LIST/linked_list.o 

C_DEPS += \
./_MY_LIBS/LINKED_LIST/linked_list.d 


# Each subdirectory must supply rules for building sources it contributes
_MY_LIBS/LINKED_LIST/%.o: ../_MY_LIBS/LINKED_LIST/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI_PRO\WS\AVR_DRIVERS\FreeRTOS" -I"D:\NTI_PRO\WS\AVR_DRIVERS\FreeRTOS\Source\include" -I"D:\NTI_PRO\WS\AVR_DRIVERS\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


