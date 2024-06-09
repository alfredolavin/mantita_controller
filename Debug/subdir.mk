################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main.cpp 

OBJS += \
./main.o 

CPP_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/usr/.dropbox/Dropbox/proyectos/AVR/mantita_controller/eduardino" -Wall -g3 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -Og -funsigned-char -funsigned-bitfields -fno-exceptions -std=gnu++23 -fplugin=/opt/AVR/root/lib/avr-flash-vtbl.so -fpermissive -mmcu=attiny85 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


