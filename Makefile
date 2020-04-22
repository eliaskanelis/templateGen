###############################################################################
#	Configuration
###############################################################################

# Target name
TARGET = templateGen
# Build path
BUILD_DIR = bin

TEMPLATE_INSTALL_HOME_DIR =	"$(HOME)/.config/templateGen/"


TEMPLATE_INSTALL_DIR =	"$(TEMPLATE_INSTALL_HOME_DIR)templates/"

###############################################################################
#	Toolchain
###############################################################################

CC = gcc
AS = gcc -x assembler-with-cpp
CP = objcopy
AR = ar
SZ = size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

C_FLAGS = -Wall -w -g -std=c11 -DTEMPLATE_INSTALL_DIR=$(TEMPLATE_INSTALL_DIR)

C_INCLUDE =	-I./inc/

C_SOURCE =	src/main.c\
			src/file_io.c

###############################################################################
## Targets
###############################################################################

all: Makefile | $(BUILD_DIR)
	$(CC) $(C_FLAGS) $(C_INCLUDE) $(C_SOURCE) $(C_FLAGS) -o $(BUILD_DIR)/$(TARGET)
	$(SZ) $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR):
	mkdir -p $@

###############################################################################
## Pseudo Targets
###############################################################################

.PHONY: run clean

run: all
	$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

install: all | $(TEMPLATE_INSTALL_DIR)
	cp -avr $(BUILD_DIR)/$(TARGET) ~/bin
	cp -avr templates/template.c $(TEMPLATE_INSTALL_DIR)
	cp -avr templates/template.h $(TEMPLATE_INSTALL_DIR)

$(TEMPLATE_INSTALL_DIR):
	@echo Creating $@
	mkdir -p $@

uninstall:
	rm -rf $(TEMPLATE_INSTALL_HOME_DIR)
