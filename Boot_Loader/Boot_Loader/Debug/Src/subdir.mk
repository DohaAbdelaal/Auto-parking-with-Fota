################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ABL_Program.c \
../Src/APARSER_Program.c \
../Src/MFDI_Program.c \
../Src/MGPIO_Program.c \
../Src/MNVIC_Program.c \
../Src/MRCC_Program.c \
../Src/MSTK_Program.c \
../Src/MUSART_Program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ABL_Program.o \
./Src/APARSER_Program.o \
./Src/MFDI_Program.o \
./Src/MGPIO_Program.o \
./Src/MNVIC_Program.o \
./Src/MRCC_Program.o \
./Src/MSTK_Program.o \
./Src/MUSART_Program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ABL_Program.d \
./Src/APARSER_Program.d \
./Src/MFDI_Program.d \
./Src/MGPIO_Program.d \
./Src/MNVIC_Program.d \
./Src/MRCC_Program.d \
./Src/MSTK_Program.d \
./Src/MUSART_Program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ABL_Program.cyclo ./Src/ABL_Program.d ./Src/ABL_Program.o ./Src/ABL_Program.su ./Src/APARSER_Program.cyclo ./Src/APARSER_Program.d ./Src/APARSER_Program.o ./Src/APARSER_Program.su ./Src/MFDI_Program.cyclo ./Src/MFDI_Program.d ./Src/MFDI_Program.o ./Src/MFDI_Program.su ./Src/MGPIO_Program.cyclo ./Src/MGPIO_Program.d ./Src/MGPIO_Program.o ./Src/MGPIO_Program.su ./Src/MNVIC_Program.cyclo ./Src/MNVIC_Program.d ./Src/MNVIC_Program.o ./Src/MNVIC_Program.su ./Src/MRCC_Program.cyclo ./Src/MRCC_Program.d ./Src/MRCC_Program.o ./Src/MRCC_Program.su ./Src/MSTK_Program.cyclo ./Src/MSTK_Program.d ./Src/MSTK_Program.o ./Src/MSTK_Program.su ./Src/MUSART_Program.cyclo ./Src/MUSART_Program.d ./Src/MUSART_Program.o ./Src/MUSART_Program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

