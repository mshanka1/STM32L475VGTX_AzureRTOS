################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/wifi_driver/addons/azure_iot/nx_azure_iot.c \
../Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_agent.c \
../Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_root_key.c \
../Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client.c \
../Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client_properties.c \
../Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_reader.c \
../Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_writer.c \
../Core/wifi_driver/addons/azure_iot/nx_azure_iot_provisioning_client.c 

OBJS += \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot.o \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_agent.o \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_root_key.o \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client.o \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client_properties.o \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_reader.o \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_writer.o \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_provisioning_client.o 

C_DEPS += \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot.d \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_agent.d \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_root_key.d \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client.d \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client_properties.d \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_reader.d \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_writer.d \
./Core/wifi_driver/addons/azure_iot/nx_azure_iot_provisioning_client.d 


# Each subdirectory must supply rules for building sources it contributes
Core/wifi_driver/addons/azure_iot/%.o Core/wifi_driver/addons/azure_iot/%.su Core/wifi_driver/addons/azure_iot/%.cyclo: ../Core/wifi_driver/addons/azure_iot/%.c Core/wifi_driver/addons/azure_iot/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -DTX_INCLUDE_USER_DEFINE_FILE -DNX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/jsmn" -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/common/inc" -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/addons" -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/inventek" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../NetXDuo/App -I../NetXDuo/Target -I../Middlewares/ST/netxduo/addons/mqtt/ -I../Middlewares/ST/netxduo/addons/sntp/ -I../Middlewares/ST/netxduo/addons/auto_ip/ -I../Middlewares/ST/netxduo/addons/dns/ -I../Middlewares/ST/netxduo/addons/web/ -I../Middlewares/ST/netxduo/common/inc/ -I../Middlewares/ST/netxduo/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/mdns/ -I../Middlewares/ST/netxduo/addons/dhcp/ -I../Middlewares/ST/netxduo/addons/nat/ -I../Middlewares/ST/netxduo/addons/ppp/ -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-wifi_driver-2f-addons-2f-azure_iot

clean-Core-2f-wifi_driver-2f-addons-2f-azure_iot:
	-$(RM) ./Core/wifi_driver/addons/azure_iot/nx_azure_iot.cyclo ./Core/wifi_driver/addons/azure_iot/nx_azure_iot.d ./Core/wifi_driver/addons/azure_iot/nx_azure_iot.o ./Core/wifi_driver/addons/azure_iot/nx_azure_iot.su ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_agent.cyclo ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_agent.d ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_agent.o ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_agent.su ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_root_key.cyclo ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_root_key.d ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_root_key.o ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_adu_root_key.su ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client.cyclo ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client.d ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client.o ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client.su ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client_properties.cyclo ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client_properties.d ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client_properties.o ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_hub_client_properties.su ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_reader.cyclo ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_reader.d ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_reader.o ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_reader.su ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_writer.cyclo ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_writer.d ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_writer.o ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_json_writer.su ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_provisioning_client.cyclo ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_provisioning_client.d ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_provisioning_client.o ./Core/wifi_driver/addons/azure_iot/nx_azure_iot_provisioning_client.su

.PHONY: clean-Core-2f-wifi_driver-2f-addons-2f-azure_iot

