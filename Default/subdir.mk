################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ChatServer.cpp \
../Client.cpp \
../CommandFactory.cpp \
../ListCommand.cpp \
../NickCommand.cpp \
../PrivateMessage.cpp \
../PublicMessage.cpp \
../ServerSocket.cpp \
../Socket.cpp \
../UnknownCommand.cpp \
../main.cpp 

OBJS += \
./ChatServer.o \
./Client.o \
./CommandFactory.o \
./ListCommand.o \
./NickCommand.o \
./PrivateMessage.o \
./PublicMessage.o \
./ServerSocket.o \
./Socket.o \
./UnknownCommand.o \
./main.o 

CPP_DEPS += \
./ChatServer.d \
./Client.d \
./CommandFactory.d \
./ListCommand.d \
./NickCommand.d \
./PrivateMessage.d \
./PublicMessage.d \
./ServerSocket.d \
./Socket.d \
./UnknownCommand.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


