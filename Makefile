###############################################################################
#	Toolchain
###############################################################################

BINPATH = 
PREFIX = 
CC = $(BINPATH)$(PREFIX)gcc
AS = $(BINPATH)$(PREFIX)gcc -x assembler-with-cpp
CP = $(BINPATH)$(PREFIX)objcopy
AR = $(BINPATH)$(PREFIX)ar
SZ = $(BINPATH)$(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

C_FLAGS = -Wall -w -g -std=c11

C_INCLUDE :=	-I./inc/

C_SOURCE :=	./src/main.c

###############################################################################
#	Configuration
###############################################################################

# Target name
TARGET = templateGen
# Build path
BUILD_DIR = bin

###############################################################################
## Targets
###############################################################################

all: Makefile $(BUILD_DIR)
	$(CC) $(C_FLAGS) $(C_INCLUDE) $(C_SOURCE) $(C_FLAGS) -o $(BUILD_DIR)/$(TARGET)
	$(SZ) $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR):
	mkdir $@
	cp -avr templates $(BUILD_DIR)/templates

###############################################################################
## Pseudo Targets
###############################################################################

.PHONY: run clean

run: all
	$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

install: all
	cp -avr bin/* ~/bin
