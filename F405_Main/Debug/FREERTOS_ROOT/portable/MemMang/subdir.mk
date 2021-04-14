################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MemMang/heap_1.c 

C_DEPS += \
./FREERTOS_ROOT/portable/MemMang/heap_1.d 

OBJS += \
./FREERTOS_ROOT/portable/MemMang/heap_1.o 


# Each subdirectory must supply rules for building sources it contributes
FREERTOS_ROOT/portable/MemMang/heap_1.o: /opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MemMang/heap_1.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Inc" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREERTOS_ROOT/portable/MemMang/heap_1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

