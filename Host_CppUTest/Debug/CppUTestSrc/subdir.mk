################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CppUTestSrc/CodeMemoryReportFormatter.cpp \
../CppUTestSrc/CommandLineArguments.cpp \
../CppUTestSrc/CommandLineTestRunner.cpp \
../CppUTestSrc/GTest.cpp \
../CppUTestSrc/IEEE754ExceptionsPlugin.cpp \
../CppUTestSrc/JUnitTestOutput.cpp \
../CppUTestSrc/MemoryLeakDetector.cpp \
../CppUTestSrc/MemoryLeakWarningPlugin.cpp \
../CppUTestSrc/MemoryReportAllocator.cpp \
../CppUTestSrc/MemoryReportFormatter.cpp \
../CppUTestSrc/MemoryReporterPlugin.cpp \
../CppUTestSrc/MockActualCall.cpp \
../CppUTestSrc/MockExpectedCall.cpp \
../CppUTestSrc/MockExpectedCallsList.cpp \
../CppUTestSrc/MockFailure.cpp \
../CppUTestSrc/MockNamedValue.cpp \
../CppUTestSrc/MockSupport.cpp \
../CppUTestSrc/MockSupportPlugin.cpp \
../CppUTestSrc/MockSupport_c.cpp \
../CppUTestSrc/OrderedTest.cpp \
../CppUTestSrc/SimpleMutex.cpp \
../CppUTestSrc/SimpleString.cpp \
../CppUTestSrc/SimpleStringInternalCache.cpp \
../CppUTestSrc/TeamCityTestOutput.cpp \
../CppUTestSrc/TestFailure.cpp \
../CppUTestSrc/TestFilter.cpp \
../CppUTestSrc/TestHarness_c.cpp \
../CppUTestSrc/TestMemoryAllocator.cpp \
../CppUTestSrc/TestOutput.cpp \
../CppUTestSrc/TestPlugin.cpp \
../CppUTestSrc/TestRegistry.cpp \
../CppUTestSrc/TestResult.cpp \
../CppUTestSrc/TestTestingFixture.cpp \
../CppUTestSrc/Utest.cpp \
../CppUTestSrc/UtestPlatform.cpp 

OBJS += \
./CppUTestSrc/CodeMemoryReportFormatter.o \
./CppUTestSrc/CommandLineArguments.o \
./CppUTestSrc/CommandLineTestRunner.o \
./CppUTestSrc/GTest.o \
./CppUTestSrc/IEEE754ExceptionsPlugin.o \
./CppUTestSrc/JUnitTestOutput.o \
./CppUTestSrc/MemoryLeakDetector.o \
./CppUTestSrc/MemoryLeakWarningPlugin.o \
./CppUTestSrc/MemoryReportAllocator.o \
./CppUTestSrc/MemoryReportFormatter.o \
./CppUTestSrc/MemoryReporterPlugin.o \
./CppUTestSrc/MockActualCall.o \
./CppUTestSrc/MockExpectedCall.o \
./CppUTestSrc/MockExpectedCallsList.o \
./CppUTestSrc/MockFailure.o \
./CppUTestSrc/MockNamedValue.o \
./CppUTestSrc/MockSupport.o \
./CppUTestSrc/MockSupportPlugin.o \
./CppUTestSrc/MockSupport_c.o \
./CppUTestSrc/OrderedTest.o \
./CppUTestSrc/SimpleMutex.o \
./CppUTestSrc/SimpleString.o \
./CppUTestSrc/SimpleStringInternalCache.o \
./CppUTestSrc/TeamCityTestOutput.o \
./CppUTestSrc/TestFailure.o \
./CppUTestSrc/TestFilter.o \
./CppUTestSrc/TestHarness_c.o \
./CppUTestSrc/TestMemoryAllocator.o \
./CppUTestSrc/TestOutput.o \
./CppUTestSrc/TestPlugin.o \
./CppUTestSrc/TestRegistry.o \
./CppUTestSrc/TestResult.o \
./CppUTestSrc/TestTestingFixture.o \
./CppUTestSrc/Utest.o \
./CppUTestSrc/UtestPlatform.o 

CPP_DEPS += \
./CppUTestSrc/CodeMemoryReportFormatter.d \
./CppUTestSrc/CommandLineArguments.d \
./CppUTestSrc/CommandLineTestRunner.d \
./CppUTestSrc/GTest.d \
./CppUTestSrc/IEEE754ExceptionsPlugin.d \
./CppUTestSrc/JUnitTestOutput.d \
./CppUTestSrc/MemoryLeakDetector.d \
./CppUTestSrc/MemoryLeakWarningPlugin.d \
./CppUTestSrc/MemoryReportAllocator.d \
./CppUTestSrc/MemoryReportFormatter.d \
./CppUTestSrc/MemoryReporterPlugin.d \
./CppUTestSrc/MockActualCall.d \
./CppUTestSrc/MockExpectedCall.d \
./CppUTestSrc/MockExpectedCallsList.d \
./CppUTestSrc/MockFailure.d \
./CppUTestSrc/MockNamedValue.d \
./CppUTestSrc/MockSupport.d \
./CppUTestSrc/MockSupportPlugin.d \
./CppUTestSrc/MockSupport_c.d \
./CppUTestSrc/OrderedTest.d \
./CppUTestSrc/SimpleMutex.d \
./CppUTestSrc/SimpleString.d \
./CppUTestSrc/SimpleStringInternalCache.d \
./CppUTestSrc/TeamCityTestOutput.d \
./CppUTestSrc/TestFailure.d \
./CppUTestSrc/TestFilter.d \
./CppUTestSrc/TestHarness_c.d \
./CppUTestSrc/TestMemoryAllocator.d \
./CppUTestSrc/TestOutput.d \
./CppUTestSrc/TestPlugin.d \
./CppUTestSrc/TestRegistry.d \
./CppUTestSrc/TestResult.d \
./CppUTestSrc/TestTestingFixture.d \
./CppUTestSrc/Utest.d \
./CppUTestSrc/UtestPlatform.d 


# Each subdirectory must supply rules for building sources it contributes
CppUTestSrc/%.o: ../CppUTestSrc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/chris/DSPGuitarPedalF405/Host_CppUTest/CppUTestInc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


