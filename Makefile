
.PHONY: all build clean install

INSTALL_PATH ?= $(HOME)/.badgeteam/badgesdk

all: build install

checktools:
	@riscv64-linux-gnu-g++ --version 1>/dev/null 2>/dev/null || echo "[31mPlease install g++-riscv64-linux-gnu[0m"
	@riscv64-linux-gnu-gcc --version 1>/dev/null 2>/dev/null || echo "[31mPlease install gcc-riscv64-linux-gnu[0m"
	@riscv64-linux-gnu-gcc --version 1>/dev/null 2>/dev/null && riscv64-linux-gnu-g++ --version 1>/dev/null 2>/dev/null

build: checktools
	@mkdir -p build
	@mkdir -p build/gen_include
	@mkdir -p build/gen_lib
	@mkdir -p build/gen_lib_stubs
	@cd build && BUILD_PATH=$(shell pwd)/build cmake ..
	@cd build && BUILD_PATH=$(shell pwd)/build make -s -j$(shell nproc)

clean:
	rm -rf build

install:
	@echo "[32mInstalling to $(INSTALL_PATH)[0m"
	@mkdir -p $(INSTALL_PATH)
	@mkdir -p $(INSTALL_PATH)/include
	@mkdir -p $(INSTALL_PATH)/lib
	@mkdir -p $(INSTALL_PATH)/lib_stubs
	@cp -r files_to_copy/* $(INSTALL_PATH)/
	@cp -r build/gen_include/* $(INSTALL_PATH)/include/
	@cp -r build/gen_lib/* $(INSTALL_PATH)/lib/
	@cp -r build/gen_lib_stubs/* $(INSTALL_PATH)/lib_stubs/
	@echo "*link_libgcc:" > $(INSTALL_PATH)/link/default.specs
	@echo "-L$(INSTALL_PATH)/lib -L$(INSTALL_PATH)/lib_stubs" >> $(INSTALL_PATH)/link/default.specs
	@BADGESDK_PATH=$(INSTALL_PATH) python3 add_to_bashrc.py
	@echo "[32mDone![0m"
