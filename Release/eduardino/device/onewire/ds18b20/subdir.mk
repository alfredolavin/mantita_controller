################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../eduardino/device/onewire/ds18b20/ds18b20.cpp 

OBJS += \
./eduardino/device/onewire/ds18b20/ds18b20.o 

CPP_DEPS += \
./eduardino/device/onewire/ds18b20/ds18b20.d 


# Each subdirectory must supply rules for building sources it contributes
eduardino/device/onewire/ds18b20/%.o: ../eduardino/device/onewire/ds18b20/%.cpp eduardino/device/onewire/ds18b20/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/usr/.dropbox/Dropbox/proyectos/AVR/duchaRGB/eduardino" -g3 -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -flto -funsigned-char -funsigned-bitfields -fno-exceptions -std=gnu++23 -fplugin=/opt/AVR/root/lib/avr-flash-vtbl.so -fpermissive -mmcu=attiny85 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


