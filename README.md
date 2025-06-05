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

## Goals
The major goals of this project include:
- How to maintain a C project on github
- How to maintain a proper readme and changelog
- How to write unit tests with Criterion
- How to write good documents with Doxygen
- How to build good makefiles
- How to use gcc, Make
- How to write a disassembler
- How to use good C (or even general) styling formats

## Building the Project

```bash
make          # Builds all components
make clean    # Removes compiled binaries