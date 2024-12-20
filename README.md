# C++ Assembler

This is a simple **assembler** program written in C++ that reads assembly language instructions, processes them, and outputs the corresponding machine code in binary format.

## Features:
- Supports basic opcodes like `AND`, `ADD`, `LDA`, `STA`, etc.
- Supports labels such as `SUB`, `MIN`, and `DIF`, which are mapped to specific memory addresses.
- Handles `HEX` constants, where values like `HEX 10` are converted from hexadecimal to binary.
- Reads assembly code from the console and outputs the binary machine code for each instruction.

## How It Works:
- **Input**: The program reads assembly instructions entered by the user.
- **Instructions**: The instructions should be in the format:
  - **Opcode**: The operation (e.g., `LDA`, `ADD`).
  - **Operand**: Can be a label (`SUB`, `MIN`, `DIF`), a constant (`HEX`), or a memory address.
  
- **Output**: The program outputs the machine code for each instruction in **binary** format.

### Supported Opcodes:
The program supports the following opcodes, which are translated into 16-bit binary machine code:
- `AND`, `ADD`, `LDA`, `STA`, `BUN`, `BSA`, `ISZ`, `CLA`, `CLE`, `CMA`, `CME`, `CIR`, `CIL`, `INC`, `SPA`, `SNA`, `SZA`, `SZE`, `HLT`, `INP`, `OUT`, `SKI`, `SKO`, `ION`, `IOF`.

### Supported Labels:
The following labels are mapped to static memory addresses:
- `SUB` -> `0x200`
- `MIN` -> `0x300`
- `DIF` -> `0x400`
