################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine/AbstractState.cpp \
/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine/FxDisabledState.cpp \
/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine/FxEnabledState.cpp \
/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine/StateList.cpp \
/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine/StateMachine.cpp 

OBJS += \
./StateMachine/AbstractState.o \
./StateMachine/FxDisabledState.o \
./StateMachine/FxEnabledState.o \
./StateMachine/StateList.o \
./StateMachine/StateMachine.o 

CPP_DEPS += \
./StateMachine/AbstractState.d \
./StateMachine/FxDisabledState.d \
./StateMachine/FxEnabledState.d \
./StateMachine/StateList.d \
./StateMachine/StateMachine.d 


# Each subdirectory must supply rules for building sources it contributes
StateMachine/AbstractState.o: /home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine/AbstractState.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDISABLE_ERROR_HANDLER -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/LinuxGCC_Tests" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/TaskManager" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP/Reverb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

StateMachine/FxDisabledState.o: /home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine/FxDisabledState.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDISABLE_ERROR_HANDLER -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/LinuxGCC_Tests" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/TaskManager" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP/Reverb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

StateMachine/FxEnabledState.o: /home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine/FxEnabledState.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDISABLE_ERROR_HANDLER -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/LinuxGCC_Tests" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/TaskManager" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP/Reverb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

StateMachine/StateList.o: /home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine/StateList.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDISABLE_ERROR_HANDLER -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/LinuxGCC_Tests" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/TaskManager" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP/Reverb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

StateMachine/StateMachine.o: /home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine/StateMachine.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDISABLE_ERROR_HANDLER -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/LinuxGCC_Tests" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/TaskManager" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP/Reverb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


