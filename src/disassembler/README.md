# Disassembler [P1]

## Description
This program disassembles a stream of hex numbers into assembly source code and prints out the name of the opcode using the bytes after the opcode as data.

## Features
- Arbitrary placeholder feature
- Less arbitrary placehold feature

## Usage
chartohex.c converts string representations of hexadecimal words into bytecode using strtoul
chartohex2.c converts file representations of hexadecimal words into bytecode using strtoul.
disassembler.c provides functionality to return the byte size of opcode instructions.

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

## Build Instructions
```bash
make main
