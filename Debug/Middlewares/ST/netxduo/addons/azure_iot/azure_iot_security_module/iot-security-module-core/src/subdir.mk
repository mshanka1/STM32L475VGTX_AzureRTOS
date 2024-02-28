################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collector_collection.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collectors_info.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_factory.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_manager.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/core.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/logger.c \
../Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/object_pool_static.c 

OBJS += \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collector_collection.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collectors_info.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_factory.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_manager.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/core.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/logger.o \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/object_pool_static.o 

C_DEPS += \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collector_collection.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collectors_info.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_factory.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_manager.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/core.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/logger.d \
./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/object_pool_static.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/%.o Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/%.su Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/%.cyclo: ../Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/%.c Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNX_HTTP_NO_FILEX -DUSE_HAL_DRIVER -DSTM32L475xx -DTX_INCLUDE_USER_DEFINE_FILE -DNX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/jsmn" -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/inventek" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../NetXDuo/App -I../NetXDuo/Target -I../Middlewares/ST/netxduo/addons/mqtt/ -I../Middlewares/ST/netxduo/addons/azure_iot/ -I../Middlewares/ST/netxduo/addons/http/ -I../Middlewares/ST/netxduo/addons/smtp/ -I../Middlewares/ST/netxduo/addons/snmp/ -I../Middlewares/ST/netxduo/addons/websocket/ -I../Middlewares/ST/netxduo/addons/sntp/ -I../Middlewares/ST/netxduo/addons/auto_ip/ -I../Middlewares/ST/netxduo/addons/dns/ -I../Middlewares/ST/netxduo/addons/web/ -I../Middlewares/ST/netxduo/common/inc/ -I../Middlewares/ST/netxduo/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/mdns/ -I../Middlewares/ST/netxduo/addons/dhcp/ -I../Middlewares/ST/netxduo/addons/nat/ -I../Middlewares/ST/netxduo/addons/ppp/ -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-azure_iot_security_module-2f-iot-2d-security-2d-module-2d-core-2f-src

clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-azure_iot_security_module-2f-iot-2d-security-2d-module-2d-core-2f-src:
	-$(RM) ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collector_collection.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collector_collection.d ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collector_collection.o ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collector_collection.su ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collectors_info.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collectors_info.d ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collectors_info.o ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/collectors_info.su ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_factory.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_factory.d ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_factory.o ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_factory.su ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_manager.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_manager.d ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_manager.o ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/components_manager.su ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/core.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/core.d ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/core.o ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/core.su ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/logger.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/logger.d ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/logger.o ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/logger.su ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/object_pool_static.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/object_pool_static.d ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/object_pool_static.o ./Middlewares/ST/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/src/object_pool_static.su

.PHONY: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-azure_iot_security_module-2f-iot-2d-security-2d-module-2d-core-2f-src

