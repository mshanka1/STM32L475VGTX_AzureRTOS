################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2.c \
../Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2_bus.c 

OBJS += \
./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2.o \
./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2_bus.o 

C_DEPS += \
./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2.d \
./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2_bus.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/B-L475E-IOT01A2/%.o Drivers/BSP/B-L475E-IOT01A2/%.su Drivers/BSP/B-L475E-IOT01A2/%.cyclo: ../Drivers/BSP/B-L475E-IOT01A2/%.c Drivers/BSP/B-L475E-IOT01A2/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNXD_MQTT_OVER_WEBSOCKET -DFEATURE_NX_IPV6 -DNX_DNS_ENABLE_EXTENDED_RR_TYPES -DNX_AZURE_DISABLE_IOT_SECURITY_MODULE -DUSE_HAL_DRIVER -DSTM32L475xx -DTX_INCLUDE_USER_DEFINE_FILE -DNX_INCLUDE_USER_DEFINE_FILE -DNX_HTTP_NO_FILEX -c -I../Core/Inc -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/inventek" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../NetXDuo/App -I../NetXDuo/Target -I../Middlewares/ST/netxduo/addons/mqtt/ -I../Middlewares/ST/netxduo/addons/websocket/ -I../Middlewares/ST/netxduo/addons/sntp/ -I../Middlewares/ST/netxduo/addons/auto_ip/ -I../Middlewares/ST/netxduo/addons/dns/ -I../Middlewares/ST/netxduo/addons/web/ -I../Middlewares/ST/netxduo/addons/http/ -I../Middlewares/ST/netxduo/common/inc/ -I../Middlewares/ST/netxduo/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/mdns/ -I../Middlewares/ST/netxduo/addons/dhcp/ -I../Middlewares/ST/netxduo/addons/nat/ -I../Middlewares/ST/netxduo/addons/ppp/ -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/cloud/ -I../BlueNRG_MS/App -I../BlueNRG_MS/Target -I../Drivers/BSP/B-L475E-IOT01A2 -I../Middlewares/ST/BlueNRG-MS/utils -I../Middlewares/ST/BlueNRG-MS/includes -I../Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-B-2d-L475E-2d-IOT01A2

clean-Drivers-2f-BSP-2f-B-2d-L475E-2d-IOT01A2:
	-$(RM) ./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2.cyclo ./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2.d ./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2.o ./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2.su ./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2_bus.cyclo ./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2_bus.d ./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2_bus.o ./Drivers/BSP/B-L475E-IOT01A2/b_l475e_iot01a2_bus.su

.PHONY: clean-Drivers-2f-BSP-2f-B-2d-L475E-2d-IOT01A2

