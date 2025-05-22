#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/disassembler.h"


void setup_redirect(void) {
    cr_redirect_stdout();
}

/**
 * TODO: Write More Robust Tests
 *
 * STEPS:
 * - Write more robust dis_OpSize tests
 * - Write robust initialization test
 */
Test(disassembler, disassemble_known_opcodes, .init = setup_redirect) {
    unsigned char codebuffer[] = {
        0x00,                         // NOP
        0x00,                         // NOP
        0x00,                         // NOP
        0xC3, 0xD4, 0x18,             // JMP $18d4
        0x00, 0x00,                   // NOP x2
        0xF5, 0xC5, 0xD5, 0xE5,       // PUSH PSW, B, D, H
        0xC3, 0x8C, 0x00,             // JMP $008c
        0x00,                         // NOP
        0xF5, 0xC5, 0xD5, 0xE5,       // PUSH PSW, B, D, H
        0x3E, 0x80,                   // MVI A,#0x80
        0x32, 0x72, 0x20              // STA $2072
    };

    int pc = 0;
    while (pc < (int)sizeof(codebuffer)) {
        pc += disassemble8080Op(codebuffer, pc);
    }

    cr_assert_stdout_eq_str(
        "0000 00       NOP\n"
        "0001 00       NOP\n"
        "0002 00       NOP\n"
        "0003 c3 d4 18 JMP    $18d4\n"
        "0006 00       NOP\n"
        "0007 00       NOP\n"
        "0008 f5       PUSH   PSW\n"
        "0009 c5       PUSH   B\n"
        "000a d5       PUSH   D\n"
        "000b e5       PUSH   H\n"
        "000c c3 8c 00 JMP    $008c\n"
        "000f 00       NOP\n"
        "0010 f5       PUSH   PSW\n"
        "0011 c5       PUSH   B\n"
        "0012 d5       PUSH   D\n"
        "0013 e5       PUSH   H\n"
        "0014 3e 80    MVI    A,#0x80\n"
        "0016 32 72 20 STA    $2072\n"
    );
}

Test(disassembler, opcode_NOP, .init = setup_redirect) {
    unsigned char code[] = { 0x00 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 1);
    cr_assert_stdout_eq_str("0000 00       NOP\n");
}

Test(disassembler, opcode_PUSH_B, .init = setup_redirect) {
    unsigned char code[] = { 0xC5 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 1);
    cr_assert_stdout_eq_str("0000 c5       PUSH   B\n");
}

// 2-Byte Instructions
Test(disassembler, opcode_MVI_A, .init = setup_redirect) {
    unsigned char code[] = { 0x3E, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 3e 80    MVI    A,#0x80\n");
}

// 3-Byte Instructions
Test(disassembler, opcode_JMP, .init = setup_redirect) {
    unsigned char code[] = { 0xC3, 0xD4, 0x18 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 c3 d4 18 JMP    $18d4\n");
}

Test(disassembler, opcode_STA, .init = setup_redirect) {
    unsigned char code[] = { 0x32, 0x72, 0x20 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 32 72 20 STA    $2072\n");
}

// Error Case: Incomplete Instruction
Test(disassembler, incomplete_JMP, .init = setup_redirect) {
    unsigned char code[] = { 0xC3, 0x12 }; // Missing third byte
    int len = disassemble8080Op(code, 0);
    cr_assert(len <= 2); // Adjust depending on your function's behavior
    // Optional: check output if you emit a placeholder/error
}


// Unknown Opcode
Test(disassembler, unknown_opcode, .init = setup_redirect) {
    unsigned char code[] = { 0xdd }; // Undefined in 8080
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 1);
    // Optional: cr_assert_stdout_eq_str("   0000 ff       ???\n");
}
