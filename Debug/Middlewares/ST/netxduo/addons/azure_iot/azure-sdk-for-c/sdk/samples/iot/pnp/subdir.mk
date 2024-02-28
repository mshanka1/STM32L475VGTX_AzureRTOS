################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_device_info_component.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_mqtt_message.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_protocol.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_temperature_controller_component.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_thermostat_component.c 

OBJS += \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_device_info_component.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_mqtt_message.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_protocol.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_temperature_controller_component.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_thermostat_component.o 

C_DEPS += \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_device_info_component.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_mqtt_message.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_protocol.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_temperature_controller_component.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_thermostat_component.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/%.o Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/%.su Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/%.cyclo: ../Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/%.c Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNX_HTTP_NO_FILEX -DUSE_HAL_DRIVER -DSTM32L475xx -DTX_INCLUDE_USER_DEFINE_FILE -DNX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/jsmn" -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/inventek" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../NetXDuo/App -I../NetXDuo/Target -I../Middlewares/ST/netxduo/addons/mqtt/ -I../Middlewares/ST/netxduo/addons/azure_iot/ -I../Middlewares/ST/netxduo/addons/http/ -I../Middlewares/ST/netxduo/addons/smtp/ -I../Middlewares/ST/netxduo/addons/snmp/ -I../Middlewares/ST/netxduo/addons/websocket/ -I../Middlewares/ST/netxduo/addons/sntp/ -I../Middlewares/ST/netxduo/addons/auto_ip/ -I../Middlewares/ST/netxduo/addons/dns/ -I../Middlewares/ST/netxduo/addons/web/ -I../Middlewares/ST/netxduo/common/inc/ -I../Middlewares/ST/netxduo/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/mdns/ -I../Middlewares/ST/netxduo/addons/dhcp/ -I../Middlewares/ST/netxduo/addons/nat/ -I../Middlewares/ST/netxduo/addons/ppp/ -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-azure-2d-sdk-2d-for-2d-c-2f-sdk-2f-samples-2f-iot-2f-pnp

clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-azure-2d-sdk-2d-for-2d-c-2f-sdk-2f-samples-2f-iot-2f-pnp:
	-$(RM) ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_device_info_component.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_device_info_component.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_device_info_component.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_device_info_component.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_mqtt_message.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_mqtt_message.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_mqtt_message.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_mqtt_message.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_protocol.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_protocol.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_protocol.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_protocol.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_temperature_controller_component.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_temperature_controller_component.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_temperature_controller_component.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_temperature_controller_component.su ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_thermostat_component.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_thermostat_component.d ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_thermostat_component.o ./Middlewares/ST/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/samples/iot/pnp/pnp_thermostat_component.su

.PHONY: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-azure-2d-sdk-2d-for-2d-c-2f-sdk-2f-samples-2f-iot-2f-pnp

