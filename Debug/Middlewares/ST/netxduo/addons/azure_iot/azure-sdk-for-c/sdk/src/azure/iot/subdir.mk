################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c 

OBJS += \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.o 

C_DEPS += \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/%.o Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/%.su Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/%.cyclo: ../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/%.c Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNX_HTTP_NO_FILEX -DUSE_HAL_DRIVER -DSTM32L475xx -DTX_INCLUDE_USER_DEFINE_FILE -DNX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/jsmn" -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/inventek" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../NetXDuo/App -I../NetXDuo/Target -I../Middlewares/ST/netxduo/addons/mqtt/ -I../Middlewares/ST/netxduo/addons/azure_iot/ -I../Middlewares/ST/netxduo/addons/http/ -I../Middlewares/ST/netxduo/addons/smtp/ -I../Middlewares/ST/netxduo/addons/snmp/ -I../Middlewares/ST/netxduo/addons/websocket/ -I../Middlewares/ST/netxduo/addons/sntp/ -I../Middlewares/ST/netxduo/addons/auto_ip/ -I../Middlewares/ST/netxduo/addons/dns/ -I../Middlewares/ST/netxduo/addons/web/ -I../Middlewares/ST/netxduo/common/inc/ -I../Middlewares/ST/netxduo/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/mdns/ -I../Middlewares/ST/netxduo/addons/dhcp/ -I../Middlewares/ST/netxduo/addons/nat/ -I../Middlewares/ST/netxduo/addons/ppp/ -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-azure-2d-sdk-2d-for-2d-c-2f-sdk-2f-src-2f-azure-2f-iot

clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-azure-2d-sdk-2d-for-2d-c-2f-sdk-2f-src-2f-azure-2f-iot:
	-$(RM) ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.su

.PHONY: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-azure-2d-sdk-2d-for-2d-c-2f-sdk-2f-src-2f-azure-2f-iot

