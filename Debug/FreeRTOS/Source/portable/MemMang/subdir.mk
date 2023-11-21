################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/portable/MemMang/heap_1.c 

OBJS += \
./FreeRTOS/Source/portable/MemMang/heap_1.o 

C_DEPS += \
./FreeRTOS/Source/portable/MemMang/heap_1.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/MemMang/%.o: ../FreeRTOS/Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI_PRO\WS\AVR_DRIVERS\FreeRTOS" -I"D:\NTI_PRO\WS\AVR_DRIVERS\FreeRTOS\Source\include" -I"D:\NTI_PRO\WS\AVR_DRIVERS\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


