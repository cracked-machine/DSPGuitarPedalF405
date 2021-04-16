################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c 

C_DEPS += \
./FREERTOS_ROOT/portable/GCC/ARM_CM4F/port.d 

OBJS += \
./FREERTOS_ROOT/portable/GCC/ARM_CM4F/port.o 


# Each subdirectory must supply rules for building sources it contributes
FREERTOS_ROOT/portable/GCC/ARM_CM4F/port.o: /opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREERTOS_ROOT/portable/GCC/ARM_CM4F/port.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

