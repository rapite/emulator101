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
 *
 * STEPS:
 * - Implement all Opcodes from 0x00 to 0xff
 * - Assert opcode sizes
 */
int disassemble8080Op(unsigned char *codebuffer, int pc) {
    unsigned char *code = &codebuffer[pc];
    int opbytes = 1;
    printf ("%04x ", pc);
    switch (*code) {
        case 0x00: printf("NOP"); break;
        case 0x01: printf("0x01"); opbytes = 3; break;
        case 0x02: printf("0x02"); break;
        case 0x03: printf("0x03"); break;
        case 0x04: printf("0x04"); break;
        case 0x05: printf("0x05"); break;
        case 0x06: printf("0x06"); opbytes = 2; break;
        case 0x07: printf("0x07"); break;
        case 0x09: printf("0x09"); break;
        case 0x0A: printf("0x0A"); break;
        case 0x0B: printf("0x0B"); break;
        case 0x0C: printf("0x0C"); break;
        case 0x0D: printf("0x0D"); break;
        case 0x0E: printf("0x0E"); opbytes = 3; break;
        case 0x0F: printf("0x0F"); break;
        case 0x11: printf("0x11"); opbytes = 3; break;
        case 0x12: printf("0x12"); break;
        case 0x13: printf("0x13"); break;
        case 0x14: printf("0x14"); break;
        case 0x15: printf("0x15"); break;
        case 0x16: printf("0x16"); opbytes = 2; break;
        case 0x17: printf("0x17"); break;
        case 0x19: printf("0x19"); break;
        case 0x1A: printf("0x1A"); break;
        case 0x1B: printf("0x1B"); break;
        case 0x1C: printf("0x1C"); break;
        case 0x1D: printf("0x1D"); break;
        case 0x1E: printf("0x1E"); opbytes = 2; break;
        case 0x1F: printf("0x1F"); break;
        case 0x21: printf("0x21"); opbytes = 3; break;
        case 0x22: printf("0x22"); opbytes = 3; break;
        case 0x23: printf("0x23"); break;
        case 0x24: printf("0x24"); break;
        case 0x25: printf("0x25"); break;
        case 0x26: printf("0x26"); opbytes = 2; break;
        case 0x27: printf("0x27"); break;
        case 0x29: printf("0x29"); break;
        case 0x2A: printf("0x2A"); opbytes = 3; break;
        case 0x2B: printf("0x2B"); break;
        case 0x2C: printf("0x2C"); break;
        case 0x2D: printf("0x2D"); break;
        case 0x2E: printf("0x2E"); opbytes = 2; break;
        case 0x2F: printf("0x2F"); break;
        case 0x31: printf("0x31"); opbytes = 3; break;
        case 0x32: printf("0x32"); opbytes = 3; break;
        case 0x33: printf("0x33"); break;
        case 0x34: printf("0x34"); break;
        case 0x35: printf("0x35"); break;
        case 0x36: printf("0x36"); opbytes = 2; break;
        case 0x37: printf("0x37"); break;
        case 0x39: printf("0x39"); break;
        case 0x3A: printf("0x3A"); opbytes = 3; break;
        case 0x3B: printf("0x3B"); break;
        case 0x3C: printf("0x3C"); break;
        case 0x3D: printf("0x3D"); break;
        case 0x3E: printf("0x3E"); opbytes = 2; break;
        case 0x3F: printf("0x3F"); break;
        case 0x40: printf("0x40"); break;
        case 0x41: printf("0x41"); break;
        case 0x42: printf("0x42"); break;
        case 0x43: printf("0x43"); break;
        case 0x44: printf("0x44"); break;
        case 0x45: printf("0x45"); break;
        case 0x46: printf("0x46"); break;
        case 0x47: printf("0x47"); break;
        case 0x48: printf("0x48"); break;
        case 0x49: printf("0x49"); break;
        case 0x4A: printf("0x4A"); break;
        case 0x4B: printf("0x4B"); break;
        case 0x4C: printf("0x4C"); break;
        case 0x4D: printf("0x4D"); break;
        case 0x4E: printf("0x4E"); break;
        case 0x4F: printf("0x4F"); break;
        case 0x50: printf("0x50"); break;
        case 0x51: printf("0x51"); break;
        case 0x52: printf("0x52"); break;
        case 0x53: printf("0x53"); break;
        case 0x54: printf("0x54"); break;
        case 0x55: printf("0x55"); break;
        case 0x56: printf("0x56"); break;
        case 0x57: printf("0x57"); break;
        case 0x58: printf("0x58"); break;
        case 0x59: printf("0x59"); break;
        case 0x5A: printf("0x5A"); break;
        case 0x5B: printf("0x5B"); break;
        case 0x5C: printf("0x5C"); break;
        case 0x5D: printf("0x5D"); break;
        case 0x5E: printf("0x5E"); break;
        case 0x5F: printf("0x5F"); break;
        case 0x60: printf("0x60"); break;
        case 0x61: printf("0x61"); break;
        case 0x62: printf("0x62"); break;
        case 0x63: printf("0x63"); break;
        case 0x64: printf("0x64"); break;
        case 0x65: printf("0x65"); break;
        case 0x66: printf("0x66"); break;
        case 0x67: printf("0x67"); break;
        case 0x68: printf("0x68"); break;
        case 0x69: printf("0x69"); break;
        case 0x6A: printf("0x6A"); break;
        case 0x6B: printf("0x6B"); break;
        case 0x6C: printf("0x6C"); break;
        case 0x6D: printf("0x6D"); break;
        case 0x6E: printf("0x6E"); break;
        case 0x6F: printf("0x6F"); break;
        case 0x70: printf("0x70"); break;
        case 0x71: printf("0x71"); break;
        case 0x72: printf("0x72"); break;
        case 0x73: printf("0x73"); break;
        case 0x74: printf("0x74"); break;
        case 0x75: printf("0x75"); break;
        case 0x76: printf("0x76"); break;
        case 0x77: printf("0x77"); break;
        case 0x78: printf("0x78"); break;
        case 0x79: printf("0x79"); break;
        case 0x7A: printf("0x7A"); break;
        case 0x7B: printf("0x7B"); break;
        case 0x7C: printf("0x7C"); break;
        case 0x7D: printf("0x7D"); break;
        case 0x7E: printf("0x7E"); break;
        case 0x7F: printf("0x7F"); break;
        case 0x80: printf("0x80"); break;
        case 0x81: printf("0x81"); break;
        case 0x82: printf("0x82"); break;
        case 0x83: printf("0x83"); break;
        case 0x84: printf("0x84"); break;
        case 0x85: printf("0x85"); break;
        case 0x86: printf("0x86"); break;
        case 0x87: printf("0x87"); break;
        case 0x88: printf("0x88"); break;
        case 0x89: printf("0x89"); break;
        case 0x8A: printf("0x8A"); break;
        case 0x8B: printf("0x8B"); break;
        case 0x8C: printf("0x8C"); break;
        case 0x8D: printf("0x8D"); break;
        case 0x8E: printf("0x8E"); break;
        case 0x8F: printf("0x8F"); break;
        case 0x90: printf("0x90"); break;
        case 0x91: printf("0x91"); break;
        case 0x92: printf("0x92"); break;
        case 0x93: printf("0x93"); break;
        case 0x94: printf("0x94"); break;
        case 0x95: printf("0x95"); break;
        case 0x96: printf("0x96"); break;
        case 0x97: printf("0x97"); break;
        case 0x98: printf("0x98"); break;
        case 0x99: printf("0x99"); break;
        case 0x9A: printf("0x9A"); break;
        case 0x9B: printf("0x9B"); break;
        case 0x9C: printf("0x9C"); break;
        case 0x9D: printf("0x9D"); break;
        case 0x9E: printf("0x9E"); break;
        case 0x9F: printf("0x9F"); break;
        case 0xA0: printf("0xA0"); break;
        case 0xA1: printf("0xA1"); break;
        case 0xA2: printf("0xA2"); break;
        case 0xA3: printf("0xA3"); break;
        case 0xA4: printf("0xA4"); break;
        case 0xA5: printf("0xA5"); break;
        case 0xA6: printf("0xA6"); break;
        case 0xA7: printf("0xA7"); break;
        case 0xA8: printf("0xA8"); break;
        case 0xA9: printf("0xA9"); break;
        case 0xAA: printf("0xAA"); break;
        case 0xAB: printf("0xAB"); break;
        case 0xAC: printf("0xAC"); break;
        case 0xAD: printf("0xAD"); break;
        case 0xAE: printf("0xAE"); break;
        case 0xAF: printf("0xAF"); break;
        case 0xB0: printf("0xB0"); break;
        case 0xB1: printf("0xB1"); break;
        case 0xB2: printf("0xB2"); break;
        case 0xB3: printf("0xB3"); break;
        case 0xB4: printf("0xB4"); break;
        case 0xB5: printf("0xB5"); break;
        case 0xB6: printf("0xB6"); break;
        case 0xB7: printf("0xB7"); break;
        case 0xB8: printf("0xB8"); break;
        case 0xB9: printf("0xB9"); break;
        case 0xBA: printf("0xBA"); break;
        case 0xBB: printf("0xBB"); break;
        case 0xBC: printf("0xBC"); break;
        case 0xBD: printf("0xBD"); break;
        case 0xBE: printf("0xBE"); break;
        case 0xBF: printf("0xBF"); break;
        case 0xC0: printf("0xC0"); break;
        case 0xC1: printf("0xC1"); break;
        case 0xC2: printf("0xC2"); opbytes = 3; break;
        case 0xC3: printf("0xC3"); opbytes = 3; break;
        case 0xC4: printf("0xC4"); opbytes = 3; break;
        case 0xC5: printf("0xC5"); break;
        case 0xC6: printf("0xC6"); opbytes = 2; break;
        case 0xC7: printf("0xC7"); break;
        case 0xC8: printf("0xC8"); break;
        case 0xC9: printf("0xC9"); break;
        case 0xCA: printf("0xCA"); opbytes = 3; break;
        case 0xCC: printf("0xCC"); opbytes = 3; break;
        case 0xCD: printf("0xCD"); opbytes = 3; break;
        case 0xCE: printf("0xCE"); opbytes = 2; break;
        case 0xCF: printf("0xCF"); break;
        case 0xD0: printf("0xD0"); break;
        case 0xD1: printf("0xD1"); break;
        case 0xD2: printf("0xD2"); opbytes = 3; break;
        case 0xD3: printf("0xD3"); opbytes = 2; break;
        case 0xD4: printf("0xD4"); opbytes = 3; break;
        case 0xD5: printf("0xD5"); break;
        case 0xD6: printf("0xD6"); opbytes = 2; break;
        case 0xD7: printf("0xD7"); break;
        case 0xD8: printf("0xD8"); break;
        case 0xDA: printf("0xDA"); opbytes = 3; break;
        case 0xDB: printf("0xDB"); opbytes = 2; break;
        case 0xDC: printf("0xDC"); opbytes = 3; break;
        case 0xDE: printf("0xDE"); opbytes = 2; break;
        case 0xDF: printf("0xDF"); break;
        case 0xE0: printf("0xE0"); break;
        case 0xE1: printf("0xE1"); break;
        case 0xE2: printf("0xE2"); opbytes = 3; break;
        case 0xE3: printf("0xE3"); break;
        case 0xE4: printf("0xE4"); opbytes = 3; break;
        case 0xE5: printf("0xE5"); break;
        case 0xE6: printf("0xE6"); opbytes = 2; break;
        case 0xE7: printf("0xE7"); break;
        case 0xE8: printf("0xE8"); break;
        case 0xE9: printf("0xE9"); break;
        case 0xEA: printf("0xEA"); opbytes = 3; break;
        case 0xEB: printf("0xEB"); break;
        case 0xEC: printf("0xEC"); opbytes = 3; break;
        case 0xEE: printf("0xEE"); opbytes = 2; break;
        case 0xEF: printf("0xEF"); break;
        case 0xF0: printf("0xF0"); break;
        case 0xF1: printf("0xF1"); break;
        case 0xF2: printf("0xF2"); opbytes = 3; break;
        case 0xF3: printf("0xF3"); break;
        case 0xF4: printf("0xF4"); opbytes = 3; break;
        case 0xF5: printf("0xF5"); break;
        case 0xF6: printf("0xF6"); opbytes = 2; break;
        case 0xF7: printf("0xF7"); break;
        case 0xF8: printf("0xF8"); break;
        case 0xF9: printf("0xF9"); break;
        case 0xFA: printf("0xFA"); opbytes = 3; break;
        case 0xFB: printf("0xFB"); break;
        case 0xFC: printf("0xFC"); opbytes = 3; break;
        case 0xFE: printf("0xFE"); opbytes = 2; break;
        case 0xFF: printf("0xFF"); break;
    }
    return opbytes;
}
