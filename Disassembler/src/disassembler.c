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
 * - Check differences between test case and implementation
 */
int disassemble8080Op(unsigned char *codebuffer, int pc) {
    unsigned char *code = &codebuffer[pc];
    int opbytes = 1;
    switch (*code) {
        case 0x00: printf("%04x %-8.2X NOP\n", pc, *code);  break;
        case 0x01: printf("0x01\n"); opbytes = 3; break;
        case 0x02: printf("0x02\n"); break;
        case 0x03: printf("0x03\n"); break;
        case 0x04: printf("0x04\n"); break;
        case 0x05: printf("0x05\n"); break;
        case 0x06: printf("0x06\n"); opbytes = 2; break;
        case 0x07: printf("0x07\n"); break;
        case 0x09: printf("0x09\n"); break;
        case 0x0A: printf("0x0A\n"); break;
        case 0x0B: printf("0x0B\n"); break;
        case 0x0C: printf("0x0C\n"); break;
        case 0x0D: printf("0x0D\n"); break;
        case 0x0E: printf("0x0E\n"); opbytes = 3; break;
        case 0x0F: printf("0x0F\n"); break;
        case 0x11: printf("0x11\n"); opbytes = 3; break;
        case 0x12: printf("0x12\n"); break;
        case 0x13: printf("0x13\n"); break;
        case 0x14: printf("0x14\n"); break;
        case 0x15: printf("0x15\n"); break;
        case 0x16: printf("0x16\n"); opbytes = 2; break;
        case 0x17: printf("0x17\n"); break;
        case 0x19: printf("0x19\n"); break;
        case 0x1A: printf("0x1A\n"); break;
        case 0x1B: printf("0x1B\n"); break;
        case 0x1C: printf("0x1C\n"); break;
        case 0x1D: printf("0x1D\n"); break;
        case 0x1E: printf("0x1E\n"); opbytes = 2; break;
        case 0x1F: printf("0x1F\n"); break;
        case 0x21: printf("0x21\n"); opbytes = 3; break;
        case 0x22: printf("0x22\n"); opbytes = 3; break;
        case 0x23: printf("0x23\n"); break;
        case 0x24: printf("0x24\n"); break;
        case 0x25: printf("0x25\n"); break;
        case 0x26: printf("0x26\n"); opbytes = 2; break;
        case 0x27: printf("0x27\n"); break;
        case 0x29: printf("0x29\n"); break;
        case 0x2A: printf("0x2A\n"); opbytes = 3; break;
        case 0x2B: printf("0x2B\n"); break;
        case 0x2C: printf("0x2C\n"); break;
        case 0x2D: printf("0x2D\n"); break;
        case 0x2E: printf("0x2E\n"); opbytes = 2; break;
        case 0x2F: printf("0x2F\n"); break;
        case 0x31: printf("0x31\n"); opbytes = 3; break;
        case 0x32: printf("0x32\n"); opbytes = 3; break;
        case 0x33: printf("0x33\n"); break;
        case 0x34: printf("0x34\n"); break;
        case 0x35: printf("0x35\n"); break;
        case 0x36: printf("0x36\n"); opbytes = 2; break;
        case 0x37: printf("0x37\n"); break;
        case 0x39: printf("0x39\n"); break;
        case 0x3A: printf("0x3A\n"); opbytes = 3; break;
        case 0x3B: printf("0x3B\n"); break;
        case 0x3C: printf("0x3C\n"); break;
        case 0x3D: printf("0x3D\n"); break;
        case 0x3E: printf("0x3E\n"); opbytes = 2; break;
        case 0x3F: printf("0x3F\n"); break;
        case 0x40: printf("0x40\n"); break;
        case 0x41: printf("0x41\n"); break;
        case 0x42: printf("0x42\n"); break;
        case 0x43: printf("0x43\n"); break;
        case 0x44: printf("0x44\n"); break;
        case 0x45: printf("0x45\n"); break;
        case 0x46: printf("0x46\n"); break;
        case 0x47: printf("0x47\n"); break;
        case 0x48: printf("0x48\n"); break;
        case 0x49: printf("0x49\n"); break;
        case 0x4A: printf("0x4A\n"); break;
        case 0x4B: printf("0x4B\n"); break;
        case 0x4C: printf("0x4C\n"); break;
        case 0x4D: printf("0x4D\n"); break;
        case 0x4E: printf("0x4E\n"); break;
        case 0x4F: printf("0x4F\n"); break;
        case 0x50: printf("0x50\n"); break;
        case 0x51: printf("0x51\n"); break;
        case 0x52: printf("0x52\n"); break;
        case 0x53: printf("0x53\n"); break;
        case 0x54: printf("0x54\n"); break;
        case 0x55: printf("0x55\n"); break;
        case 0x56: printf("0x56\n"); break;
        case 0x57: printf("0x57\n"); break;
        case 0x58: printf("0x58\n"); break;
        case 0x59: printf("0x59\n"); break;
        case 0x5A: printf("0x5A\n"); break;
        case 0x5B: printf("0x5B\n"); break;
        case 0x5C: printf("0x5C\n"); break;
        case 0x5D: printf("0x5D\n"); break;
        case 0x5E: printf("0x5E\n"); break;
        case 0x5F: printf("0x5F\n"); break;
        case 0x60: printf("0x60\n"); break;
        case 0x61: printf("0x61\n"); break;
        case 0x62: printf("0x62\n"); break;
        case 0x63: printf("0x63\n"); break;
        case 0x64: printf("0x64\n"); break;
        case 0x65: printf("0x65\n"); break;
        case 0x66: printf("0x66\n"); break;
        case 0x67: printf("0x67\n"); break;
        case 0x68: printf("0x68\n"); break;
        case 0x69: printf("0x69\n"); break;
        case 0x6A: printf("0x6A\n"); break;
        case 0x6B: printf("0x6B\n"); break;
        case 0x6C: printf("0x6C\n"); break;
        case 0x6D: printf("0x6D\n"); break;
        case 0x6E: printf("0x6E\n"); break;
        case 0x6F: printf("0x6F\n"); break;
        case 0x70: printf("0x70\n"); break;
        case 0x71: printf("0x71\n"); break;
        case 0x72: printf("0x72\n"); break;
        case 0x73: printf("0x73\n"); break;
        case 0x74: printf("0x74\n"); break;
        case 0x75: printf("0x75\n"); break;
        case 0x76: printf("0x76\n"); break;
        case 0x77: printf("0x77\n"); break;
        case 0x78: printf("0x78\n"); break;
        case 0x79: printf("0x79\n"); break;
        case 0x7A: printf("0x7A\n"); break;
        case 0x7B: printf("0x7B\n"); break;
        case 0x7C: printf("0x7C\n"); break;
        case 0x7D: printf("0x7D\n"); break;
        case 0x7E: printf("0x7E\n"); break;
        case 0x7F: printf("0x7F\n"); break;
        case 0x80: printf("0x80\n"); break;
        case 0x81: printf("0x81\n"); break;
        case 0x82: printf("0x82\n"); break;
        case 0x83: printf("0x83\n"); break;
        case 0x84: printf("0x84\n"); break;
        case 0x85: printf("0x85\n"); break;
        case 0x86: printf("0x86\n"); break;
        case 0x87: printf("0x87\n"); break;
        case 0x88: printf("0x88\n"); break;
        case 0x89: printf("0x89\n"); break;
        case 0x8A: printf("0x8A\n"); break;
        case 0x8B: printf("0x8B\n"); break;
        case 0x8C: printf("0x8C\n"); break;
        case 0x8D: printf("0x8D\n"); break;
        case 0x8E: printf("0x8E\n"); break;
        case 0x8F: printf("0x8F\n"); break;
        case 0x90: printf("0x90\n"); break;
        case 0x91: printf("0x91\n"); break;
        case 0x92: printf("0x92\n"); break;
        case 0x93: printf("0x93\n"); break;
        case 0x94: printf("0x94\n"); break;
        case 0x95: printf("0x95\n"); break;
        case 0x96: printf("0x96\n"); break;
        case 0x97: printf("0x97\n"); break;
        case 0x98: printf("0x98\n"); break;
        case 0x99: printf("0x99\n"); break;
        case 0x9A: printf("0x9A\n"); break;
        case 0x9B: printf("0x9B\n"); break;
        case 0x9C: printf("0x9C\n"); break;
        case 0x9D: printf("0x9D\n"); break;
        case 0x9E: printf("0x9E\n"); break;
        case 0x9F: printf("0x9F\n"); break;
        case 0xA0: printf("0xA0\n"); break;
        case 0xA1: printf("0xA1\n"); break;
        case 0xA2: printf("0xA2\n"); break;
        case 0xA3: printf("0xA3\n"); break;
        case 0xA4: printf("0xA4\n"); break;
        case 0xA5: printf("0xA5\n"); break;
        case 0xA6: printf("0xA6\n"); break;
        case 0xA7: printf("0xA7\n"); break;
        case 0xA8: printf("0xA8\n"); break;
        case 0xA9: printf("0xA9\n"); break;
        case 0xAA: printf("0xAA\n"); break;
        case 0xAB: printf("0xAB\n"); break;
        case 0xAC: printf("0xAC\n"); break;
        case 0xAD: printf("0xAD\n"); break;
        case 0xAE: printf("0xAE\n"); break;
        case 0xAF: printf("0xAF\n"); break;
        case 0xB0: printf("0xB0\n"); break;
        case 0xB1: printf("0xB1\n"); break;
        case 0xB2: printf("0xB2\n"); break;
        case 0xB3: printf("0xB3\n"); break;
        case 0xB4: printf("0xB4\n"); break;
        case 0xB5: printf("0xB5\n"); break;
        case 0xB6: printf("0xB6\n"); break;
        case 0xB7: printf("0xB7\n"); break;
        case 0xB8: printf("0xB8\n"); break;
        case 0xB9: printf("0xB9\n"); break;
        case 0xBA: printf("0xBA\n"); break;
        case 0xBB: printf("0xBB\n"); break;
        case 0xBC: printf("0xBC\n"); break;
        case 0xBD: printf("0xBD\n"); break;
        case 0xBE: printf("0xBE\n"); break;
        case 0xBF: printf("0xBF\n"); break;
        case 0xC0: printf("0xC0\n"); break;
        case 0xC1: printf("0xC1\n"); break;
        case 0xC2: printf("0xC2\n"); opbytes = 3; break;
        case 0xC3: printf("0xC3\n"); opbytes = 3; break;
        case 0xC4: printf("0xC4\n"); opbytes = 3; break;
        case 0xC5: printf("0xC5\n"); break;
        case 0xC6: printf("0xC6\n"); opbytes = 2; break;
        case 0xC7: printf("0xC7\n"); break;
        case 0xC8: printf("0xC8\n"); break;
        case 0xC9: printf("0xC9\n"); break;
        case 0xCA: printf("0xCA\n"); opbytes = 3; break;
        case 0xCC: printf("0xCC\n"); opbytes = 3; break;
        case 0xCD: printf("0xCD\n"); opbytes = 3; break;
        case 0xCE: printf("0xCE\n"); opbytes = 2; break;
        case 0xCF: printf("0xCF\n"); break;
        case 0xD0: printf("0xD0\n"); break;
        case 0xD1: printf("0xD1\n"); break;
        case 0xD2: printf("0xD2\n"); opbytes = 3; break;
        case 0xD3: printf("0xD3\n"); opbytes = 2; break;
        case 0xD4: printf("0xD4\n"); opbytes = 3; break;
        case 0xD5: printf("0xD5\n"); break;
        case 0xD6: printf("0xD6\n"); opbytes = 2; break;
        case 0xD7: printf("0xD7\n"); break;
        case 0xD8: printf("0xD8\n"); break;
        case 0xDA: printf("0xDA\n"); opbytes = 3; break;
        case 0xDB: printf("0xDB\n"); opbytes = 2; break;
        case 0xDC: printf("0xDC\n"); opbytes = 3; break;
        case 0xDE: printf("0xDE\n"); opbytes = 2; break;
        case 0xDF: printf("0xDF\n"); break;
        case 0xE0: printf("0xE0\n"); break;
        case 0xE1: printf("0xE1\n"); break;
        case 0xE2: printf("0xE2\n"); opbytes = 3; break;
        case 0xE3: printf("0xE3\n"); break;
        case 0xE4: printf("0xE4\n"); opbytes = 3; break;
        case 0xE5: printf("0xE5\n"); break;
        case 0xE6: printf("0xE6\n"); opbytes = 2; break;
        case 0xE7: printf("0xE7\n"); break;
        case 0xE8: printf("0xE8\n"); break;
        case 0xE9: printf("0xE9\n"); break;
        case 0xEA: printf("0xEA\n"); opbytes = 3; break;
        case 0xEB: printf("0xEB\n"); break;
        case 0xEC: printf("0xEC\n"); opbytes = 3; break;
        case 0xEE: printf("0xEE\n"); opbytes = 2; break;
        case 0xEF: printf("0xEF\n"); break;
        case 0xF0: printf("0xF0\n"); break;
        case 0xF1: printf("0xF1\n"); break;
        case 0xF2: printf("0xF2\n"); opbytes = 3; break;
        case 0xF3: printf("0xF3\n"); break;
        case 0xF4: printf("0xF4\n"); opbytes = 3; break;
        case 0xF5: printf("0xF5\n"); break;
        case 0xF6: printf("0xF6\n"); opbytes = 2; break;
        case 0xF7: printf("0xF7\n"); break;
        case 0xF8: printf("0xF8\n"); break;
        case 0xF9: printf("0xF9\n"); break;
        case 0xFA: printf("0xFA\n"); opbytes = 3; break;
        case 0xFB: printf("0xFB\n"); break;
        case 0xFC: printf("0xFC\n"); opbytes = 3; break;
        case 0xFE: printf("0xFE\n"); opbytes = 2; break;
        case 0xFF: printf("0xFF\n"); break;
    }
    fflush(stdout);
    return opbytes;
}
