## Folder and Files

   * **msp432p401r.lds** - The linker file used to linking  

<br />

‘**src**’ folder : contains five source files (*.c)  

   * **Makefile** - The makefile

   * **sources.mk** - The source file

   * **main.c** - Main file

   * **memory.c** - File that interacts with memory through an IO abstraction interface

   * **interrupts_msp432p401r_gcc.c** - MSP432 specific C-file for interrupts

   * **startup_msp432p401r_gcc.c** - MSP432 specific C-file for startup

   * **system_msp432p401r.c** - MSP432 specific C-file for for system information

<br />

‘**include**’ folder : contains the three directories of supporting header files  

   * **common** - Contains common headers for both platform targets

   * **msp432** - Contains MSP432 platform headers

   * **CMSIS** - Contains ARM architecture specific headers

<br />

## Platforms and Flag Support

This building support two target platforms and their own specific compilers. These two platforms are  
   * **HOST**

   * **MSP432**

The host embedded system will use the native compiler and the MSP432 embedded system will use the cross  compiler.  

<br />

Compiling Specific Flags  
   * **STD** - Compiler standard version (c89, c99)

   * **CC** - Compiler that will perform the build (Native or Cross)

   * **SIZE** - Tool that will perform the build report of code size

   * **OBJDUMP** - Tool that will perform the dump information about an object file

   * **CFLAGS** - C-programming flags for gcc

   * **CPPFLAGS** - C-Preprocessor Flags

   * **LDFLAGS** - Linker Flags

   * **GFLAGS** - General Flags (Both Platforms)
       * -Wall
       * -Werror
       * -g
       * -O0
       * -std

   * **PLATFORM** - The target platform you are compiling for (Platform Specific) (MASP432, HOST)

   * **SOURCES** - The list of sources files that will need to be compiled (Platform specific)

   * **INCLUDES** - The list of include directories

   * **TARGET** - Name of output executable

<br />

Architecture Specific Flags (ARM only)  
   * -mcpu=cortex-m4

   * -mthumb

   * -march=armv7e-m

   * -mfloat-abi=hard

   * -mfpu=fpv4-sp-d16

   * --specs=nosys.specs

<br />

## Build Target Guidelines
### Specifying Platform
Can be specified platform HOST or MSP432.  
```
    make build PLATFORM=HOST
```
```
    make build PLATFORM=MSP432
```
*Default platform is MSP432.*
```
    make build
```
---

### %.i
Generate the preprocessed output of all c-program implementation files. You can do this by providing a single target name.  
```
    $ make <file>.i
```

### %.d
Generate the dependency files for each source files. You can do this by providing a single target name.  
```
    $ make <file>.d
```

### %.asm
Generate assembly output of c-program implementation files. You can do this by providing a single target name.  
```
    $ make <file>.asm
```

### %.o
Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.  
```
    $ make <file>.o
```

### compile-all
Compile all object files, but DO NOT link.  
```
    $ make compile-all
```

### Build
Compile all object files, but DO NOT link.  
```
    $ make
```
```
    $ make all
```
```
    $ make build
```

### Clean
Remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.  
```
    $ make clean
```
