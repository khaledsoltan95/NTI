################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MAP.c 

OBJS += \
./Inc/MAP.o 

C_DEPS += \
./Inc/MAP.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/MAP.o: ../Inc/MAP.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Inc/MAP.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

