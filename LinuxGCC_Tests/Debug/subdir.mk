################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test_blank.cpp \
../test_debounce.cpp \
../test_resource_manager.cpp \
../test_statemachine.cpp \
../test_taskman.cpp \
../testmain.cpp 

OBJS += \
./test_blank.o \
./test_debounce.o \
./test_resource_manager.o \
./test_statemachine.o \
./test_taskman.o \
./testmain.o 

CPP_DEPS += \
./test_blank.d \
./test_debounce.d \
./test_resource_manager.d \
./test_statemachine.d \
./test_taskman.d \
./testmain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDISABLE_ERROR_HANDLER -DENABLE_CPPUTEST -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Debounce" -I"/home/chris/DSPGuitarPedalF405/LinuxGCC_Tests" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/StateMachine" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/TaskManager" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/FreeRTOS" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP/Reverb" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP/Filters" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/DSP" -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/ResourceManager" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


