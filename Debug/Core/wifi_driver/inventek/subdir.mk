################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/wifi_driver/inventek/es_wifi.c \
../Core/wifi_driver/inventek/es_wifi_io.c \
../Core/wifi_driver/inventek/nx_driver_stm32l4.c \
../Core/wifi_driver/inventek/sntp_client.c \
../Core/wifi_driver/inventek/wifi.c 

OBJS += \
./Core/wifi_driver/inventek/es_wifi.o \
./Core/wifi_driver/inventek/es_wifi_io.o \
./Core/wifi_driver/inventek/nx_driver_stm32l4.o \
./Core/wifi_driver/inventek/sntp_client.o \
./Core/wifi_driver/inventek/wifi.o 

C_DEPS += \
./Core/wifi_driver/inventek/es_wifi.d \
./Core/wifi_driver/inventek/es_wifi_io.d \
./Core/wifi_driver/inventek/nx_driver_stm32l4.d \
./Core/wifi_driver/inventek/sntp_client.d \
./Core/wifi_driver/inventek/wifi.d 


# Each subdirectory must supply rules for building sources it contributes
Core/wifi_driver/inventek/%.o Core/wifi_driver/inventek/%.su Core/wifi_driver/inventek/%.cyclo: ../Core/wifi_driver/inventek/%.c Core/wifi_driver/inventek/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNX_AZURE_DISABLE_IOT_SECURITY_MODULE -DUSE_HAL_DRIVER -DSTM32L475xx -DTX_INCLUDE_USER_DEFINE_FILE -DNX_INCLUDE_USER_DEFINE_FILE -DNX_HTTP_NO_FILEX -c -I../Core/Inc -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/inventek" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../NetXDuo/App -I../NetXDuo/Target -I../Middlewares/ST/netxduo/addons/mqtt/ -I../Middlewares/ST/netxduo/addons/sntp/ -I../Middlewares/ST/netxduo/addons/auto_ip/ -I../Middlewares/ST/netxduo/addons/dns/ -I../Middlewares/ST/netxduo/addons/web/ -I../Middlewares/ST/netxduo/addons/http/ -I../Middlewares/ST/netxduo/common/inc/ -I../Middlewares/ST/netxduo/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/mdns/ -I../Middlewares/ST/netxduo/addons/dhcp/ -I../Middlewares/ST/netxduo/addons/nat/ -I../Middlewares/ST/netxduo/addons/ppp/ -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/cloud/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-wifi_driver-2f-inventek

clean-Core-2f-wifi_driver-2f-inventek:
	-$(RM) ./Core/wifi_driver/inventek/es_wifi.cyclo ./Core/wifi_driver/inventek/es_wifi.d ./Core/wifi_driver/inventek/es_wifi.o ./Core/wifi_driver/inventek/es_wifi.su ./Core/wifi_driver/inventek/es_wifi_io.cyclo ./Core/wifi_driver/inventek/es_wifi_io.d ./Core/wifi_driver/inventek/es_wifi_io.o ./Core/wifi_driver/inventek/es_wifi_io.su ./Core/wifi_driver/inventek/nx_driver_stm32l4.cyclo ./Core/wifi_driver/inventek/nx_driver_stm32l4.d ./Core/wifi_driver/inventek/nx_driver_stm32l4.o ./Core/wifi_driver/inventek/nx_driver_stm32l4.su ./Core/wifi_driver/inventek/sntp_client.cyclo ./Core/wifi_driver/inventek/sntp_client.d ./Core/wifi_driver/inventek/sntp_client.o ./Core/wifi_driver/inventek/sntp_client.su ./Core/wifi_driver/inventek/wifi.cyclo ./Core/wifi_driver/inventek/wifi.d ./Core/wifi_driver/inventek/wifi.o ./Core/wifi_driver/inventek/wifi.su

.PHONY: clean-Core-2f-wifi_driver-2f-inventek

