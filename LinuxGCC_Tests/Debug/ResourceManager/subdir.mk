################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/chris/DSPGuitarPedalF405/F405_Main/Application/ResourceManager/ResourceManager.cpp 

OBJS += \
./ResourceManager/ResourceManager.o 

CPP_DEPS += \
./ResourceManager/ResourceManager.d 


# Each subdirectory must supply rules for building sources it contributes
ResourceManager/ResourceManager.o: /home/chris/DSPGuitarPedalF405/F405_Main/Application/ResourceManager/ResourceManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDISABLE_ERROR_HANDLER -DENABLE_CPPUTEST -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/LinuxGCC_Tests" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/TaskManager" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP/Reverb" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP/Filters" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/ResourceManager" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


