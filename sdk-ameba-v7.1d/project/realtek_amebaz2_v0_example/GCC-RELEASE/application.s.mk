# Initialize tool chain
# -------------------------------------------------------------------

AMEBAZ2_TOOLDIR	= ../../../component/soc/realtek/8710c/misc/iar_utility
AMEBAZ2_GCCTOOLDIR	= ../../../component/soc/realtek/8710c/misc/gcc_utility
AMEBAZ2_BSPDIR = ../../../component/soc/realtek/8710c/misc/bsp
AMEBAZ2_BOOTLOADERDIR = $(AMEBAZ2_BSPDIR)/image
AMEBAZ2_ROMSYMDIR = $(AMEBAZ2_BSPDIR)/ROM

OS := $(shell uname)

CROSS_COMPILE = $(ARM_GCC_TOOLCHAIN)/arm-none-eabi-

# Compilation tools
AR = $(CROSS_COMPILE)ar
CC = $(CROSS_COMPILE)gcc
AS = $(CROSS_COMPILE)as
NM = $(CROSS_COMPILE)nm
LD = $(CROSS_COMPILE)gcc
GDB = $(CROSS_COMPILE)gdb
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump

OS := $(shell uname)

LDSCRIPT := ./rtl8710c_ram_s.ld

# Initialize target name and target object files
# -------------------------------------------------------------------

all: build_info application_s manipulate_images

mp: build_info application_s manipulate_images

TARGET=application_s

OBJ_DIR=$(TARGET)/Debug/obj
BIN_DIR=$(TARGET)/Debug/bin
INFO_DIR=$(TARGET)/Debug/info


ROMIMG = 
# Include folder list
# -------------------------------------------------------------------

INCLUDES =
INCLUDES += -I../inc

INCLUDES += -I../../../component/common/api
INCLUDES += -I../../../component/common/api/at_cmd
INCLUDES += -I../../../component/common/api/platform
INCLUDES += -I../../../component/common/api/wifi
INCLUDES += -I../../../component/common/api/wifi/rtw_wpa_supplicant/src
INCLUDES += -I../../../component/common/api/network/include
INCLUDES += -I../../../component/common/application
INCLUDES += -I../../../component/common/application/mqtt/MQTTClient
INCLUDES += -I../../../component/common/file_system
INCLUDES += -I../../../component/common/utilities
INCLUDES += -I../../../component/common/mbed/hal
INCLUDES += -I../../../component/common/mbed/hal_ext
INCLUDES += -I../../../component/common/mbed/targets/hal/rtl8710c
INCLUDES += -I../../../component/common/network
INCLUDES += -I../../../component/common/network/coap/include
INCLUDES += -I../../../component/common/network/lwip/lwip_v2.0.2/src/include
INCLUDES += -I../../../component/common/network/lwip/lwip_v2.0.2/src/include/lwip
INCLUDES += -I../../../component/common/network/lwip/lwip_v2.0.2/port/realtek
INCLUDES += -I../../../component/common/network/lwip/lwip_v2.0.2/port/realtek/freertos
INCLUDES += -I../../../component/common/network/ssl/mbedtls-2.4.0/include
INCLUDES += -I../../../component/common/network/ssl/ssl_ram_map/rom
INCLUDES += -I../../../component/common/drivers/wlan/realtek/include
INCLUDES += -I../../../component/common/drivers/wlan/realtek/src/osdep
INCLUDES += -I../../../component/common/test

INCLUDES += -I../../../component/soc/realtek/8710c/cmsis/rtl8710c/include
INCLUDES += -I../../../component/soc/realtek/8710c/cmsis/rtl8710c/lib/include
INCLUDES += -I../../../component/soc/realtek/8710c/fwlib/include
INCLUDES += -I../../../component/soc/realtek/8710c/fwlib/lib/include
INCLUDES += -I../../../component/soc/realtek/8710c/cmsis/cmsis-core/include
INCLUDES += -I../../../component/soc/realtek/8710c/app/rtl_printf/include
INCLUDES += -I../../../component/soc/realtek/8710c/app/shell
INCLUDES += -I../../../component/soc/realtek/8710c/app/stdio_port
INCLUDES += -I../../../component/soc/realtek/8710c/misc/utilities/include
INCLUDES += -I../../../component/soc/realtek/8710c/mbed-drivers/include

INCLUDES += -I../../../component/os/freertos
INCLUDES += -I../../../component/os/freertos/freertos_v10.2.0/Source/include
INCLUDES += -I../../../component/os/freertos/freertos_v10.2.0/Source/portable/GCC/RTL8710C/secure
INCLUDES += -I../../../component/os/freertos/freertos_v10.2.0/Source/portable/GCC/RTL8710C/non_secure
INCLUDES += -I../../../component/os/os_dep/include

# Source file list
# -------------------------------------------------------------------

SRC_C =
SRAM_C =
ERAM_C =

SRC_C += ../../../component/common/file_system/ftl/ftl_crypto.c

#cmsis
SRC_C += ../../../component/soc/realtek/8710c/cmsis/rtl8710c/source/ram/mpu_config.c
SRC_C += ../../../component/soc/realtek/8710c/cmsis/rtl8710c/source/ram_s/app_start.c

#libc api wrapper
SRC_C += ../../../component/soc/realtek/8710c/misc/utilities/source/ram/libc_wrap.c

#console
SRC_C += ../../../component/soc/realtek/8710c/app/shell/ram_s/consol_cmds.c

#network - ssl - ssl_ram_map
SRC_C += ../../../component/common/network/ssl/ssl_ram_map/rom/rom_ssl_ram_map.c
SRC_C += ../../../component/common/network/ssl/ssl_ram_map/ssl_ram_map.c

#os
SRC_C += ../../../component/os/freertos/freertos_heap5_config.c
SRC_C += ../../../component/os/freertos/freertos_heap_rtk.c

SRC_C += ../../../component/os/freertos/freertos_v10.2.0/Source/portable/GCC/RTL8710C/secure/secure_context.c
SRC_C += ../../../component/os/freertos/freertos_v10.2.0/Source/portable/GCC/RTL8710C/secure/secure_context_port.c
SRC_C += ../../../component/os/freertos/freertos_v10.2.0/Source/portable/GCC/RTL8710C/secure/secure_init.c

#peripheral - api
SRC_C += ../../../component/common/mbed/targets/hal/rtl8710c/crypto_api.c
SRC_C += ../../../component/common/mbed/targets/hal/rtl8710c/us_ticker_api.c
SRC_C += ../../../component/common/mbed/targets/hal/rtl8710c/wait_api.c
SRC_C += ../../../component/common/mbed/targets/hal/rtl8710c/sys_api.c

#peripheral - hal
SRC_C += ../../../component/soc/realtek/8710c/fwlib/source/ram_s/hal_efuse.c
SRC_C += ../../../component/soc/realtek/8710c/fwlib/source/ram/hal_gdma.c
SRC_C += ../../../component/soc/realtek/8710c/fwlib/source/ram/hal_gpio.c
SRC_C += ../../../component/soc/realtek/8710c/fwlib/source/ram/hal_misc.c
SRC_C += ../../../component/soc/realtek/8710c/fwlib/source/ram_s/hal_efuse_nsc.c
SRC_C += ../../../component/soc/realtek/8710c/fwlib/source/ram_s/hal_pinmux_nsc.c
SRC_C += ../../../component/soc/realtek/8710c/fwlib/source/ram/hal_uart.c

#network - ssl - mbedtls
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/aes.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/asn1parse.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/asn1write.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/base64.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/bignum.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/ecdsa.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/ecp.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/ecp_curves.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library_s/mbedtls_nsc.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/md.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/md5.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/md_wrap.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/oid.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/pem.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/pk.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/pk_wrap.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/pkcs12.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/pkcs5.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/pkparse.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/platform.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/rsa.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/sha1.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/sha256.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/sha512.c
SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/ssl_tls.c

# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/arc4.c
# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/cipher.c
# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/cipher_wrap.c
# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/debug.c
# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/ecdh.c
# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/gcm.c
# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library_s/mbedtls_ext_nsc.c
# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/ssl_ciphersuites.c
# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/ssl_cli.c
# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/x509.c
# SRC_C += ../../../component/common/network/ssl/mbedtls-2.4.0/library/x509_crt.c

#utilities - example
SRC_C += ../../../component/common/example/secure_storage/example_secure_storage_s.c

#user
SRC_C += ../src/main_s.c

#SRAM
# -------------------------------------------------------------------
#@SRAM
# SRAM_C += 

# Generate obj list
# -------------------------------------------------------------------

SRC_O = $(patsubst %.c,%_$(TARGET).o,$(SRC_C))
SRAM_O = $(patsubst %.c,%_$(TARGET).o,$(SRAM_C))
ERAM_O = $(patsubst %.c,%_$(TARGET).o,$(ERAM_C))

SRC_C_LIST = $(notdir $(SRC_C)) $(notdir $(SRAM_C)) $(notdir $(ERAM_C))
OBJ_LIST = $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%_$(TARGET).o,$(SRC_C_LIST)))
DEPENDENCY_LIST = $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%_$(TARGET).d,$(SRC_C_LIST)))

# Compile options
# -------------------------------------------------------------------

CFLAGS =
CFLAGS += -march=armv8-m.main+dsp -mthumb -mcmse -mfloat-abi=soft -D__thumb2__ -g -gdwarf-3 -Os
CFLAGS += -D__ARM_ARCH_8M_MAIN__=1 -gdwarf-3 -fstack-usage -fdata-sections -ffunction-sections 
CFLAGS += -fdiagnostics-color=always -Wall -Wpointer-arith -Wstrict-prototypes -Wundef -Wno-write-strings 
CFLAGS += -Wno-maybe-uninitialized --save-temps -c -MMD
CFLAGS += -DCONFIG_PLATFORM_8710C -DCONFIG_BUILD_RAM=1
CFLAGS += -DV8M_STKOVF
CFLAGS += -DV8M_SECURE
CFLAGS += -DCONFIG_BUILD_SECURE=1

LFLAGS = 
LFLAGS += -Os -march=armv8-m.main+dsp -mthumb -mcmse -mfloat-abi=soft -nostartfiles -nodefaultlibs -nostdlib -specs=nosys.specs
LFLAGS += -Wl,--gc-sections -Wl,--warn-section-align -Wl,--cref -Wl,--build-id=none -Wl,--use-blx
LFLAGS += -Wl,-Map=$(BIN_DIR)/$(TARGET).map
# libc api wrapper
LFLAGS += -Wl,-wrap,strcat  -Wl,-wrap,strchr   -Wl,-wrap,strcmp
LFLAGS += -Wl,-wrap,strncmp -Wl,-wrap,strnicmp -Wl,-wrap,strcpy
LFLAGS += -Wl,-wrap,strncpy -Wl,-wrap,strlcpy  -Wl,-wrap,strlen
LFLAGS += -Wl,-wrap,strnlen -Wl,-wrap,strncat  -Wl,-wrap,strpbrk
LFLAGS += -Wl,-wrap,strspn  -Wl,-wrap,strstr   -Wl,-wrap,strtok
LFLAGS += -Wl,-wrap,strxfrm -Wl,-wrap,strsep   -Wl,-wrap,strtod
LFLAGS += -Wl,-wrap,strtof  -Wl,-wrap,strtold  -Wl,-wrap,strtoll
LFLAGS += -Wl,-wrap,strtoul -Wl,-wrap,strtoull -Wl,-wrap,atoi
LFLAGS += -Wl,-wrap,atoui   -Wl,-wrap,atol     -Wl,-wrap,atoul
LFLAGS += -Wl,-wrap,atoull  -Wl,-wrap,atof
LFLAGS += -Wl,-wrap,malloc  -Wl,-wrap,realloc
LFLAGS += -Wl,-wrap,calloc  -Wl,-wrap,free
LFLAGS += -Wl,-wrap,_malloc_r  -Wl,-wrap,_calloc_r
LFLAGS += -Wl,-wrap,memcmp  -Wl,-wrap,memcpy
LFLAGS += -Wl,-wrap,memmove -Wl,-wrap,memset
LFLAGS += -Wl,-wrap,printf  -Wl,-wrap,sprintf
LFLAGS += -Wl,-wrap,puts  -Wl,-wrap,putc -Wl,-wrap,putchar
LFLAGS += -Wl,-wrap,snprintf  -Wl,-wrap,vsnprintf
LFLAGS += -Wl,--out-implib=./gateway_ns.o -Wl,--cmse-implib

LIBFLAGS =
LIBFLAGS += -L$(AMEBAZ2_ROMSYMDIR)
all: LIBFLAGS += -L../../../component/soc/realtek/8710c/misc/bsp/lib/common/GCC -l_soc_s
mp: LIBFLAGS += -L../../../component/soc/realtek/8710c/misc/bsp/lib/common/GCC -l_soc_s

RAMALL_BIN =
OTA_BIN = 

include toolchain.mk

# Compile
# -------------------------------------------------------------------

.PHONY: application_s
application_s: prerequirement $(SRC_O) $(SRAM_O) $(ERAM_O)
	$(LD) $(LFLAGS) -o $(BIN_DIR)/$(TARGET).axf  $(OBJ_LIST) $(ROMIMG) $(LIBFLAGS) -T$(LDSCRIPT)  
	$(OBJDUMP) -d $(BIN_DIR)/$(TARGET).axf > $(BIN_DIR)/$(TARGET).asm

# Manipulate Image
# -------------------------------------------------------------------
	
.PHONY: manipulate_images
manipulate_images: | application_s
	@echo ===========================================================
	@echo Image manipulating
	@echo ===========================================================
	# cp $(AMEBAZ2_BOOTLOADERDIR)/bootloader.bin $(BIN_DIR)/bootloader.bin
# ifeq ($(findstring Linux, $(OS)), Linux)
#	chmod 0774 $(ELF2BIN)
# endif
	# $(ELF2BIN) keygen keycfg.json
	# $(ELF2BIN) convert amebaz2_bootloader.json PARTITIONTABLE
	# $(ELF2BIN) convert amebaz2_firmware_is.json FIRMWARE
	# $(ELF2BIN) combine $(BIN_DIR)/flash_is.bin PTAB=partition.bin,BOOT=$(BIN_DIR)/bootloader.bin,FW1=$(BIN_DIR)/firmware_is.bin

# Generate build info
# -------------------------------------------------------------------	

.PHONY: build_info
build_info:
	@echo \#define RTL_FW_COMPILE_TIME RTL8710CFW_COMPILE_TIME\ > .ver
	@echo \#define RTL_FW_COMPILE_DATE RTL8710CFW_COMPILE_DATE\ >> .ver
	@echo \#define UTS_VERSION \"`date +%Y/%m/%d-%T`\" >> .ver
	@echo \#define RTL8710CFW_COMPILE_TIME \"`date +%Y/%m/%d-%T`\" >> .ver
	@echo \#define RTL8710CFW_COMPILE_DATE \"`date +%Y%m%d`\" >> .ver
	@echo \#define RTL8710CFW_COMPILE_BY \"`id -u -n`\" >> .ver
	@echo \#define RTL8710CFW_COMPILE_HOST \"`$(HOSTNAME_APP)`\" >> .ver
	@if [ -x /bin/dnsdomainname ]; then \
		echo \#define RTL8710CFW_COMPILE_DOMAIN \"`dnsdomainname`\"; \
	elif [ -x /bin/domainname ]; then \
		echo \#define RTL8710CFW_COMPILE_DOMAIN \"`domainname`\"; \
	else \
		echo \#define RTL8710CFW_COMPILE_DOMAIN ; \
	fi >> .ver

	@echo \#define RTL8710CFW_COMPILER \"gcc `$(CC) $(CFLAGS) -dumpversion | tr --delete '\r'`\" >> .ver
	@mv -f .ver ../inc/$@.h

.PHONY: prerequirement
prerequirement:
	@if [ ! -d $(ARM_GCC_TOOLCHAIN) ]; then \
		echo ===========================================================; \
		echo Toolchain not found, \"make toolchain\" first!; \
		echo ===========================================================; \
		exit -1; \
	fi
	@echo ===========================================================
	@echo Build $(TARGET)
	@echo ===========================================================
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(INFO_DIR)

$(SRC_O): %_$(TARGET).o : %.c | prerequirement
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -MM -MT $@ -MF $(OBJ_DIR)/$(notdir $(patsubst %.o,%.d,$@))
	cp $@ $(OBJ_DIR)/$(notdir $@)
	mv $(notdir $*.i) $(INFO_DIR)
	mv $(notdir $*.s) $(INFO_DIR)
	chmod 777 $(OBJ_DIR)/$(notdir $@)

$(SRAM_O): %_$(TARGET).o : %.c | prerequirement
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(OBJCOPY) --prefix-alloc-sections .sram $@
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -MM -MT $@ -MF $(OBJ_DIR)/$(notdir $(patsubst %.o,%.d,$@))
	cp $@ $(OBJ_DIR)/$(notdir $@)
	mv $(notdir $*.i) $(INFO_DIR)
	mv $(notdir $*.s) $(INFO_DIR)
	chmod 777 $(OBJ_DIR)/$(notdir $@)

$(ERAM_O): %_$(TARGET).o : %.c | prerequirement
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(OBJCOPY) --prefix-alloc-sections .psram $@
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -MM -MT $@ -MF $(OBJ_DIR)/$(notdir $(patsubst %.o,%.d,$@))
	cp $@ $(OBJ_DIR)/$(notdir $@)
	mv $(notdir $*.i) $(INFO_DIR)
	mv $(notdir $*.s) $(INFO_DIR)
	chmod 777 $(OBJ_DIR)/$(notdir $@)

-include $(DEPENDENCY_LIST)

# Only needed for FPGA phase
.PHONY: romdebug
romdebug:
ifeq ($(findstring CYGWIN, $(OS)), CYGWIN) 
#	$(FLASH_TOOLDIR)/Check_Jtag.sh
	cmd /c start $(GDB) -x ./rtl_gdb_debug_jlink.txt	
else
	$(GDB) -x ./rtl_gdb_debug_jlink.txt	
endif

.PHONY: flash
flash:
#	@if [ ! -f $(FLASH_TOOLDIR)/rtl_gdb_flash_write.txt ] ; then echo Please do /"make setup GDB_SERVER=[jlink or openocd]/" first; echo && false ; fi
#ifeq ($(findstring CYGWIN, $(OS)), CYGWIN) 
#	$(FLASH_TOOLDIR)/Check_Jtag.sh
#endif
	# chmod +rx $(AMEBAZ2_GCCTOOLDIR)/flashloader.sh
	# $(AMEBAZ2_GCCTOOLDIR)/flashloader.sh application_s/Debug/bin/flash_is.bin
	# $(GDB) -x $(AMEBAZ2_GCCTOOLDIR)/rtl_gdb_flashloader_jlink.txt

.PHONY: debug
debug:
	#chmod +rx $(AMEBAZ2_GCCTOOLDIR)/debug.sh
	#$(AMEBAZ2_GCCTOOLDIR)/debug.sh $(BIN_DIR)/$(TARGET).axf
	@echo "add-symbol-file $(BIN_DIR)/$(TARGET).axf 0x0" >> debug.gdb
	#$(GDB) -x $(AMEBAZ2_GCCTOOLDIR)/rtl_gdb_debug_jlink.txt

.PHONY: clean
clean:
	rm -rf $(TARGET)
	rm -f $(SRC_O) $(SRAM_O) $(ERAM_O)
	rm -f $(patsubst %.o,%.d,$(SRC_O)) $(patsubst %.o,%.d,$(SRAM_O)) $(patsubst %.o,%.d,$(ERAM_O))
	rm -f $(patsubst %.o,%.su,$(SRC_O)) $(patsubst %.o,%.su,$(SRAM_O)) $(patsubst %.o,%.su,$(ERAM_O))
	rm -f *.i
	rm -f *.s

