################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_cert.c \
../Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_ciphersuites.c 

OBJS += \
./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_cert.o \
./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_ciphersuites.o 

C_DEPS += \
./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_cert.d \
./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_ciphersuites.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/netxduo/addons/azure_iot/samples/cert/%.o Middlewares/ST/netxduo/addons/azure_iot/samples/cert/%.su Middlewares/ST/netxduo/addons/azure_iot/samples/cert/%.cyclo: ../Middlewares/ST/netxduo/addons/azure_iot/samples/cert/%.c Middlewares/ST/netxduo/addons/azure_iot/samples/cert/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNX_HTTP_NO_FILEX -DUSE_HAL_DRIVER -DSTM32L475xx -DTX_INCLUDE_USER_DEFINE_FILE -DNX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/jsmn" -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/inventek" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../NetXDuo/App -I../NetXDuo/Target -I../Middlewares/ST/netxduo/addons/mqtt/ -I../Middlewares/ST/netxduo/addons/azure_iot/ -I../Middlewares/ST/netxduo/addons/http/ -I../Middlewares/ST/netxduo/addons/smtp/ -I../Middlewares/ST/netxduo/addons/snmp/ -I../Middlewares/ST/netxduo/addons/websocket/ -I../Middlewares/ST/netxduo/addons/sntp/ -I../Middlewares/ST/netxduo/addons/auto_ip/ -I../Middlewares/ST/netxduo/addons/dns/ -I../Middlewares/ST/netxduo/addons/web/ -I../Middlewares/ST/netxduo/common/inc/ -I../Middlewares/ST/netxduo/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/mdns/ -I../Middlewares/ST/netxduo/addons/dhcp/ -I../Middlewares/ST/netxduo/addons/nat/ -I../Middlewares/ST/netxduo/addons/ppp/ -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-samples-2f-cert

clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-samples-2f-cert:
	-$(RM) ./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_cert.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_cert.d ./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_cert.o ./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_cert.su ./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_ciphersuites.cyclo ./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_ciphersuites.d ./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_ciphersuites.o ./Middlewares/ST/netxduo/addons/azure_iot/samples/cert/nx_azure_iot_ciphersuites.su

.PHONY: clean-Middlewares-2f-ST-2f-netxduo-2f-addons-2f-azure_iot-2f-samples-2f-cert

