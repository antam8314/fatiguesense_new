################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_dcdc_s2.c \
C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_emu_s2.c \
C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_hfxo_s2.c \
C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_lfrco.c \
C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_lfxo_s2.c \
C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_nvic.c 

OBJS += \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_dcdc_s2.o \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_emu_s2.o \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_hfxo_s2.o \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_lfrco.o \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_lfxo_s2.o \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_nvic.o 

C_DEPS += \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_dcdc_s2.d \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_emu_s2.d \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_hfxo_s2.d \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_lfrco.d \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_lfxo_s2.d \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_nvic.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_dcdc_s2.o: C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_dcdc_s2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32BG22_BRD4184A/config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_dcdc_s2.d" -MT"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_dcdc_s2.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_emu_s2.o: C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_emu_s2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32BG22_BRD4184A/config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_emu_s2.d" -MT"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_emu_s2.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_hfxo_s2.o: C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_hfxo_s2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32BG22_BRD4184A/config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_hfxo_s2.d" -MT"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_hfxo_s2.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_lfrco.o: C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_lfrco.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32BG22_BRD4184A/config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_lfrco.d" -MT"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_lfrco.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_lfxo_s2.o: C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_lfxo_s2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32BG22_BRD4184A/config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_lfxo_s2.d" -MT"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_lfxo_s2.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_nvic.o: C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_nvic.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\notion\SimplicityStudio\v5_workspace\fatiguesense_new\config" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/common/bsp" -I"C:/Users/notion/SimplicityStudio/SDKs/gecko_sdk//hardware/kit/EFR32BG22_BRD4184A/config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_nvic.d" -MT"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_nvic.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


