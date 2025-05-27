#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/disassembler.h"

/**
 * @brief Initializes Disassembler
 */
// TODO: Implement main loop in this function
int init8080Op(const char* path) {
    FILE* fp = fopen(path, "r");
    if (!fp) {
        printf("Failed to open %s\n", path);
        exit(1);
    }
    //Get the file size and read it into a memory buffer    
    fseek(fp, 0L, SEEK_END);
    int fsize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    unsigned char *buffer=malloc(fsize);

    fread(buffer, fsize, 1, fp);
    fclose(fp);

    int pc = 0;

    while (pc < fsize) {    
        pc += disassemble8080Op(buffer, pc);
    }
    return 0;
}
/**
 * TODO: Implement full code disassembler
 * Later, eventuall change the behavior of the disassembler for address instructions (0x2a LHLD)
 * to abide by intended 'uint16_t addr' values
 *  
 * STEPS:
 * - Implement all Opcodes from 0x00 to 0xff
 * - Check differences between test case and implementation
 * 
 * -
 */
int disassemble8080Op(unsigned char *codebuffer, int pc) {
    unsigned char *code = &codebuffer[pc];
    int opbytes = 1;
    printf("%04x ", pc);
    switch (*code) {
        case 0x00: printf("%-7.2X NOP\n", *code);  break;
        case 0x01: printf("%.2X %.2X %.2X LXI B, #0x%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x02: printf("%-7.2X\n", *code); break;
        case 0x03: printf("%-7.2X\n", *code); break;
        case 0x04: printf("%-7.2X\n", *code); break;
        case 0x05: printf("%-7.2X\n", *code); break;
        case 0x06: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0x07: printf("%-7.2X\n", *code); break;
        case 0x09: printf("%-7.2X\n", *code); break;
        case 0x0A: printf("%-7.2X\n", *code); break;
        case 0x0B: printf("%-7.2X\n", *code); break;
        case 0x0C: printf("%-7.2X\n", *code); break;
        case 0x0D: printf("%-7.2X\n", *code); break;
        case 0x0E: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0x0F: printf("%-7.2X\n", *code); break;
        case 0x11: printf("%.2X %.2X %.2X LXI D, #0x%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x12: printf("%-7.2X\n", *code); break;
        case 0x13: printf("%-7.2X\n", *code); break;
        case 0x14: printf("%-7.2X\n", *code); break;
        case 0x15: printf("%-7.2X\n", *code); break;
        case 0x16: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0x17: printf("%-7.2X\n", *code); break;
        case 0x19: printf("%-7.2X\n", *code); break;
        case 0x1A: printf("%-7.2X\n", *code); break;
        case 0x1B: printf("%-7.2X\n", *code); break;
        case 0x1C: printf("%-7.2X\n", *code); break;
        case 0x1D: printf("%-7.2X\n", *code); break;
        case 0x1E: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0x1F: printf("%-7.2X\n", *code); break;
        case 0x21: printf("%.2X %.2X %.2X LXI H, #0x%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x22: printf("%.2X %.2X %.2X SHLD $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x23: printf("%-7.2X\n", *code); break;
        case 0x24: printf("%-7.2X\n", *code); break;
        case 0x25: printf("%-7.2X\n", *code); break;
        case 0x26: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0x27: printf("%-7.2X\n", *code); break;
        case 0x29: printf("%-7.2X\n", *code); break;
        case 0x2A: printf("%.2X %.2X %.2X LHLD $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x2B: printf("%-7.2X\n", *code); break;
        case 0x2C: printf("%-7.2X\n", *code); break;
        case 0x2D: printf("%-7.2X\n", *code); break;
        case 0x2E: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0x2F: printf("%-7.2X\n", *code); break;
        case 0x31: printf("%.2X %.2X %.2X LXI SP, #0x%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break;
        case 0x32: printf("%.2X %.2X %.2X STA $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0x33: printf("%-7.2X\n", *code); break;
        case 0x34: printf("%-7.2X\n", *code); break;
        case 0x35: printf("%-7.2X\n", *code); break;
        case 0x36: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0x37: printf("%-7.2X\n", *code); break;
        case 0x39: printf("%-7.2X\n", *code); break;
        case 0x3A: printf("%.2X %.2X %.2X LDA $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0x3B: printf("%-7.2X\n", *code); break;
        case 0x3C: printf("%-7.2X\n", *code); break;
        case 0x3D: printf("%-7.2X\n", *code); break;
        case 0x3E: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0x3F: printf("%-7.2X\n", *code); break;
        case 0x40: printf("%-7.2X\n", *code); break;
        case 0x41: printf("%-7.2X\n", *code); break;
        case 0x42: printf("%-7.2X\n", *code); break;
        case 0x43: printf("%-7.2X\n", *code); break;
        case 0x44: printf("%-7.2X\n", *code); break;
        case 0x45: printf("%-7.2X\n", *code); break;
        case 0x46: printf("%-7.2X\n", *code); break;
        case 0x47: printf("%-7.2X\n", *code); break;
        case 0x48: printf("%-7.2X\n", *code); break;
        case 0x49: printf("%-7.2X\n", *code); break;
        case 0x4A: printf("%-7.2X\n", *code); break;
        case 0x4B: printf("%-7.2X\n", *code); break;
        case 0x4C: printf("%-7.2X\n", *code); break;
        case 0x4D: printf("%-7.2X\n", *code); break;
        case 0x4E: printf("%-7.2X\n", *code); break;
        case 0x4F: printf("%-7.2X\n", *code); break;
        case 0x50: printf("%-7.2X\n", *code); break;
        case 0x51: printf("%-7.2X\n", *code); break;
        case 0x52: printf("%-7.2X\n", *code); break;
        case 0x53: printf("%-7.2X\n", *code); break;
        case 0x54: printf("%-7.2X\n", *code); break;
        case 0x55: printf("%-7.2X\n", *code); break;
        case 0x56: printf("%-7.2X\n", *code); break;
        case 0x57: printf("%-7.2X\n", *code); break;
        case 0x58: printf("%-7.2X\n", *code); break;
        case 0x59: printf("%-7.2X\n", *code); break;
        case 0x5A: printf("%-7.2X\n", *code); break;
        case 0x5B: printf("%-7.2X\n", *code); break;
        case 0x5C: printf("%-7.2X\n", *code); break;
        case 0x5D: printf("%-7.2X\n", *code); break;
        case 0x5E: printf("%-7.2X\n", *code); break;
        case 0x5F: printf("%-7.2X\n", *code); break;
        case 0x60: printf("%-7.2X\n", *code); break;
        case 0x61: printf("%-7.2X\n", *code); break;
        case 0x62: printf("%-7.2X\n", *code); break;
        case 0x63: printf("%-7.2X\n", *code); break;
        case 0x64: printf("%-7.2X\n", *code); break;
        case 0x65: printf("%-7.2X\n", *code); break;
        case 0x66: printf("%-7.2X\n", *code); break;
        case 0x67: printf("%-7.2X\n", *code); break;
        case 0x68: printf("%-7.2X\n", *code); break;
        case 0x69: printf("%-7.2X\n", *code); break;
        case 0x6A: printf("%-7.2X\n", *code); break;
        case 0x6B: printf("%-7.2X\n", *code); break;
        case 0x6C: printf("%-7.2X\n", *code); break;
        case 0x6D: printf("%-7.2X\n", *code); break;
        case 0x6E: printf("%-7.2X\n", *code); break;
        case 0x6F: printf("%-7.2X\n", *code); break;
        case 0x70: printf("%-7.2X\n", *code); break;
        case 0x71: printf("%-7.2X\n", *code); break;
        case 0x72: printf("%-7.2X\n", *code); break;
        case 0x73: printf("%-7.2X\n", *code); break;
        case 0x74: printf("%-7.2X\n", *code); break;
        case 0x75: printf("%-7.2X\n", *code); break;
        case 0x76: printf("%-7.2X\n", *code); break;
        case 0x77: printf("%-7.2X\n", *code); break;
        case 0x78: printf("%-7.2X\n", *code); break;
        case 0x79: printf("%-7.2X\n", *code); break;
        case 0x7A: printf("%-7.2X\n", *code); break;
        case 0x7B: printf("%-7.2X\n", *code); break;
        case 0x7C: printf("%-7.2X\n", *code); break;
        case 0x7D: printf("%-7.2X\n", *code); break;
        case 0x7E: printf("%-7.2X\n", *code); break;
        case 0x7F: printf("%-7.2X\n", *code); break;
        case 0x80: printf("%-7.2X\n", *code); break;
        case 0x81: printf("%-7.2X\n", *code); break;
        case 0x82: printf("%-7.2X\n", *code); break;
        case 0x83: printf("%-7.2X\n", *code); break;
        case 0x84: printf("%-7.2X\n", *code); break;
        case 0x85: printf("%-7.2X\n", *code); break;
        case 0x86: printf("%-7.2X\n", *code); break;
        case 0x87: printf("%-7.2X\n", *code); break;
        case 0x88: printf("%-7.2X\n", *code); break;
        case 0x89: printf("%-7.2X\n", *code); break;
        case 0x8A: printf("%-7.2X\n", *code); break;
        case 0x8B: printf("%-7.2X\n", *code); break;
        case 0x8C: printf("%-7.2X\n", *code); break;
        case 0x8D: printf("%-7.2X\n", *code); break;
        case 0x8E: printf("%-7.2X\n", *code); break;
        case 0x8F: printf("%-7.2X\n", *code); break;
        case 0x90: printf("%-7.2X\n", *code); break;
        case 0x91: printf("%-7.2X\n", *code); break;
        case 0x92: printf("%-7.2X\n", *code); break;
        case 0x93: printf("%-7.2X\n", *code); break;
        case 0x94: printf("%-7.2X\n", *code); break;
        case 0x95: printf("%-7.2X\n", *code); break;
        case 0x96: printf("%-7.2X\n", *code); break;
        case 0x97: printf("%-7.2X\n", *code); break;
        case 0x98: printf("%-7.2X\n", *code); break;
        case 0x99: printf("%-7.2X\n", *code); break;
        case 0x9A: printf("%-7.2X\n", *code); break;
        case 0x9B: printf("%-7.2X\n", *code); break;
        case 0x9C: printf("%-7.2X\n", *code); break;
        case 0x9D: printf("%-7.2X\n", *code); break;
        case 0x9E: printf("%-7.2X\n", *code); break;
        case 0x9F: printf("%-7.2X\n", *code); break;
        case 0xA0: printf("%-7.2X\n", *code); break;
        case 0xA1: printf("%-7.2X\n", *code); break;
        case 0xA2: printf("%-7.2X\n", *code); break;
        case 0xA3: printf("%-7.2X\n", *code); break;
        case 0xA4: printf("%-7.2X\n", *code); break;
        case 0xA5: printf("%-7.2X\n", *code); break;
        case 0xA6: printf("%-7.2X\n", *code); break;
        case 0xA7: printf("%-7.2X\n", *code); break;
        case 0xA8: printf("%-7.2X\n", *code); break;
        case 0xA9: printf("%-7.2X\n", *code); break;
        case 0xAA: printf("%-7.2X\n", *code); break;
        case 0xAB: printf("%-7.2X\n", *code); break;
        case 0xAC: printf("%-7.2X\n", *code); break;
        case 0xAD: printf("%-7.2X\n", *code); break;
        case 0xAE: printf("%-7.2X\n", *code); break;
        case 0xAF: printf("%-7.2X\n", *code); break;
        case 0xB0: printf("%-7.2X\n", *code); break;
        case 0xB1: printf("%-7.2X\n", *code); break;
        case 0xB2: printf("%-7.2X\n", *code); break;
        case 0xB3: printf("%-7.2X\n", *code); break;
        case 0xB4: printf("%-7.2X\n", *code); break;
        case 0xB5: printf("%-7.2X\n", *code); break;
        case 0xB6: printf("%-7.2X\n", *code); break;
        case 0xB7: printf("%-7.2X\n", *code); break;
        case 0xB8: printf("%-7.2X\n", *code); break;
        case 0xB9: printf("%-7.2X\n", *code); break;
        case 0xBA: printf("%-7.2X\n", *code); break;
        case 0xBB: printf("%-7.2X\n", *code); break;
        case 0xBC: printf("%-7.2X\n", *code); break;
        case 0xBD: printf("%-7.2X\n", *code); break;
        case 0xBE: printf("%-7.2X\n", *code); break;
        case 0xBF: printf("%-7.2X\n", *code); break;
        case 0xC0: printf("%-7.2X\n", *code); break;
        case 0xC1: printf("%-7.2X\n", *code); break;
        case 0xC2: printf("%.2X %.2X %.2X JNZ $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xC3: printf("%.2X %.2X %.2X JMP $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO 
        case 0xC4: printf("%.2X %.2X %.2X CNZ $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xC5: printf("%-7.2X\n", *code); break;
        case 0xC6: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0xC7: printf("%-7.2X\n", *code); break;
        case 0xC8: printf("%-7.2X\n", *code); break;
        case 0xC9: printf("%-7.2X\n", *code); break;
        case 0xCA: printf("%.2X %.2X %.2X JZ $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xCC: printf("%.2X %.2X %.2X CZ $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xCD: printf("%.2X %.2X %.2X CALL $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xCE: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0xCF: printf("%-7.2X\n", *code); break;
        case 0xD0: printf("%-7.2X\n", *code); break;
        case 0xD1: printf("%-7.2X\n", *code); break;
        case 0xD2: printf("%.2X %.2X %.2X JNC $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xD3: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0xD4: printf("%.2X %.2X %.2X CNC $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xD5: printf("%-7.2X\n", *code); break;
        case 0xD6: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0xD7: printf("%-7.2X\n", *code); break;
        case 0xD8: printf("%-7.2X\n", *code); break;
        case 0xDA: printf("%.2X %.2X %.2X JC $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xDB: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0xDC: printf("%.2X %.2X %.2X CC $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xDE: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0xDF: printf("%-7.2X\n", *code); break;
        case 0xE0: printf("%-7.2X\n", *code); break;
        case 0xE1: printf("%-7.2X\n", *code); break;
        case 0xE2: printf("%.2X %.2X %.2X JPO $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xE3: printf("%-7.2X\n", *code); break;
        case 0xE4: printf("%.2X %.2X %.2X CPO $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xE5: printf("%-7.2X\n", *code); break;
        case 0xE6: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0xE7: printf("%-7.2X\n", *code); break;
        case 0xE8: printf("%-7.2X\n", *code); break;
        case 0xE9: printf("%-7.2X\n", *code); break;
        case 0xEA: printf("%.2X %.2X %.2X JPE $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xEB: printf("%-7.2X\n", *code); break;
        case 0xEC: printf("%.2X %.2X %.2X CPE $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xEE: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0xEF: printf("%-7.2X\n", *code); break;
        case 0xF0: printf("%-7.2X\n", *code); break;
        case 0xF1: printf("%-7.2X\n", *code); break;
        case 0xF2: printf("%.2X %.2X %.2X JP $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xF3: printf("%-7.2X\n", *code); break;
        case 0xF4: printf("%.2X %.2X %.2X CP $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xF5: printf("%-7.2X\n", *code); break;
        case 0xF6: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0xF7: printf("%-7.2X\n", *code); break;
        case 0xF8: printf("%-7.2X\n", *code); break;
        case 0xF9: printf("%-7.2X\n", *code); break;
        case 0xFA: printf("%.2X %.2X %.2X JM $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xFB: printf("%-7.2X\n", *code); break;
        case 0xFC: printf("%.2X %.2X %.2X CM $%.2X%.2X\n", code[0], code[1], code[2], code[2], code[1]); opbytes = 3; break; // TODO
        case 0xFE: printf("%-7.2X\n", *code); opbytes = 2; break;
        case 0xFF: printf("%-7.2X\n", *code); break;
    }
    fflush(stdout);
    return opbytes;
}
