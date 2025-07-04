# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.2.5] - 6/15/2025

### Changed
- Implemented missing opcodes in disassembler.c

## [0.2.4] - 6/13/2025

### Added
- structs.c demonstrating struct initialization of nested struct

### Changed
- Makefile adjusted to build struct

## [0.2.3] - 6/12/2025

### Changed
- Makefile to adjust to new directory

## [0.2.2] - 6/5/2025

### Added
- TODO File

### Changed
- emulator.h details intended black box of Emulator8080Op.

## [0.2.1] - 6/4/2025

### Added
- Emulator header files and skeleton

### Changed
- Project naming schema and overall hierarchy
- Updated various files to reflect changes (Makefile, src files, headers, etc.)

## [0.2.0] - 6/2/2025

### Added
- Implemented chartohex src file 
- 8080Disassembler completed
- Disassembler test src completed

### Changed
- README goals revised

## [0.1.3] - 5/30/2025

### Added
- General debugger for disassembler/main.c

## [0.1.2] - 5/28/2025

### Added
- Disassembler implementation for opcodes of size 2 (tests included)
- Complete implementation of size 1 opcodes

## [0.1.2] - 5/22/2025

### Added
- Disassembler opcode implementations for opcodes of size 3
- Disassembler opcode tests of size 3

## [0.1.1] - 5/21/2025

### Added
- Added in unit tests generated by ChatGPT4o
- Opcode test skeletons and individual opcode tests

### Removed
- Invalid 8080opcodes
    - 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38, 0xcb, 0xd9, 0xdd, 0xed, 0xfd

## [0.1.1] - 5/20/2025

### Added
- Emulator101 starter code to disassembler.c
- Test case skeletons using Criterion

### Changed
- Updated goals
- Updated Implementation TODO's

## [0.1.0] - 5/19/2025

### Added
- Disassembler header and source files
- README project statements and goals
- CHANGELOG information for project

### Changed
- LICENSE adjusted to MIT copyright