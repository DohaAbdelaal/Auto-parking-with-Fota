################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ESP_program.c \
../Src/GPIO.c \
../Src/MSTK_Program.c \
../Src/NVIC_PROG.c \
../Src/RCC_PROG.c \
../Src/USART_PROG.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ESP_program.o \
./Src/GPIO.o \
./Src/MSTK_Program.o \
./Src/NVIC_PROG.o \
./Src/RCC_PROG.o \
./Src/USART_PROG.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ESP_program.d \
./Src/GPIO.d \
./Src/MSTK_Program.d \
./Src/NVIC_PROG.d \
./Src/RCC_PROG.d \
./Src/USART_PROG.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ESP_program.cyclo ./Src/ESP_program.d ./Src/ESP_program.o ./Src/ESP_program.su ./Src/GPIO.cyclo ./Src/GPIO.d ./Src/GPIO.o ./Src/GPIO.su ./Src/MSTK_Program.cyclo ./Src/MSTK_Program.d ./Src/MSTK_Program.o ./Src/MSTK_Program.su ./Src/NVIC_PROG.cyclo ./Src/NVIC_PROG.d ./Src/NVIC_PROG.o ./Src/NVIC_PROG.su ./Src/RCC_PROG.cyclo ./Src/RCC_PROG.d ./Src/RCC_PROG.o ./Src/RCC_PROG.su ./Src/USART_PROG.cyclo ./Src/USART_PROG.d ./Src/USART_PROG.o ./Src/USART_PROG.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

