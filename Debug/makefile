################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include NetXDuo/Target/subdir.mk
-include NetXDuo/App/subdir.mk
-include Middlewares/ST/threadx/ports/cortex_m4/gnu/src/subdir.mk
-include Middlewares/ST/threadx/common/src/subdir.mk
-include Middlewares/ST/netxduo/common/src/subdir.mk
-include Middlewares/ST/netxduo/addons/web/subdir.mk
-include Middlewares/ST/netxduo/addons/sntp/subdir.mk
-include Middlewares/ST/netxduo/addons/ppp/subdir.mk
-include Middlewares/ST/netxduo/addons/nat/subdir.mk
-include Middlewares/ST/netxduo/addons/mqtt/subdir.mk
-include Middlewares/ST/netxduo/addons/mdns/subdir.mk
-include Middlewares/ST/netxduo/addons/http/subdir.mk
-include Middlewares/ST/netxduo/addons/dns/subdir.mk
-include Middlewares/ST/netxduo/addons/dhcp/subdir.mk
-include Middlewares/ST/netxduo/addons/cloud/subdir.mk
-include Middlewares/ST/netxduo/addons/auto_ip/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include Core/wifi_driver/inventek/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include AZURE_RTOS/App/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := wifi_rtos
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
wifi_rtos.elf \

MAP_FILES += \
wifi_rtos.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
wifi_rtos.list \


# All Target
all: main-build

# Main-build Target
main-build: wifi_rtos.elf secondary-outputs

# Tool invocations
wifi_rtos.elf wifi_rtos.map: $(OBJS) $(USER_OBJS) F:\STM32_Code\wifi_rtos\wifi_rtos\STM32L475VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "wifi_rtos.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"F:\STM32_Code\wifi_rtos\wifi_rtos\STM32L475VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="wifi_rtos.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

wifi_rtos.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "wifi_rtos.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout wifi_rtos.elf wifi_rtos.list wifi_rtos.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
