## Allocated Memory Analyze

Specify where the listed symbols will be placed in our program. Specific symbol elements including:
- **Location Top segment or Type** - Code, Data, Peripheral, Register, None

- **Location Sub-segment** - Stack, Heap, BSS, Data, const/rodata, None

- **Access Permissions**  - Read (R), Write (W) Read-write (RW), None

- **Lifetime** - Function/Block, Program, Indefinite, None

<br />

There are multiple tools can use to help determine segment, sub-segment, permissions and lifetime besides just inspection.
- Generate a **.map** file using the linker flag -Wl,-Map=main.map. With this file you can look find certain assignments listed in the code.

- Use the GCC binary utility **nm** to investigate the code symbols. This will print code/data symbols with the memory properties.

- Use the GCC toolchain and dump a file to assembly with the **-S** option. This will provide some details on how a piece of data is allocated.

<br />
<br />

| Symbol Item                 | Segment            | Sub-segment                | Permissions      | Lifetime                  |
|-----------------------------|--------------------|----------------------------|------------------|---------------------------|
|  g1                         |  Data Segment      |  BSS Sub-segment           |  Read/Write      |  Program Lifetime         |
|  g2                         |  Code Segment      |  const/rodata Sub-segment  |  Read Only       |  Program Lifetime         |
|  g3                         |  Data Segment      |  Data Sub-segment          |  Read/Write      |  Program Lifetime         |
|  g4                         |  Data Segment      |  BSS Sub-segment           |  Read/Write      |  Program Lifetime         |
|  g5                         |  Data Segment      |  Data Sub-segment          |  Read/Write      |  Program Lifetime         |
|  l1                         |  Register Segment  |  None Sub-segment          |  Read/Write      |  Function/Block Lifetime  |
|  l2                         |  Data Segment      |  Stack Sub-segment         |  Read/Write      |  Function/Block Lifetime  |
|  \*l2 (dereferenced)        |  Data Segment      |  Heap Sub-segment          |  Read/Write      |  Indefinite Lifetime      |
|  l3                         |  Data Segment      |  Stack Sub-segment         |  Read/Write      |  Function/Block Lifetime  |
|  f1                         |  Data Segment      |  Stack Sub-segment         |  Read/Write      |  Function/Block Lifetime  |
|  f2                         |  Data Segment      |  BSS Sub-segment           |  Read/Write      |  Program Lifetime         |
|  f3                         |  Data Segment      |  Stack Sub-segment         |  Read/Write      |  Function/Block Lifetime  |
|  Hello World! (The string)  |  Code Segment      |  const/rodata Sub-segment  |  Read Only       |  Program Lifetime         |
|  func()                     |  Code Segment      |  Text Sub-segment          |  Read Only       |  Program Lifetime         |
|  main()                     |  Code Segment      |  Text Sub-segment          |  Read Only       |  Program Lifetime         |
|  SOME_VALUE                 |  No Segment        |  No Sub-segment            |  No Permissions  |  No Lifetime              |
|  N                          |  No Segment        |  No Sub-segment            |  No Permissions  |  No Lifetime              |
