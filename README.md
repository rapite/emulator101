# 8080 Emulator & Disassembler

A modular C project for disassembling and emulating Intel 8080 programs. This repository includes a functional disassembler and a preliminary CPU emulator capable of interpreting ROM dumps of classic arcade games like *Space Invaders*.

### [Disassembler](src/disassembler/README.md)
A tool to convert binary or hexdump files into readable 8080 assembly instructions.

- Converts binary/hex input to readable disassembly
- Supports most documented 8080 instructions
- Input can be sourced from files in `data/`

### [Emulator](src/emulator/README.md)
An early-stage Intel 8080 emulator. Includes support for:

- Basic register/memory operations
- Stack and instruction pointer logic
- Designed to grow into a full CPU core

## Building the Project

```bash
make          # Builds all components
make clean    # Removes compiled binaries