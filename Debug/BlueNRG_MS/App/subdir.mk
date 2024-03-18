################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BlueNRG_MS/App/app_bluenrg_ms.c \
../BlueNRG_MS/App/sample_service.c 

OBJS += \
./BlueNRG_MS/App/app_bluenrg_ms.o \
./BlueNRG_MS/App/sample_service.o 

C_DEPS += \
./BlueNRG_MS/App/app_bluenrg_ms.d \
./BlueNRG_MS/App/sample_service.d 


# Each subdirectory must supply rules for building sources it contributes
BlueNRG_MS/App/%.o BlueNRG_MS/App/%.su BlueNRG_MS/App/%.cyclo: ../BlueNRG_MS/App/%.c BlueNRG_MS/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DFEATURE_NX_IPV6 -DNX_DNS_ENABLE_EXTENDED_RR_TYPES -DNX_AZURE_DISABLE_IOT_SECURITY_MODULE -DUSE_HAL_DRIVER -DSTM32L475xx -DTX_INCLUDE_USER_DEFINE_FILE -DNX_INCLUDE_USER_DEFINE_FILE -DNX_HTTP_NO_FILEX -c -I../Core/Inc -I"F:/STM32_Code/wifi_rtos/wifi_rtos/Core/wifi_driver/inventek" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../AZURE_RTOS/App -I../NetXDuo/App -I../NetXDuo/Target -I../Middlewares/ST/netxduo/addons/mqtt/ -I../Middlewares/ST/netxduo/addons/websocket/ -I../Middlewares/ST/netxduo/addons/sntp/ -I../Middlewares/ST/netxduo/addons/auto_ip/ -I../Middlewares/ST/netxduo/addons/dns/ -I../Middlewares/ST/netxduo/addons/web/ -I../Middlewares/ST/netxduo/addons/http/ -I../Middlewares/ST/netxduo/common/inc/ -I../Middlewares/ST/netxduo/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/mdns/ -I../Middlewares/ST/netxduo/addons/dhcp/ -I../Middlewares/ST/netxduo/addons/nat/ -I../Middlewares/ST/netxduo/addons/ppp/ -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m4/gnu/inc/ -I../Middlewares/ST/netxduo/addons/cloud/ -I../BlueNRG_MS/App -I../BlueNRG_MS/Target -I../Drivers/BSP/B-L475E-IOT01A2 -I../Middlewares/ST/BlueNRG-MS/utils -I../Middlewares/ST/BlueNRG-MS/includes -I../Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BlueNRG_MS-2f-App

clean-BlueNRG_MS-2f-App:
	-$(RM) ./BlueNRG_MS/App/app_bluenrg_ms.cyclo ./BlueNRG_MS/App/app_bluenrg_ms.d ./BlueNRG_MS/App/app_bluenrg_ms.o ./BlueNRG_MS/App/app_bluenrg_ms.su ./BlueNRG_MS/App/sample_service.cyclo ./BlueNRG_MS/App/sample_service.d ./BlueNRG_MS/App/sample_service.o ./BlueNRG_MS/App/sample_service.su

.PHONY: clean-BlueNRG_MS-2f-App

