################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BUTTONH.c \
../ButtonApp.c \
../CLOCK.c \
../DIO_prog.c \
../GIE_prog.c \
../KEYPAD7SEGAPP.c \
../KEYPADH.c \
../LED.c \
../LedTog.c \
../OS.c \
../OS_cfg.c \
../SEVENSEGH.c \
../TIMER.c \
../main.c 

OBJS += \
./BUTTONH.o \
./ButtonApp.o \
./CLOCK.o \
./DIO_prog.o \
./GIE_prog.o \
./KEYPAD7SEGAPP.o \
./KEYPADH.o \
./LED.o \
./LedTog.o \
./OS.o \
./OS_cfg.o \
./SEVENSEGH.o \
./TIMER.o \
./main.o 

C_DEPS += \
./BUTTONH.d \
./ButtonApp.d \
./CLOCK.d \
./DIO_prog.d \
./GIE_prog.d \
./KEYPAD7SEGAPP.d \
./KEYPADH.d \
./LED.d \
./LedTog.d \
./OS.d \
./OS_cfg.d \
./SEVENSEGH.d \
./TIMER.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


