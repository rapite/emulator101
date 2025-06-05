#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/disassembler.h"


void setup_redirect(void) {
    cr_redirect_stdout();
}

/**
 * TODO: Create tests
 *
 * STEPS:
 * - Consider edge cases including unrecognized opcodes
 */
// 1-Byte Instructions
Test(disassembler, opcode_NOP, .init = setup_redirect) {
    unsigned char code[] = { 0x00 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 1);
    cr_assert_stdout_eq_str("0000 00       NOP\n");
}

// 2-Byte Instructions
Test(disassembler, opcode_MVI_B, .init = setup_redirect) {
    unsigned char code[] = { 0x06, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 06 80    MVI B, #0x80\n"); // B <- byte 2
}

Test(disassembler, opcode_MVI_C, .init = setup_redirect) {
    unsigned char code[] = { 0x0E, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 0E 80    MVI C, #0x80\n"); // C <- byte 2
}

Test(disassembler, opcode_MVI_D, .init = setup_redirect) {
    unsigned char code[] = { 0x16, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 16 80    MVI D, #0x80\n"); // D <- byte 2
}

Test(disassembler, opcode_MVI_E, .init = setup_redirect) {
    unsigned char code[] = { 0x1E, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 1E 80    MVI E, #0x80\n"); // E <- byte 2
}

Test(disassembler, opcode_MVI_H, .init = setup_redirect) {
    unsigned char code[] = { 0x26, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 26 80    MVI H, #0x80\n"); // H <- byte 2
}

Test(disassembler, opcode_MVI_L, .init = setup_redirect) {
    unsigned char code[] = { 0x2E, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 2E 80    MVI L, #0x80\n"); // L <- byte 2
}

Test(disassembler, opcode_MVI_M, .init = setup_redirect) {
    unsigned char code[] = { 0x36, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 36 80    MVI M, #0x80\n"); // (HL) <- byte 2
}

Test(disassembler, opcode_MVI_A, .init = setup_redirect) {
    unsigned char code[] = { 0x3E, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 3E 80    MVI A, #0x80\n"); // A <- byte 2
}

Test(disassembler, opcode_ADI, .init = setup_redirect) {
    unsigned char code[] = { 0xC6, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 C6 80    ADI A, #0x80\n"); // A <- A + byte
}

Test(disassembler, opcode_ACI, .init = setup_redirect) {
    unsigned char code[] = { 0xCE, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 CE 80    ACI A, #0x80\n"); // A <- A + data + CY
}

Test(disassembler, opcode_OUT, .init = setup_redirect) {
    unsigned char code[] = { 0xD3, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 D3 80    OUT #0x80\n"); // special
}

Test(disassembler, opcode_SUI, .init = setup_redirect) {
    unsigned char code[] = { 0xD6, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 D6 80    SUI #0x80\n"); // A <- A - data
}

Test(disassembler, opcode_IN, .init = setup_redirect) {
    unsigned char code[] = { 0xDB, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 DB 80    IN #0x80\n"); // special
}

Test(disassembler, opcode_SBI, .init = setup_redirect) {
    unsigned char code[] = { 0xDE, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 DE 80    SBI #0x80\n"); // A <- A - data - CY
}

Test(disassembler, opcode_ANI, .init = setup_redirect) {
    unsigned char code[] = { 0xE6, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 E6 80    ANI #0x80\n"); // A <- A & data
}

Test(disassembler, opcode_XRI, .init = setup_redirect) {
    unsigned char code[] = { 0xEE, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 EE 80    XRI #0x80\n"); // A <- A ^ data
}

Test(disassembler, opcode_ORI, .init = setup_redirect) {
    unsigned char code[] = { 0xF6, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 F6 80    ORI #0x80\n"); // A <- A | data
}

Test(disassembler, opcode_CPI, .init = setup_redirect) {
    unsigned char code[] = { 0xFE, 0x80 };
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 2);
    cr_assert_stdout_eq_str("0000 FE 80    CPI #0x80\n"); // A - data
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

Test(disassembler, opcode_SHLD, .init = setup_redirect) {
    unsigned char code[] = { 0x22, 0x34, 0x12 }; // 0x22
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 22 34 12 SHLD $1234\n"); // (adr) <-L; (adr+1)<-H
}

Test(disassembler, opcode_LHLD, .init = setup_redirect) {
    unsigned char code[] = { 0x2a, 0x34, 0x12 }; // 0x2a
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 2A 34 12 LHLD $1234\n"); // (adr) <-L; (adr+1)<-H
}

Test(disassembler, opcode_LXI_SP, .init = setup_redirect) {
    unsigned char code[] = { 0x31, 0x34, 0x12 }; // 0x31
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 31 34 12 LXI SP, #0x1234\n"); // SP.hi <- byte 3, SP.lo <- byte 2
}

Test(disassembler, opcode_STA, .init = setup_redirect) {
    unsigned char code[] = { 0x32, 0x34, 0x12 }; // 0x32
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 32 34 12 STA $1234\n"); // (adr) <- A
}

Test(disassembler, opcode_LDA, .init = setup_redirect) {
    unsigned char code[] = { 0x3A, 0x34, 0x12 }; // 0x3a
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 3A 34 12 LDA $1234\n"); // A <- (adr)
}

Test(disassembler, opcode_JNZ, .init = setup_redirect) {
    unsigned char code[] = { 0xC2, 0xD4, 0x18 }; // 0xc2
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 C2 D4 18 JNZ $18D4\n"); // if NZ, PC <- adr
}

Test(disassembler, opcode_JMP, .init = setup_redirect) {
    unsigned char code[] = { 0xC3, 0xD4, 0x18 }; // 0xc3
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 C3 D4 18 JMP $18D4\n");
}

Test(disassembler, opcode_CNZ, .init = setup_redirect) {
    unsigned char code[] = { 0xC4, 0xD4, 0x18 }; // 0xc4
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 C4 D4 18 CNZ $18D4\n"); // if NZ, CALL adr
}

Test(disassembler, opcode_JZ, .init = setup_redirect) {
    unsigned char code[] = { 0xCA, 0xD4, 0x18 }; // 0xca
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 CA D4 18 JZ $18D4\n"); // if Z, PC <- adr
}

Test(disassembler, opcode_CZ, .init = setup_redirect) {
    unsigned char code[] = { 0xCC, 0xD4, 0x18 }; // 0xc
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 CC D4 18 CZ $18D4\n"); // if Z, CALL adr
}

Test(disassembler, opcode_CALL, .init = setup_redirect) {
    unsigned char code[] = { 0xCD, 0xD4, 0x18 }; // 0xcd
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 CD D4 18 CALL $18D4\n"); // (SP-1)<-PC.hi;(SP-2)<-PC.lo;SP<-SP+2;PC=adr
}

Test(disassembler, opcode_JNC, .init = setup_redirect) {
    unsigned char code[] = { 0xD2, 0xD4, 0x18 }; // 0xd2
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 D2 D4 18 JNC $18D4\n"); // if NCY, PC<-adr
}

Test(disassembler, opcode_CNC, .init = setup_redirect) {
    unsigned char code[] = { 0xD4, 0xD4, 0x18 }; // 0xd4
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 D4 D4 18 CNC $18D4\n"); // if NCY, CALL adr
}

Test(disassembler, opcode_JC, .init = setup_redirect) {
    unsigned char code[] = { 0xDA, 0xD4, 0x18 }; // 0xda
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 DA D4 18 JC $18D4\n"); // if CY, PC<-adr
}

Test(disassembler, opcode_CC, .init = setup_redirect) {
    unsigned char code[] = { 0xDC, 0xD4, 0x18 }; // 0xdc
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 DC D4 18 CC $18D4\n"); // if CY, CALL adr
}

Test(disassembler, opcode_JPO, .init = setup_redirect) {
    unsigned char code[] = { 0xE2, 0xD4, 0x18 }; // 0xe2
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 E2 D4 18 JPO $18D4\n"); // if PO, PC <- adr
}

Test(disassembler, opcode_CPO, .init = setup_redirect) {
    unsigned char code[] = { 0xE4, 0xD4, 0x18 }; // 0xe4
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 E4 D4 18 CPO $18D4\n"); // if PO, CALL adr
}

Test(disassembler, opcode_JPE, .init = setup_redirect) {
    unsigned char code[] = { 0xEA, 0xD4, 0x18 }; // 0xea
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 EA D4 18 JPE $18D4\n"); // if PE, PC <- adr
}

Test(disassembler, opcode_CPE, .init = setup_redirect) {
    unsigned char code[] = { 0xEC, 0xD4, 0x18 }; // 0xec
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 EC D4 18 CPE $18D4\n"); // if PE, CALL adr
}

Test(disassembler, opcode_JP, .init = setup_redirect) {
    unsigned char code[] = { 0xF2, 0xD4, 0x18 }; // 0xf2
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 F2 D4 18 JP $18D4\n"); // if P=1 PC <- adr
}

Test(disassembler, opcode_CP, .init = setup_redirect) {
    unsigned char code[] = { 0xF4, 0xD4, 0x18 }; // 0xf4
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 F4 D4 18 CP $18D4\n"); // if P, PC <- adr
}

Test(disassembler, opcode_JM, .init = setup_redirect) {
    unsigned char code[] = { 0xFA, 0xD4, 0x18 }; // 0xfa
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 FA D4 18 JM $18D4\n"); // if M, PC <- adr
}

Test(disassembler, opcode_CM, .init = setup_redirect) {
    unsigned char code[] = { 0xFC, 0xD4, 0x18 }; // 0xfc
    int len = disassemble8080Op(code, 0);
    cr_assert_eq(len, 3);
    cr_assert_stdout_eq_str("0000 FC D4 18 CM $18D4\n"); // if M, CALL adr
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
