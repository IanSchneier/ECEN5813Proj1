################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/allocate.c \
../src/display.c \
../src/exit_pgm.c \
../src/free_mem.c \
../src/help.c \
../src/invert.c \
../src/main.c \
../src/mtb.c \
../src/pattern.c \
../src/retarget_itm.c \
../src/semihost_hardfault.c \
../src/verify.c \
../src/write.c 

OBJS += \
./src/allocate.o \
./src/display.o \
./src/exit_pgm.o \
./src/free_mem.o \
./src/help.o \
./src/invert.o \
./src/main.o \
./src/mtb.o \
./src/pattern.o \
./src/retarget_itm.o \
./src/semihost_hardfault.o \
./src/verify.o \
./src/write.o 

C_DEPS += \
./src/allocate.d \
./src/display.d \
./src/exit_pgm.d \
./src/free_mem.d \
./src/help.d \
./src/invert.d \
./src/main.d \
./src/mtb.d \
./src/pattern.d \
./src/retarget_itm.d \
./src/semihost_hardfault.d \
./src/verify.d \
./src/write.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DDEBUG -DPRINTF_FLOAT_ENABLE=0 -DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 -DFRDM_KL25Z -DFREEDOM -DCR_INTEGER_PRINTF -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DSDK_DEBUGCONSOLE_ITM -D__MCUXPRESSO -D__USE_CMSIS -D__REDLIB__ -DSDK_DEBUGCONSOLE=1 -I../board -I../ -I../drivers -I../CMSIS -I../utilities -I../startup -I../inc -I../src -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


