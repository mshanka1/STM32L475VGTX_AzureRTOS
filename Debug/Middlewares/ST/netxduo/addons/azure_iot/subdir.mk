################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot.c \
../Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_agent.c \
../Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_root_key.c \
../Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client.c \
../Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client_properties.c \
../Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_reader.c \
../Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_writer.c \
../Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_provisioning_client.c 

OBJS += \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot.o \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_agent.o \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_root_key.o \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client.o \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client_properties.o \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_reader.o \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_writer.o \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_provisioning_client.o 

C_DEPS += \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot.d \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_agent.d \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_root_key.d \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client.d \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client_properties.d \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_reader.d \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_writer.d \
./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_provisioning_client.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/netxduo/addons/azure_iot/%.o Middlewares/ST/netxduo/addons/azure_iot/%.su Middlewares/ST/netxduo/addons/azure_iot/%.cyclo: ../Middlewares/ST/netxduo/addons/azure_iot/%.c Middlewares/ST/netxduo/addons/azure_iot/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNX_AZURE_DISABLE_IOT_SECURITY_MODULE -DNX_HTTP_NO_FILEX -DUSE_HAL_DRIVER -DSTM32L475xx -DTX_INCLUDE_USER_DEFINE_FILE -DNX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/jsmn" -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/inventek" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../NetXDuo/App -I../NetXDuo/Target -I../Middlewares/ST/netxduo/addons/mqtt/ -I../Middlewares/ST/netxduo/addons/azure_iot/ -I../Middlewares/ST/netxduo/addons/http/ -I../Middlewares/ST/netxduo/addons/smtp/ -I../Middlewares/ST/netxduo/addons/snmp/ -I../Middlewares/ST/netxduo/addons/sntp/ -I../Middlewares/ST/netxduo/addons/auto_ip/ -I../Middlewares/ST/netxduo/addons/dns/ -I../Middlewares/ST/netxduo/addons/web/ -I../Middlewares/ST/netxduo/common/inc/ -I../Middlewares/ST/netxduo/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/mdns/ -I../Middlewares/ST/netxduo/addons/dhcp/ -I../Middlewares/ST/netxduo/addons/nat/ -I../Middlewares/ST/netxduo/addons/ppp/ -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot

clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot:
	-$(RM) ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot.d ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot.o ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot.su ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_agent.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_agent.d ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_agent.o ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_agent.su ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_root_key.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_root_key.d ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_root_key.o ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_adu_root_key.su ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client.d ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client.o ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client.su ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client_properties.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client_properties.d ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client_properties.o ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_hub_client_properties.su ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_reader.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_reader.d ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_reader.o ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_reader.su ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_writer.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_writer.d ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_writer.o ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_json_writer.su ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_provisioning_client.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_provisioning_client.d ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_provisioning_client.o ./Middlewares/ST/netxduo/addons/azure_iot/nx_azure_iot_provisioning_client.su

.PHONY: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot

