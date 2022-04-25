################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../autogen/gatt_db.c \
../autogen/sl_bluetooth.c \
../autogen/sl_board_default_init.c \
../autogen/sl_device_init_clocks.c \
../autogen/sl_event_handler.c \
../autogen/sl_iostream_handles.c \
../autogen/sl_power_manager_handler.c 

OBJS += \
./autogen/gatt_db.o \
./autogen/sl_bluetooth.o \
./autogen/sl_board_default_init.o \
./autogen/sl_device_init_clocks.o \
./autogen/sl_event_handler.o \
./autogen/sl_iostream_handles.o \
./autogen/sl_power_manager_handler.o 

C_DEPS += \
./autogen/gatt_db.d \
./autogen/sl_bluetooth.d \
./autogen/sl_board_default_init.d \
./autogen/sl_device_init_clocks.d \
./autogen/sl_event_handler.d \
./autogen/sl_iostream_handles.d \
./autogen/sl_power_manager_handler.d 


# Each subdirectory must supply rules for building sources it contributes
autogen/gatt_db.o: ../autogen/gatt_db.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/gatt_db.d" -MT"autogen/gatt_db.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_bluetooth.o: ../autogen/sl_bluetooth.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_bluetooth.d" -MT"autogen/sl_bluetooth.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_board_default_init.o: ../autogen/sl_board_default_init.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_board_default_init.d" -MT"autogen/sl_board_default_init.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_device_init_clocks.o: ../autogen/sl_device_init_clocks.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_device_init_clocks.d" -MT"autogen/sl_device_init_clocks.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_event_handler.o: ../autogen/sl_event_handler.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_event_handler.d" -MT"autogen/sl_event_handler.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_iostream_handles.o: ../autogen/sl_iostream_handles.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_iostream_handles.d" -MT"autogen/sl_iostream_handles.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_power_manager_handler.o: ../autogen/sl_power_manager_handler.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DARM_MATH_ARMV8MML=1' '-DARM_MATH_DSP=1' '-D__DSP_PRESENT=1' '-D__FPU_PRESENT=1' '-DEFR32BG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4184A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DRTT_USE_ASM=0' '-DSEGGER_RTT_SECTION="SEGGER_RTT"' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/ota_dfu" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/segger/systemview/SEGGER" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/simple_timer" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/Ryan/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\autogen" -I"C:\Users\Ryan\SimplicityStudio\v5_workspace\fatiguesense_new\config" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_power_manager_handler.d" -MT"autogen/sl_power_manager_handler.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


