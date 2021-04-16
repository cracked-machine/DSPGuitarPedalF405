################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/opt/FreeRTOSv202012.00/FreeRTOS/Source/croutine.c \
/opt/FreeRTOSv202012.00/FreeRTOS/Source/event_groups.c \
/opt/FreeRTOSv202012.00/FreeRTOS/Source/list.c \
/opt/FreeRTOSv202012.00/FreeRTOS/Source/queue.c \
/opt/FreeRTOSv202012.00/FreeRTOS/Source/stream_buffer.c \
/opt/FreeRTOSv202012.00/FreeRTOS/Source/tasks.c \
/opt/FreeRTOSv202012.00/FreeRTOS/Source/timers.c 

C_DEPS += \
./FREERTOS_ROOT/croutine.d \
./FREERTOS_ROOT/event_groups.d \
./FREERTOS_ROOT/list.d \
./FREERTOS_ROOT/queue.d \
./FREERTOS_ROOT/stream_buffer.d \
./FREERTOS_ROOT/tasks.d \
./FREERTOS_ROOT/timers.d 

OBJS += \
./FREERTOS_ROOT/croutine.o \
./FREERTOS_ROOT/event_groups.o \
./FREERTOS_ROOT/list.o \
./FREERTOS_ROOT/queue.o \
./FREERTOS_ROOT/stream_buffer.o \
./FREERTOS_ROOT/tasks.o \
./FREERTOS_ROOT/timers.o 


# Each subdirectory must supply rules for building sources it contributes
FREERTOS_ROOT/croutine.o: /opt/FreeRTOSv202012.00/FreeRTOS/Source/croutine.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREERTOS_ROOT/croutine.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
FREERTOS_ROOT/event_groups.o: /opt/FreeRTOSv202012.00/FreeRTOS/Source/event_groups.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREERTOS_ROOT/event_groups.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
FREERTOS_ROOT/list.o: /opt/FreeRTOSv202012.00/FreeRTOS/Source/list.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREERTOS_ROOT/list.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
FREERTOS_ROOT/queue.o: /opt/FreeRTOSv202012.00/FreeRTOS/Source/queue.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREERTOS_ROOT/queue.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
FREERTOS_ROOT/stream_buffer.o: /opt/FreeRTOSv202012.00/FreeRTOS/Source/stream_buffer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREERTOS_ROOT/stream_buffer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
FREERTOS_ROOT/tasks.o: /opt/FreeRTOSv202012.00/FreeRTOS/Source/tasks.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREERTOS_ROOT/tasks.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
FREERTOS_ROOT/timers.o: /opt/FreeRTOSv202012.00/FreeRTOS/Source/timers.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREERTOS_ROOT/timers.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

