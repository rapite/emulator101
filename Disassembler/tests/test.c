#include <stdio.h>
#include <criterion/criterion.h>
#include "../include/disassembler.h"

/**
 * TODO: Write More Robust Tests
 *
 * STEPS:
 * - Write more robust dis_OpSize tests
 * - Write robust initialization test
 */
Test(disassembler, dis_OpSize) {
    // unsigned char * -> pointer to raw bytes
    int pc = 0;
    // register code is not real
    unsigned char code1[16] = {
        0x00, // NOP (1)
        0x00, // NOP (1)
        0x00, // NOP (1)
        0xc3, // JMP adr (3)
        0xd4,
        0x18,
        0x00, // NOP (1)
        0x00, // NOP (1)
        0xf5, // PUSH PSW (1)
        0xc5, // PUSH B (1)
        0xd5, // PUSH D (1)
        0xe5, // PUSH H (1)
        0xc3, // JUMP $008c (3)
        0x8c,
        0x00,
        0x00 // NOP
    };
    cr_expect(disassemble8080Op(code1, pc) == 1); pc += 1; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 1); pc += 1; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 1); pc += 1; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 3); pc += 3; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 1); pc += 1; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 1); pc += 1; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 1); pc += 1; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 1); pc += 1; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 1); pc += 1; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 1); pc += 1; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 3); pc += 3; printf("\n");
    cr_expect(disassemble8080Op(code1, pc) == 1); pc += 1; printf("\n");
}