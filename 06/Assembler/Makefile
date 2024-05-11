.PHONY: all build cmake clean clean-all

PROJECT_NAME ?= HackAssembler
BUILD_DIR ?= build
BUILD_TYPE ?= Debug 

BUILD_SYSTEM ?= Unix Makefiles

all: build


build: cmake
	$(MAKE) -C $(BUILD_DIR) --no-print-directory

cmake: Makefile 
	cmake \
		-G "$(BUILD_SYSTEM)" \
		-B $(BUILD_DIR) \
		-DPROJECT_NAME=$(PROJECT_NAME) \
		-DCMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		-DCMAKE_TOOLCHAIN_FILE=gcc.cmake 

clean:
	rm -rf $(BUILD_DIR)
