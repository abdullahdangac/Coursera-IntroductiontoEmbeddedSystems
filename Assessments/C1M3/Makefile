#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for the cortex-M0+ build system
#
# Use: make [BUILD TARGET] [OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      size - Provide build report of code size
#      nm - Provide reading ELF files
#      readelf - Provide build report of code size
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#      TARGET - Name of target file
#
#------------------------------------------------------------------------------

SRCS = main.c \
       misc.c

# Architecture Specific Flags
CPU = cortex-m0plus
ARCH = thumb
SPECS = nosys.specs

# Platform Specific Flags
LINKER_FILE = msp432p401r.lds 

# Compile Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
NM = arm-none-eabi-nm
SIZE = arm-none-eabi-size
READELF = arm-none-eabi-readelf
OBJDUMP = arm-none-eabi-objdump
LDFLAGS = -Wl,-Map=$(TARGET).out.map -T $(LINKER_FILE)
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall
TARGET = main

OBJS = $(SRCS:.c=.o)

# BUILD RULES

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(OBJDUMP) --disassemble $(TARGET).out > $(TARGET).out.dump

# ---

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@
	$(OBJDUMP) --disassemble $@ > $@.dump

.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) -c $(CFLAGS) $^

# ---

.PHONY: size
size: $(TARGET)
	@echo --------------------- $(TARGET) SIZE UTILITY ------------------------
	$(SIZE) -Atd $<

.PHONY: nm
nm: $(TARGET)
	@echo ---------------------- $(TARGET) NM UTILITY -------------------------
	$(NM) -S --defined --size-sort -s $<

.PHONY: readelf
readelf: $(TARGET)
	@echo ------------------- $(TARGET) READELF UTILITY -----------------------
	$(READELF) $< --all

# ---

.PHONY: clean
clean:
	rm -f *.o *.out *.map *.dump 

