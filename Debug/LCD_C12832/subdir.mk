################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LCD_C12832/C12832_lcd.cpp \
../LCD_C12832/GraphicsDisplay.cpp \
../LCD_C12832/TextDisplay.cpp 

OBJS += \
./LCD_C12832/C12832_lcd.o \
./LCD_C12832/GraphicsDisplay.o \
./LCD_C12832/TextDisplay.o 

CPP_DEPS += \
./LCD_C12832/C12832_lcd.d \
./LCD_C12832/GraphicsDisplay.d \
./LCD_C12832/TextDisplay.d 


# Each subdirectory must supply rules for building sources it contributes
LCD_C12832/%.o: ../LCD_C12832/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__CODE_RED -DCPP_USE_HEAP -DMBED_BUILD_TIMESTAMP=1465545695.67 -D__CORTEX_M3 -DTOOLCHAIN_GCC -DTOOLCHAIN_GCC_CR -DARM_MATH_CM3 -DTARGET_LIKE_CORTEX_M3 -DTARGET_CORTEX_M -DTARGET_LIKE_MBED -DTARGET_LPC176X -DTARGET_NXP -DTARGET_LPC1768 -DTARGET_M3 -DTARGET_MBED_LPC1768 -D__MBED__=1 -I"C:\Mywork\mbed_program\High-V_INV-MC\MyProgram" -I"C:\Mywork\mbed_program\High-V_INV-MC\MyProgram\mbed" -I"C:\Mywork\mbed_program\High-V_INV-MC\MyProgram\mbed\TARGET_LPC1768" -I"C:\Mywork\mbed_program\High-V_INV-MC\MyProgram\mbed\TARGET_LPC1768\TARGET_NXP" -I"C:\Mywork\mbed_program\High-V_INV-MC\MyProgram\mbed\TARGET_LPC1768\TARGET_NXP\TARGET_LPC176X" -I"C:\Mywork\mbed_program\High-V_INV-MC\MyProgram\mbed\TARGET_LPC1768\TARGET_NXP\TARGET_LPC176X\TARGET_MBED_LPC1768" -I"C:\Mywork\mbed_program\High-V_INV-MC\MyProgram\mbed\TARGET_LPC1768\TOOLCHAIN_GCC_CR" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


