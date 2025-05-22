#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/disassembler.h"


void setup_redirect(void) {
    cr_redirect_stdout();
}

/**
 * TODO: Evaluate the quality of gptTests
 *
 * STEPS:
 */
// 1-Byte Instructions
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
    cr_assert_eq(len, 2); // Adjust depending on your function's behavior
    // Optional: check output if you emit a placeholder/error
}

// Unknown Opcode
Test(disassembler, unknown_opcode, .init = setup_redirect) {
    unsigned char code[] = { 0xdd }; // Undefined in 8080
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 1);
    // Optional: cr_assert_stdout_eq_str("   0000 ff       ???\n");
}
