################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/AppMain.cpp \
../Application/PeriphInterrupts.cpp \
../Application/SystemInterrupts.cpp \
../Application/pedal_io_test.cpp 

OBJS += \
./Application/AppMain.o \
./Application/PeriphInterrupts.o \
./Application/SystemInterrupts.o \
./Application/pedal_io_test.o 

CPP_DEPS += \
./Application/AppMain.d \
./Application/PeriphInterrupts.d \
./Application/SystemInterrupts.d \
./Application/pedal_io_test.d 


# Each subdirectory must supply rules for building sources it contributes
Application/AppMain.o: ../Application/AppMain.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Application/AppMain.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/PeriphInterrupts.o: ../Application/PeriphInterrupts.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Application/PeriphInterrupts.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/SystemInterrupts.o: ../Application/SystemInterrupts.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Application/SystemInterrupts.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/pedal_io_test.o: ../Application/pedal_io_test.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DSTM32F405xx -DUSE_HAL_DRIVER -DDEBUG -c -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Application/pedal_io_test.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

