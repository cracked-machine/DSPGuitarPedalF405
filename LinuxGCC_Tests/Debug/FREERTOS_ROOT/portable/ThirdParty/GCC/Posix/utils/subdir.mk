################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c 

OBJS += \
./FREERTOS_ROOT/portable/ThirdParty/GCC/Posix/utils/wait_for_event.o 

C_DEPS += \
./FREERTOS_ROOT/portable/ThirdParty/GCC/Posix/utils/wait_for_event.d 


# Each subdirectory must supply rules for building sources it contributes
FREERTOS_ROOT/portable/ThirdParty/GCC/Posix/utils/wait_for_event.o: /opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Inc" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FSM" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/ThirdParty/GCC/Posix" -I"/home/chris/DSPGuitarPedalF405/LinuxGCC_Tests" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


