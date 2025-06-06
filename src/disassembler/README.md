# Disassembler [P1]

## Description
This program disassembles a stream of hex numbers into assembly source code and prints out the name of the opcode using the bytes after the opcode as data.

## Features
- Returns opcode byte size (1, 2, 3) for number of inputs. 

## Usage
- Strictly accepts little endian hex inputs.
- chartohex.c converts string representations of hexadecimal words into bytecode using strtoul
- chartohex2.c converts file representations of hexadecimal words into bytecode using strtoul.
- disassembler.c provides functionality to return the byte size of opcode instructions.