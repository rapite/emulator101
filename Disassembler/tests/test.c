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
 * - Test the following 3 Byte instructions
 * 0x22 0x2a 0x32 0x3a 0xc2 0xc3 0xc4
 * 0xca 0xcc 0xcd 0xd2 0xd4 0xda 0xdc 0xe2 0xe4 0xea 0xec
 * 0xf2 0xf4 0xfa 0xfc
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
// LXI Instructions
Test(disassembler, opcode_LXI_B, .init = setup_redirect) {
    unsigned char code[] = { 0x01, 0x34, 0x12 }; // 0x01
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 01 34 12 LXI B, #0x1234\n"); // B <- byte 3, C <- byte 2
}

Test(disassembler, opcode_LXI_D, .init = setup_redirect) {
    unsigned char code[] = { 0x11, 0x34, 0x12 }; // 0x11 
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 11 34 12 LXI D, #0x1234\n"); // D <- byte 3, E <- byte 2
}

Test(disassembler, opcode_LXI_H, .init = setup_redirect) {
    unsigned char code[] = { 0x21, 0x34, 0x12 }; // 0x21
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 21 34 12 LXI H, #0x1234\n"); // H <- byte 3, L <- byte 2
}

Test(disassembler, opcode_LXI_SP, .init = setup_redirect) {
    unsigned char code[] = { 0x31, 0x34, 0x12 }; // 0x31
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 31 34 12 LXI H, #0x1234\n"); // SP.hi <- byte 3, SP.lo <- byte 2
}
// SHLD
Test(disassembler, opcode_SHLD, .init = setup_redirect) {
    unsigned char code[] = { 0x22, 0x34, 0x12 }; // 0x22
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 22 34 12 SHLD $1234\n"); // (adr) <-L; (adr+1)<-H
}

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
