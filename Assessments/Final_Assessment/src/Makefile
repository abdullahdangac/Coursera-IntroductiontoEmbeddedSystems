#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#******************************************************************************

#------------------------------------------------------------------------------
# Below are the instructions use for the C1M2 Assessment
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - Builds <FILE>.i preprocessed file
#      <FILE>.d - Builds <FILE>.d dependency file
#      <FILE>.asm - Builds <FILE>.asm assembly file
#      <FILE>.o - Builds <FILE>.o object file
#      compile-all - Builds and links all source files
#      build - Builds and links all source files
#      all - Same as build
#      clean - Removes all generated files
#
# Platform Overrides:
#      PLATFORM - The target platform you are compiling for (MSP432, HOST)
#
# Other Overrides:
#      TARGET - Name of output executable
#      STD - Compiler standard version (c89, c99)
#
# Compile Time Overrides:
#      COURSE1 - Call course1 test implementation file from main (TRUE, FALSE)
#      VERBOSE - Can enable/disable debug printing in stats file (TRUE, FALSE)
#
#------------------------------------------------------------------------------

# Platform Overrides (Default Platform)
PLATFORM = MSP432

include sources.mk

# Other Overrides
TARGET = final_assessment
STD = c99

# Compile Time (Switches) Overrides
COURSE1 = FALSE
VERBOSE = FALSE

# General Flags
GFLAGS = -std=$(STD) -g -Wall -Werror -O0

# Architectures Specific Flags (Only MSP432 Platform)
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
LINKER_FILE = ../msp432p401r.lds

# Compiler Flags and Defines
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	CFLAGS = $(GFLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 
	CPPFLAGS = -D$(PLATFORM) $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
else
	CC = gcc
	SIZE = size
	CFLAGS = $(GFLAGS)
	CPPFLAGS = -D$(PLATFORM) $(INCLUDES)
endif

ifeq ($(COURSE1), TRUE)
	CPPFLAGS += -DCOURSE1
endif

ifeq ($(VERBOSE), TRUE)
	CPPFLAGS += -DVERBOSE
endif

OBJECTS = $(SOURCES:.c=.o)
ASSEMBLIES = $(SOURCES:.c=.asm)
PREPROCESSED = $(SOURCES:.c=.i)
DEPENDENCIES = $(SOURCES:.c=.d)

#******************************************************************************
#                                BUILD RULES
#******************************************************************************

# Compile all object files and link into a final executable. Provide build report of code size information about executable.
.PHONY: build
build: all

.PHONY: all
all : $(TARGET).out

$(TARGET).out : $(OBJECTS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $@
	$(SIZE) -Btd $@

# Generate the preprocessed output of all c-program implementation files.
%.i: %.c
	$(CC) -E $(CFLAGS) $(CPPFLAGS) $< -o $@

# Generate the dependency files for each source files (-M* options [MP, MF, MD, MM, etc]).
%.d: %.c
	$(CC) -E -M $(CFLAGS) $(CPPFLAGS) $< -o $@

# Generate assembly output of c-program implementation files.
%.asm: %.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $< -o $@

# Generate the object file for all c-source files (but do not link) you want to compile.
%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $<

# Compile all object files, but DO NOT link.
.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $^

# Remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
.PHONY: clean
clean:
	rm -f *.d *.i *.o *.asm *.out *.map *.dump
