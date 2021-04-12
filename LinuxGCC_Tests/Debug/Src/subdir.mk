################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/chris/DSPGuitarPedalF405/F405_Main/Application/Src/AbstractState.cpp \
/home/chris/DSPGuitarPedalF405/F405_Main/Application/Src/EventMachine.cpp \
/home/chris/DSPGuitarPedalF405/F405_Main/Application/Src/app_main.cpp \
/home/chris/DSPGuitarPedalF405/F405_Main/Application/Src/pedal_io_test.cpp 

OBJS += \
./Src/AbstractState.o \
./Src/EventMachine.o \
./Src/app_main.o \
./Src/pedal_io_test.o 

CPP_DEPS += \
./Src/AbstractState.d \
./Src/EventMachine.d \
./Src/app_main.d \
./Src/pedal_io_test.d 


# Each subdirectory must supply rules for building sources it contributes
Src/AbstractState.o: /home/chris/DSPGuitarPedalF405/F405_Main/Application/Src/AbstractState.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Inc" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/EventMachine.o: /home/chris/DSPGuitarPedalF405/F405_Main/Application/Src/EventMachine.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Inc" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/app_main.o: /home/chris/DSPGuitarPedalF405/F405_Main/Application/Src/app_main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Inc" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/pedal_io_test.o: /home/chris/DSPGuitarPedalF405/F405_Main/Application/Src/pedal_io_test.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -I/home/chris/CMSIS_5.7.0_Build/CMSIS/DSP/Include -I/home/chris/CMSIS_5.7.0_Build/CMSIS/Include -I"/home/chris/DSPGuitarPedalF405/F405_Main/Application/Inc" -I"/home/chris/DSPGuitarPedalF405/F405_RTT/RTT" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


