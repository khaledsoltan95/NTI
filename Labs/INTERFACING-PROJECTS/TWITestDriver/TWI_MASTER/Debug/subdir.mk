################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_Prog.c \
../DIO_Prog.c \
../MAP.c \
../PORT_Prog.c \
../TWI_Prog.c \
../main.c 

OBJS += \
./CLCD_Prog.o \
./DIO_Prog.o \
./MAP.o \
./PORT_Prog.o \
./TWI_Prog.o \
./main.o 

C_DEPS += \
./CLCD_Prog.d \
./DIO_Prog.d \
./MAP.d \
./PORT_Prog.d \
./TWI_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

