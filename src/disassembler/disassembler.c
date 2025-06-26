#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/disassembler.h"
 /**
 * TODO: write up briefing
 */
int disassemble8080Op(unsigned char *codebuffer, int pc) {
    unsigned char *code = &codebuffer[pc];
    int opbytes = 1;
    printf("%04x ", pc);
    switch (*code) {
        case 0x00: printf("%-8.2X NOP\n", *code);  break;
        case 0x01: printf("%.2X %.2X %.2X LXI B, #0x%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x02: printf("%-8.2X STAX B\n", *code); break;
        case 0x03: printf("%-8.2X INX B\n", *code); break;
        case 0x04: printf("%-8.2X INR B\n", *code); break;
        case 0x05: printf("%-8.2X DCR B\n", *code); break;
        case 0x06: printf("%.2X %-5.2X MVI B, #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0x07: printf("%-8.2X RLC\n", *code); break;
        case 0x09: printf("%-8.2X DAD B\n", *code); break;
        case 0x0A: printf("%-8.2X LDAX B\n", *code); break;
        case 0x0B: printf("%-8.2X DCX B\n", *code); break;
        case 0x0C: printf("%-8.2X INR C\n", *code); break;
        case 0x0D: printf("%-8.2X DCR C\n", *code); break;
        case 0x0E: printf("%.2X %-5.2X MVI C, #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0x0F: printf("%-8.2X RRC\n", *code); break;
        case 0x11: printf("%.2X %.2X %.2X LXI D, #0x%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x12: printf("%-8.2X STAX D\n", *code); break;
        case 0x13: printf("%-8.2X INX D\n", *code); break;
        case 0x14: printf("%-8.2X INR D\n", *code); break;
        case 0x15: printf("%-8.2X DCR D\n", *code); break;
        case 0x16: printf("%.2X %-5.2X MVI D, #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0x17: printf("%-8.2X RAL\n", *code); break;
        //   0x18
        case 0x19: printf("%-8.2X DAD D\n", *code); break;
        case 0x1A: printf("%-8.2X LDAX D\n", *code); break;
        case 0x1B: printf("%-8.2X DCX D\n", *code); break;
        case 0x1C: printf("%-8.2X INR E\n", *code); break;
        case 0x1D: printf("%-8.2X DCR E\n", *code); break;
        case 0x1E: printf("%.2X %-5.2X MVI E, #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0x1F: printf("%-8.2X RAR\n", *code); break;
        //   0x20
        case 0x21: printf("%.2X %.2X %.2X LXI H, #0x%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x22: printf("%.2X %.2X %.2X SHLD $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x23: printf("%-8.2X INH X\n", *code); break;
        case 0x24: printf("%-8.2X INR H\n", *code); break;
        case 0x25: printf("%-8.2X DCR H\n", *code); break;
        case 0x26: printf("%.2X %-5.2X MVI H, #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0x27: printf("%-8.2X DAA\n", *code); break;
        //   0x28
        case 0x29: printf("%-8.2X DAD H\n", *code); break;
        case 0x2A: printf("%.2X %.2X %.2X LHLD $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x2B: printf("%-8.2X DCX H\n", *code); break;
        case 0x2C: printf("%-8.2X INR L\n", *code); break;
        case 0x2D: printf("%-8.2X DCR L\n", *code); break;
        case 0x2E: printf("%.2X %-5.2X MVI L, #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0x2F: printf("%-8.2X CMA\n", *code); break;
        //   0x30
        case 0x31: printf("%.2X %.2X %.2X LXI SP, #0x%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x32: printf("%.2X %.2X %.2X STA $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0x33: printf("%-8.2X INX SP\n", *code); break;
        case 0x34: printf("%-8.2X INR M\n", *code); break;
        case 0x35: printf("%-8.2X DCR M\n", *code); break;
        case 0x36: printf("%.2X %-5.2X MVI M, #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0x37: printf("%-8.2X STC\n", *code); break;
        //   0x38
        case 0x39: printf("%-8.2X DAD SP\n", *code); break;
        case 0x3A: printf("%.2X %.2X %.2X LDA $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0x3B: printf("%-8.2X DCX SP\n", *code); break;
        case 0x3C: printf("%-8.2X INR A\n", *code); break;
        case 0x3D: printf("%-8.2X DCR A\n", *code); break;
        case 0x3E: printf("%.2X %-5.2X MVI A, #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0x3F: printf("%-8.2X CMC\n", *code); break;
        case 0x40: printf("%-8.2X MOV B, B\n", *code); break;
        case 0x41: printf("%-8.2X MOV B, C\n", *code); break; // B <- C
        case 0x42: printf("%-8.2X MOV B, D\n", *code); break;
        case 0x43: printf("%-8.2X MOV B, E\n", *code); break;
        case 0x44: printf("%-8.2X MOV B, H\n", *code); break;
        case 0x45: printf("%-8.2X MOV B, L\n", *code); break;
        case 0x46: printf("%-8.2X MOV B, M\n", *code); break;
        case 0x47: printf("%-8.2X MOV B, A\n", *code); break;
        case 0x48: printf("%-8.2X MOV C, B\n", *code); break;
        case 0x49: printf("%-8.2X MOV C, C\n", *code); break;
        case 0x4A: printf("%-8.2X MOV C, D\n", *code); break;
        case 0x4B: printf("%-8.2X MOV C, E\n", *code); break;
        case 0x4C: printf("%-8.2X MOV C, H\n", *code); break;
        case 0x4D: printf("%-8.2X MOV C, L\n", *code); break;
        case 0x4E: printf("%-8.2X MOV C, M\n", *code); break;
        case 0x4F: printf("%-8.2X MOV C, A\n", *code); break;
        case 0x50: printf("%-8.2X MOV D, B\n", *code); break;
        case 0x51: printf("%-8.2X MOV D, C\n", *code); break;
        case 0x52: printf("%-8.2X MOV D, D\n", *code); break;
        case 0x53: printf("%-8.2X MOV D, E\n", *code); break;
        case 0x54: printf("%-8.2X MOV D, H\n", *code); break;
        case 0x55: printf("%-8.2X MOV D, L\n", *code); break;
        case 0x56: printf("%-8.2X MOV D, M\n", *code); break;
        case 0x57: printf("%-8.2X MOV D, A\n", *code); break;
        case 0x58: printf("%-8.2X MOV E, B\n", *code); break;
        case 0x59: printf("%-8.2X MOV E, C\n", *code); break;
        case 0x5A: printf("%-8.2X MOV E, D\n", *code); break;
        case 0x5B: printf("%-8.2X MOV E, E\n", *code); break;
        case 0x5C: printf("%-8.2X MOV E, H\n", *code); break;
        case 0x5D: printf("%-8.2X MOV E, L\n", *code); break;
        case 0x5E: printf("%-8.2X MOV E, M\n", *code); break;
        case 0x5F: printf("%-8.2X MOV E, A\n", *code); break;
        case 0x60: printf("%-8.2X MOV H, B\n", *code); break;
        case 0x61: printf("%-8.2X MOV H, C\n", *code); break;
        case 0x62: printf("%-8.2X MOV H, D\n", *code); break;
        case 0x63: printf("%-8.2X MOV H, E\n", *code); break;
        case 0x64: printf("%-8.2X MOV H, H\n", *code); break;
        case 0x65: printf("%-8.2X MOV H, L\n", *code); break;
        case 0x66: printf("%-8.2X MOV H, M\n", *code); break; // H <- (HL)
        case 0x67: printf("%-8.2X MOV H, A\n", *code); break;
        case 0x68: printf("%-8.2X MOV L, B\n", *code); break;
        case 0x69: printf("%-8.2X MOV L, C\n", *code); break;
        case 0x6A: printf("%-8.2X MOV L, D\n", *code); break;
        case 0x6B: printf("%-8.2X MOV L, E\n", *code); break;
        case 0x6C: printf("%-8.2X MOV L, H\n", *code); break;
        case 0x6D: printf("%-8.2X MOV L, L\n", *code); break;
        case 0x6E: printf("%-8.2X MOV L, M\n", *code); break;
        case 0x6F: printf("%-8.2X MOV L, A\n", *code); break;
        case 0x70: printf("%-8.2X MOV M, B\n", *code); break;
        case 0x71: printf("%-8.2X MOV M, C\n", *code); break;
        case 0x72: printf("%-8.2X MOV M, D\n", *code); break;
        case 0x73: printf("%-8.2X MOV M, E\n", *code); break;
        case 0x74: printf("%-8.2X MOV M, H\n", *code); break;
        case 0x75: printf("%-8.2X MOV M, L\n", *code); break;
        case 0x76: printf("%-8.2X HLT\n", *code); break; // HLT (Special)
        case 0x77: printf("%-8.2X MOV M, A\n", *code); break;
        case 0x78: printf("%-8.2X MOV A, B\n", *code); break;
        case 0x79: printf("%-8.2X MOV A, C\n", *code); break;
        case 0x7A: printf("%-8.2X MOV A, D\n", *code); break;
        case 0x7B: printf("%-8.2X MOV A, E\n", *code); break;
        case 0x7C: printf("%-8.2X MOV A, H\n", *code); break;
        case 0x7D: printf("%-8.2X MOV A, L\n", *code); break;
        case 0x7E: printf("%-8.2X MOV A, M\n", *code); break;
        case 0x7F: printf("%-8.2X MOV A, A\n", *code); break;
        // Flags: Z, S, P, CY, AC from 0x80 to 0xBF
        case 0x80: printf("%-8.2X ADD B\n", *code); break; // 	A <- A + B
        case 0x81: printf("%-8.2X ADD C\n", *code); break; 
        case 0x82: printf("%-8.2X ADD D\n", *code); break; 
        case 0x83: printf("%-8.2X ADD E\n", *code); break; 
        case 0x84: printf("%-8.2X ADD H\n", *code); break; 
        case 0x85: printf("%-8.2X ADD L\n", *code); break; 
        case 0x86: printf("%-8.2X ADD M\n", *code); break; 
        case 0x87: printf("%-8.2X ADD A\n", *code); break; 
        case 0x88: printf("%-8.2X ADC B\n", *code); break; // 	A <- A + B + CY
        case 0x89: printf("%-8.2X ADC C\n", *code); break; 
        case 0x8A: printf("%-8.2X ADC D\n", *code); break; 
        case 0x8B: printf("%-8.2X ADC E\n", *code); break; 
        case 0x8C: printf("%-8.2X ADC H\n", *code); break; 
        case 0x8D: printf("%-8.2X ADC L\n", *code); break; 
        case 0x8E: printf("%-8.2X ADC M\n", *code); break; 
        case 0x8F: printf("%-8.2X ADC A\n", *code); break; 
        case 0x90: printf("%-8.2X SUB B\n", *code); break; // A <- A - B
        case 0x91: printf("%-8.2X SUB C\n", *code); break; 
        case 0x92: printf("%-8.2X SUB D\n", *code); break; 
        case 0x93: printf("%-8.2X SUB E\n", *code); break; 
        case 0x94: printf("%-8.2X SUB H\n", *code); break; 
        case 0x95: printf("%-8.2X SUB L\n", *code); break; 
        case 0x96: printf("%-8.2X SUB M\n", *code); break; 
        case 0x97: printf("%-8.2X SUB A\n", *code); break; 
        case 0x98: printf("%-8.2X SBB B\n", *code); break; // A <- A - B - CY
        case 0x99: printf("%-8.2X SBB C\n", *code); break; 
        case 0x9A: printf("%-8.2X SBB D\n", *code); break; 
        case 0x9B: printf("%-8.2X SBB E\n", *code); break; 
        case 0x9C: printf("%-8.2X SBB H\n", *code); break; 
        case 0x9D: printf("%-8.2X SBB L\n", *code); break; 
        case 0x9E: printf("%-8.2X SBB M\n", *code); break; 
        case 0x9F: printf("%-8.2X SBB A\n", *code); break; 
        case 0xA0: printf("%-8.2X ANA B\n", *code); break; // A <- A & B
        case 0xA1: printf("%-8.2X ANA C\n", *code); break; 
        case 0xA2: printf("%-8.2X ANA D\n", *code); break; 
        case 0xA3: printf("%-8.2X ANA E\n", *code); break; 
        case 0xA4: printf("%-8.2X ANA H\n", *code); break; 
        case 0xA5: printf("%-8.2X ANA L\n", *code); break; 
        case 0xA6: printf("%-8.2X ANA M\n", *code); break; 
        case 0xA7: printf("%-8.2X ANA A\n", *code); break; 
        case 0xA8: printf("%-8.2X XRA B\n", *code); break; // A <- A ^ B
        case 0xA9: printf("%-8.2X XRA C\n", *code); break; 
        case 0xAA: printf("%-8.2X XRA D\n", *code); break; 
        case 0xAB: printf("%-8.2X XRA E\n", *code); break; 
        case 0xAC: printf("%-8.2X XRA H\n", *code); break; 
        case 0xAD: printf("%-8.2X XRA L\n", *code); break; 
        case 0xAE: printf("%-8.2X XRA M\n", *code); break; 
        case 0xAF: printf("%-8.2X XRA A\n", *code); break; 
        case 0xB0: printf("%-8.2X ORA B\n", *code); break; // A <- A | B
        case 0xB1: printf("%-8.2X ORA C\n", *code); break; 
        case 0xB2: printf("%-8.2X ORA D\n", *code); break; 
        case 0xB3: printf("%-8.2X ORA E\n", *code); break; 
        case 0xB4: printf("%-8.2X ORA H\n", *code); break; 
        case 0xB5: printf("%-8.2X ORA L\n", *code); break; 
        case 0xB6: printf("%-8.2X ORA M\n", *code); break; 
        case 0xB7: printf("%-8.2X ORA A\n", *code); break; 
        case 0xB8: printf("%-8.2X CMP B\n", *code); break; // A - B
        case 0xB9: printf("%-8.2X CMP C\n", *code); break; 
        case 0xBA: printf("%-8.2X CMP D\n", *code); break; 
        case 0xBB: printf("%-8.2X CMP E\n", *code); break; 
        case 0xBC: printf("%-8.2X CMP H\n", *code); break; 
        case 0xBD: printf("%-8.2X CMP L\n", *code); break; 
        case 0xBE: printf("%-8.2X CMP M\n", *code); break; 
        case 0xBF: printf("%-8.2X CMP A\n", *code); break; 
        case 0xC0: printf("%-8.2X RNZ\n", *code); break; // RNZ
        case 0xC1: printf("%-8.2X POP B\n", *code); break; // POP B C <- (sp); B <- (sp+1); sp <- sp+2
        case 0xC2: printf("%.2X %.2X %.2X JNZ $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xC3: printf("%.2X %.2X %.2X JMP $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xC4: printf("%.2X %.2X %.2X CNZ $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xC5: printf("%-8.2X PUSH B\n", *code); break;
        case 0xC6: printf("%.2X %-5.2X ADI A, #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0xC7: printf("%-8.2X RST 0\n", *code); break;
        case 0xC8: printf("%-8.2X RZ\n", *code); break;
        case 0xC9: printf("%-8.2X RET\n", *code); break;
        case 0xCA: printf("%.2X %.2X %.2X JZ $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        //   0xCB
        case 0xCC: printf("%.2X %.2X %.2X CZ $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xCD: printf("%.2X %.2X %.2X CALL $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xCE: printf("%.2X %-5.2X ACI A, #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0xCF: printf("%-8.2X RST 1\n", *code); break;
        case 0xD0: printf("%-8.2X RNC\n", *code); break;
        case 0xD1: printf("%-8.2X POP D\n", *code); break;
        case 0xD2: printf("%.2X %.2X %.2X JNC $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xD3: printf("%.2X %-5.2X OUT #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0xD4: printf("%.2X %.2X %.2X CNC $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xD5: printf("%-8.2X PUSH D\n", *code); break;
        case 0xD6: printf("%.2X %-5.2X SUI #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0xD7: printf("%-8.2X RST 2\n", *code); break;
        case 0xD8: printf("%-8.2X RC\n", *code); break;
        //   0xD9
        case 0xDA: printf("%.2X %.2X %.2X JC $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xDB: printf("%.2X %-5.2X IN #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0xDC: printf("%.2X %.2X %.2X CC $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        //   0xDD
        case 0xDE: printf("%.2X %-5.2X SBI #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0xDF: printf("%-8.2X RST 3\n", *code); break;
        case 0xE0: printf("%-8.2X RPO\n", *code); break;
        case 0xE1: printf("%-8.2X POP H\n", *code); break;
        case 0xE2: printf("%.2X %.2X %.2X JPO $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xE3: printf("%-8.2X XTHL\n", *code); break;
        case 0xE4: printf("%.2X %.2X %.2X CPO $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xE5: printf("%-8.2X PUSH H\n", *code); break;
        case 0xE6: printf("%.2X %-5.2X ANI #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0xE7: printf("%-8.2X RST 4\n", *code); break;
        case 0xE8: printf("%-8.2X RPE\n", *code); break;
        case 0xE9: printf("%-8.2X PCHL\n", *code); break;
        case 0xEA: printf("%.2X %.2X %.2X JPE $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xEB: printf("%-8.2X XCHG\n", *code); break;
        case 0xEC: printf("%.2X %.2X %.2X CPE $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        //   0xED
        case 0xEE: printf("%.2X %-5.2X XRI #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0xEF: printf("%-8.2X RST 5\n", *code); break;
        case 0xF0: printf("%-8.2X RP\n", *code); break;
        case 0xF1: printf("%-8.2X POP PSW\n", *code); break;
        case 0xF2: printf("%.2X %.2X %.2X JP $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xF3: printf("%.2X %.2X %.2X DI $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0xF4: printf("%.2X %.2X %.2X CP $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; 
        case 0xF5: printf("%-8.2X PUSH PSW\n", *code); break;
        case 0xF6: printf("%.2X %-5.2X ORI #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0xF7: printf("%-8.2X RST 6\n", *code); break;
        case 0xF8: printf("%-8.2X RM\n", *code); break;
        case 0xF9: printf("%-8.2X SPHL\n", *code); break;
        case 0xFA: printf("%.2X %.2X %.2X JM $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; 
        case 0xFB: printf("%-8.2X EI\n", *code); break;
        case 0xFC: printf("%.2X %.2X %.2X CM $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; 
        //   0xFD
        case 0xFE: printf("%.2X %-5.2X CPI #0x%.2X\n", code[0], code[1], code[1]); opbytes = 2; break;
        case 0xFF: printf("%-8.2X RST 7\n", *code); break;
    }
    fflush(stdout);
    return opbytes;
}
