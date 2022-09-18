all: is

OS := $(shell uname)
LBITS := $(shell getconf LONG_BIT)

include toolchain.mk


.PHONY: is
is: toolchain
	@$(MAKE) -f application.is.mk

.PHONY: tz
tz: toolchain
	@$(MAKE) -f application.tz.mk

.PHONY: mp
mp: toolchain
	@$(MAKE) -f application.is.mk mp

.PHONY: clean
clean:
	@$(MAKE) -f application.is.mk clean
	@$(MAKE) -f application.tz.mk clean

debug: toolchain
	@$(MAKE) -f application.is.mk debug

debug_tz: toolchain
	@$(MAKE) -f application.tz.mk debug

flash: toolchain
	@$(MAKE) -f application.is.mk flash

flash_tz: toolchain
	@$(MAKE) -f application.tz.mk flash
	
setup:
	@$(MAKE) -f application.is.mk $(MAKECMDGOALS)	

setup_tz:
	@$(MAKE) -f application.tz.mk $(MAKECMDGOALS)
