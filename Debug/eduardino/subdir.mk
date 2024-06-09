################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../eduardino/eduardino.cpp 

OBJS += \
./eduardino/eduardino.o 

CPP_DEPS += \
./eduardino/eduardino.d 


# Each subdirectory must supply rules for building sources it contributes
eduardino/%.o: ../eduardino/%.cpp eduardino/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/usr/.dropbox/Dropbox/proyectos/AVR/mantita_controller/eduardino" -Wall -g3 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -Og -funsigned-char -funsigned-bitfields -fno-exceptions -std=gnu++23 -fplugin=/opt/AVR/root/lib/avr-flash-vtbl.so -fpermissive -mmcu=attiny85 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


