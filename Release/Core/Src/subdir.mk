################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/button.c \
../Core/Src/fsm_auto.c \
../Core/Src/fsm_manual.c \
../Core/Src/fsm_setting.c \
../Core/Src/fsm_slow.c \
../Core/Src/global.c \
../Core/Src/i2c-lcd.c \
../Core/Src/led_display.c \
../Core/Src/main.c \
../Core/Src/stm32f0xx_hal_msp.c \
../Core/Src/stm32f0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f0xx.c \
../Core/Src/timer.c 

OBJS += \
./Core/Src/button.o \
./Core/Src/fsm_auto.o \
./Core/Src/fsm_manual.o \
./Core/Src/fsm_setting.o \
./Core/Src/fsm_slow.o \
./Core/Src/global.o \
./Core/Src/i2c-lcd.o \
./Core/Src/led_display.o \
./Core/Src/main.o \
./Core/Src/stm32f0xx_hal_msp.o \
./Core/Src/stm32f0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f0xx.o \
./Core/Src/timer.o 

C_DEPS += \
./Core/Src/button.d \
./Core/Src/fsm_auto.d \
./Core/Src/fsm_manual.d \
./Core/Src/fsm_setting.d \
./Core/Src/fsm_slow.d \
./Core/Src/global.d \
./Core/Src/i2c-lcd.d \
./Core/Src/led_display.d \
./Core/Src/main.d \
./Core/Src/stm32f0xx_hal_msp.d \
./Core/Src/stm32f0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f0xx.d \
./Core/Src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F031x6 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

