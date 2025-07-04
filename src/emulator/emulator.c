#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "../../include/emulator.h"

void UnimplementedInstruction(State8080* state) {
     //pc will have advanced one, so undo that
    state->pc-=1;
    printf ("Error: Unimplemented instruction\n");    
    exit(1);    
}

void printStateData(State8080* s) {
    // print struct members
    printf("a: %" PRIu8 "\n", s->a);
    printf("b: %" PRIu8 "\n", s->b);
    printf("c: %" PRIu8 "\n", s->c);
    printf("d: %" PRIu8 "\n", s->d);
    printf("e: %" PRIu8 "\n", s->e);
    printf("h: %" PRIu8 "\n", s->h);
    printf("l: %" PRIu8 "\n", s->l);
    printf("sp: %" PRIu16 "\n", s->sp);
    printf("pc: %" PRIu16 "\n\n", s->pc);

    // observe members of cc
    printf("s.cc->z: %" PRIu8 "\n", s->cc.z);
    printf("s.cc->s: %" PRIu8 "\n", s->cc.s);
    printf("s.cc->p: %" PRIu8 "\n", s->cc.p);
    printf("s.cc->cy: %" PRIu8 "\n", s->cc.cy);
    printf("s.cc->ac: %" PRIu8 "\n", s->cc.ac);
    printf("s.cc->pad: %" PRIu8 "\n", s->cc.pad);
}

/**
 * TODO: implement size 3 opcode
 * - 0x01 0x11 0x21 0x22 0x2A 0x31 0x32
 * - 0x3a 0xc2 0xc3 0xc4 0xca 0xcc 0xcd
 * - 0xd2 0xd4 0xda 0xdc 0xe2 0xe4 0xea
 * - 0xec 0xf2 0xf4 0xfa 0xfc
 * 
 * TODO: Implement Arithmetic group
 * - Unless indicated otherwise, all instructions affect zero, sign, parity, carry and auxiliary Carry flags
 *
 * TODO: Implement Branch group
 * TODO: Implement Logical group
 * TODO: Implement IO and Special group
 * TODO: Implement Stack group
 * 
 * - In the carry variants (ADC, ACI, SBB, SUI) you use the carry bit in the calculation as indicated in the data book.
 * - INX and DCX effect register pairs, these instructions do not effect the flags.
 * - DAD is another register pair instruction, it only effects the carry flag
 * - INR and DCR do not effect the carry flag
 * 
 * TODO: 50k list of instructions
 */
int Emulate8080Op(State8080* state) {    
    unsigned char *opcode = &state->memory[state->pc];
    int opbytes = 1;
    switch(*opcode)
    {
        case 0x00: break; // NOP 
        case 0x01: { // LXI B, word 	B <- byte 3, C <- byte 2
            state->c = opcode[1];
            state->b = opcode[2];
            opbytes = 3;
            break;
        }
        case 0x02: UnimplementedInstruction(state); break;
        case 0x03: UnimplementedInstruction(state); break;
        case 0x04: UnimplementedInstruction(state); break;
        case 0x05: { // DCR B
            uint16_t result = (uint16_t) state->b - 1;
            state->cc.z = (result == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.p = Parity(result & 0xFF);
            state->b = result & 0xff;
            break;
        } 
        case 0x06: { // MVI B, D8
            state->b = opcode[1];
            opbytes = 2;
            break;
        } 
        case 0x07: UnimplementedInstruction(state); break;
        case 0x08: UnimplementedInstruction(state); break;
        case 0x09: { // DAD B
            uint32_t hl = ((uint32_t) state->h << 8) | state->l;
            uint16_t bc = ((uint16_t) state->b << 8) | state->c;
            
            uint32_t result = hl + bc;
            state->h = (result >> 8) & 0xFF;
            state->l = result & 0xFF;

            state->cc.cy = (result > 0xFFFF);
            break;
        } 
        case 0x0A: UnimplementedInstruction(state); break;
        case 0x0B: UnimplementedInstruction(state); break;
        case 0x0C: UnimplementedInstruction(state); break;
        case 0x0D: { // DCR C
            uint16_t result = (uint16_t) state->c - 1;
            state->cc.z = (result == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.p = Parity(result & 0xFF);
            state->c = result & 0xff;
            break;
        } 
        case 0x0E: { // MVI C, D8
            state->c = opcode[1];
            opbytes = 2;
            break;
        }
        case 0x0F: { // RRC
            uint8_t acc = state->a;
            state->cc.cy = (acc & 0x01);
            state->a = (acc >> 1) | (state->cc.cy << 7);
        } 
        case 0x10: UnimplementedInstruction(state); break;
        case 0x11: { // LXI D, D16
            state->e = opcode[1];
            state->d = opcode[2];
            opbytes = 3;
        }
        case 0x12: UnimplementedInstruction(state); break;
        case 0x13: { // INX D
            uint16_t de = (uint16_t) state->d << 8 | state->e;
            de += 1;
            state->d = (de >> 8) & 0xFF;
            state->e = (de & 0xFF); 
        } 
        case 0x14: UnimplementedInstruction(state); break;
        case 0x15: { // DCR D
            uint16_t result = (uint16_t) state->d - 1;
            state->cc.z = (result == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.p = Parity(result & 0xFF);
            state->d = result & 0xff;
            break;
        }
        case 0x16: { // MVI D, D8
            state->d = opcode[1];
            opbytes = 2;
            break;
        }
        case 0x17: UnimplementedInstruction(state); break;
        case 0x18: UnimplementedInstruction(state); break;
        case 0x19: { // DAD D
            uint32_t hl = ((uint32_t) state->h << 8) | state->l;
            uint16_t de = ((uint16_t) state->d << 8) | state->e;
            
            uint32_t result = hl + de;
            state->h = (result >> 8) & 0xFF;
            state->l = result & 0xFF;

            state->cc.cy = (result > 0xFFFF);
            break;
        } 
        case 0x1A: UnimplementedInstruction(state); break;
        case 0x1B: UnimplementedInstruction(state); break;
        case 0x1C: UnimplementedInstruction(state); break;
        case 0x1D: { // DCR E
            uint16_t result = (uint16_t) state->e - 1;
            state->cc.z = (result == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.p = Parity(result & 0xFF);
            state->e = result & 0xff;
            break;
        }
        case 0x1E: { // MVI E, D8
            state->e = opcode[1];
            opbytes = 2;
            break;
        } 
        case 0x1F: UnimplementedInstruction(state); break;
        case 0x20: UnimplementedInstruction(state); break;
        case 0x21: UnimplementedInstruction(state); break;
        case 0x22: UnimplementedInstruction(state); break;
        case 0x23: UnimplementedInstruction(state); break;
        case 0x24: UnimplementedInstruction(state); break;
        case 0x25: { // DCR h
            uint16_t result = (uint16_t) state->h - 1;
            state->cc.z = (result == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.p = Parity(result & 0xFF);
            state->h = result & 0xff;
            break;
        } 
        case 0x26: { // MVI H, D8
            state->h = opcode[1];
            opbytes = 2;
            break;
        }
        case 0x27: UnimplementedInstruction(state); break;
        case 0x28: UnimplementedInstruction(state); break;
        case 0x29: { // DAD H
            uint32_t hl = ((uint32_t) state->h << 8) | state->l;
            
            uint32_t result = hl + hl;
            state->h = (result >> 8) & 0xFF;
            state->l = result & 0xFF;

            state->cc.cy = (result > 0xFFFF);
            break;
        } 
        case 0x2A: UnimplementedInstruction(state); break;
        case 0x2B: UnimplementedInstruction(state); break;
        case 0x2C: UnimplementedInstruction(state); break;
        case 0x2D: { // DCR L
            uint16_t result = (uint16_t) state->l - 1;
            state->cc.z = (result == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.p = Parity(result & 0xFF);
            state->l = result & 0xff;
            break;
        }
        case 0x2E: { // MVI L, D8
            state->l = opcode[1];
            opbytes = 2;
            break;
        }
        case 0x2F: UnimplementedInstruction(state); break;
        case 0x30: UnimplementedInstruction(state); break;
        case 0x31: UnimplementedInstruction(state); break;
        case 0x32: UnimplementedInstruction(state); break;
        case 0x33: UnimplementedInstruction(state); break;
        case 0x34: UnimplementedInstruction(state); break;
        case 0x35: { // DCR M
            uint16_t offset = (state->h << 8) | state->l;
            uint8_t result = state->memory[offset] - 1;

            state->cc.z = ((result & 0xff) == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.p = Parity(result & 0xFF);
            state->memory[offset] = result;
            break;
        }
        case 0x36: { // MVI M, D8
            uint16_t offset = (state->h << 8) | state->l;
            state->memory[offset] = opcode[1];
            opbytes = 2;
            break;
        }
        case 0x37: UnimplementedInstruction(state); break;
        case 0x38: UnimplementedInstruction(state); break;
        case 0x39: { // DAD SP
            uint32_t hl = ((uint16_t)state->h << 8) | state->l;
            uint32_t sp = state->sp;

            uint32_t result = hl + sp;

            state->h = (result >> 8) & 0xFF;
            state->l = result & 0xFF;

            state->cc.cy = (result > 0xFFFF); 
            break;
        } 
        case 0x3A: UnimplementedInstruction(state); break;
        case 0x3B: UnimplementedInstruction(state); break;
        case 0x3C: UnimplementedInstruction(state); break;
        case 0x3D: { // DCR A
            uint16_t result = (uint16_t) state->a - 1;
            state->cc.z = (result == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.p = Parity(result & 0xFF);
            state->a = result & 0xff;
            break;
        } 
        case 0x3E: { // MVI A, D8
            state->a = opcode[1];
            opbytes = 2;
            break;
        }
        case 0x3F: UnimplementedInstruction(state); break;
        case 0x40: UnimplementedInstruction(state); break;
        case 0x41: UnimplementedInstruction(state); break;
        case 0x42: UnimplementedInstruction(state); break;
        case 0x43: UnimplementedInstruction(state); break;
        case 0x44: UnimplementedInstruction(state); break;
        case 0x45: UnimplementedInstruction(state); break;
        case 0x46: UnimplementedInstruction(state); break;
        case 0x47: UnimplementedInstruction(state); break;
        case 0x48: UnimplementedInstruction(state); break;
        case 0x49: UnimplementedInstruction(state); break;
        case 0x4A: UnimplementedInstruction(state); break;
        case 0x4B: UnimplementedInstruction(state); break;
        case 0x4C: UnimplementedInstruction(state); break;
        case 0x4D: UnimplementedInstruction(state); break;
        case 0x4E: UnimplementedInstruction(state); break;
        case 0x4F: UnimplementedInstruction(state); break;
        case 0x50: UnimplementedInstruction(state); break;
        case 0x51: UnimplementedInstruction(state); break;
        case 0x52: UnimplementedInstruction(state); break;
        case 0x53: UnimplementedInstruction(state); break;
        case 0x54: UnimplementedInstruction(state); break;
        case 0x55: UnimplementedInstruction(state); break;
        case 0x56: UnimplementedInstruction(state); break;
        case 0x57: UnimplementedInstruction(state); break;
        case 0x58: UnimplementedInstruction(state); break;
        case 0x59: UnimplementedInstruction(state); break;
        case 0x5A: UnimplementedInstruction(state); break;
        case 0x5B: UnimplementedInstruction(state); break;
        case 0x5C: UnimplementedInstruction(state); break;
        case 0x5D: UnimplementedInstruction(state); break;
        case 0x5E: UnimplementedInstruction(state); break;
        case 0x5F: UnimplementedInstruction(state); break;
        case 0x60: UnimplementedInstruction(state); break;
        case 0x61: UnimplementedInstruction(state); break;
        case 0x62: UnimplementedInstruction(state); break;
        case 0x63: UnimplementedInstruction(state); break;
        case 0x64: UnimplementedInstruction(state); break;
        case 0x65: UnimplementedInstruction(state); break;
        case 0x66: UnimplementedInstruction(state); break;
        case 0x67: UnimplementedInstruction(state); break;
        case 0x68: UnimplementedInstruction(state); break;
        case 0x69: UnimplementedInstruction(state); break;
        case 0x6A: UnimplementedInstruction(state); break;
        case 0x6B: UnimplementedInstruction(state); break;
        case 0x6C: UnimplementedInstruction(state); break;
        case 0x6D: UnimplementedInstruction(state); break;
        case 0x6E: UnimplementedInstruction(state); break;
        case 0x6F: UnimplementedInstruction(state); break;
        case 0x70: UnimplementedInstruction(state); break;
        case 0x71: UnimplementedInstruction(state); break;
        case 0x72: UnimplementedInstruction(state); break;
        case 0x73: UnimplementedInstruction(state); break;
        case 0x74: UnimplementedInstruction(state); break;
        case 0x75: UnimplementedInstruction(state); break;
        case 0x76: UnimplementedInstruction(state); break;
        case 0x77: UnimplementedInstruction(state); break;
        case 0x78: UnimplementedInstruction(state); break;
        case 0x79: UnimplementedInstruction(state); break;
        case 0x7A: UnimplementedInstruction(state); break;
        case 0x7B: UnimplementedInstruction(state); break;
        case 0x7C: UnimplementedInstruction(state); break;
        case 0x7D: UnimplementedInstruction(state); break;
        case 0x7E: UnimplementedInstruction(state); break;
        case 0x7F: UnimplementedInstruction(state); break;
        case 0x80: // ADD B
        {
            // do the math with higher precision so we can capture the    
            // carry out    
            uint16_t result = (uint16_t) state->a + (uint16_t) state->b;

            // Zero flag: if the result is zero,    
            // set the flag to zero    
            // else clear the flag    
            if ((result & 0xff) == 0)
                state->cc.z = 1;
            else    
                state->cc.z = 0;
            // Sign flag: if bit 7 is set,
            // set the sign flag
            // else clear the sign flag
            if (result & 0x80)
                state->cc.s = 1;
            else    
                state->cc.s = 0;

            // Carry flag    
            if (result > 0xff)    
                state->cc.cy = 1;
            else    
                state->cc.cy = 0;
            // Parity is handled by a subroutine    
            state->cc.p = Parity( result & 0xff);
            state->a = result & 0xff;
            break;
        } 
        case 0x81: { // ADD C
            uint16_t result = (uint16_t) state->a + (uint16_t) state->c;
            state->cc.z = ((result & 0xff) == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.cy = (result > 0xff);
            state->cc.p = Parity(result&0xff);
            state->a = result & 0xff;
            break;
        }   
        case 0x82: UnimplementedInstruction(state); break;
        case 0x83: UnimplementedInstruction(state); break;
        case 0x84: UnimplementedInstruction(state); break;
        case 0x85: UnimplementedInstruction(state); break;
        case 0x86: { // ADD M
            uint16_t offset = (state->h<<8) | (state->l);
            uint16_t result = (uint16_t) state->a + state->memory[offset];
            state->cc.z = ((result & 0xff) == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.cy = (result > 0xff);
            state->cc.p = Parity(result&0xff);
            state->a = result & 0xff;
        }
        case 0x87: UnimplementedInstruction(state); break;
        case 0x88: UnimplementedInstruction(state); break;
        case 0x89: UnimplementedInstruction(state); break;
        case 0x8A: UnimplementedInstruction(state); break;
        case 0x8B: UnimplementedInstruction(state); break;
        case 0x8C: UnimplementedInstruction(state); break;
        case 0x8D: UnimplementedInstruction(state); break;
        case 0x8E: UnimplementedInstruction(state); break;
        case 0x8F: UnimplementedInstruction(state); break;
        case 0x90: UnimplementedInstruction(state); break;
        case 0x91: UnimplementedInstruction(state); break;
        case 0x92: UnimplementedInstruction(state); break;
        case 0x93: UnimplementedInstruction(state); break;
        case 0x94: UnimplementedInstruction(state); break;
        case 0x95: UnimplementedInstruction(state); break;
        case 0x96: UnimplementedInstruction(state); break;
        case 0x97: UnimplementedInstruction(state); break;
        case 0x98: UnimplementedInstruction(state); break;
        case 0x99: UnimplementedInstruction(state); break;
        case 0x9A: UnimplementedInstruction(state); break;
        case 0x9B: UnimplementedInstruction(state); break;
        case 0x9C: UnimplementedInstruction(state); break;
        case 0x9D: UnimplementedInstruction(state); break;
        case 0x9E: UnimplementedInstruction(state); break;
        case 0x9F: UnimplementedInstruction(state); break;
        case 0xA0: UnimplementedInstruction(state); break;
        case 0xA1: UnimplementedInstruction(state); break;
        case 0xA2: UnimplementedInstruction(state); break;
        case 0xA3: UnimplementedInstruction(state); break;
        case 0xA4: UnimplementedInstruction(state); break;
        case 0xA5: UnimplementedInstruction(state); break;
        case 0xA6: UnimplementedInstruction(state); break;
        case 0xA7: UnimplementedInstruction(state); break;
        case 0xA8: UnimplementedInstruction(state); break;
        case 0xA9: UnimplementedInstruction(state); break;
        case 0xAA: UnimplementedInstruction(state); break;
        case 0xAB: UnimplementedInstruction(state); break;
        case 0xAC: UnimplementedInstruction(state); break;
        case 0xAD: UnimplementedInstruction(state); break;
        case 0xAE: UnimplementedInstruction(state); break;
        case 0xAF: UnimplementedInstruction(state); break;
        case 0xB0: UnimplementedInstruction(state); break;
        case 0xB1: UnimplementedInstruction(state); break;
        case 0xB2: UnimplementedInstruction(state); break;
        case 0xB3: UnimplementedInstruction(state); break;
        case 0xB4: UnimplementedInstruction(state); break;
        case 0xB5: UnimplementedInstruction(state); break;
        case 0xB6: UnimplementedInstruction(state); break;
        case 0xB7: UnimplementedInstruction(state); break;
        case 0xB8: UnimplementedInstruction(state); break;
        case 0xB9: UnimplementedInstruction(state); break;
        case 0xBA: UnimplementedInstruction(state); break;
        case 0xBB: UnimplementedInstruction(state); break;
        case 0xBC: UnimplementedInstruction(state); break;
        case 0xBD: UnimplementedInstruction(state); break;
        case 0xBE: UnimplementedInstruction(state); break;
        case 0xBF: UnimplementedInstruction(state); break;
        case 0xC0: UnimplementedInstruction(state); break;
        case 0xC1: UnimplementedInstruction(state); break;
        case 0xC2: UnimplementedInstruction(state); break;
        case 0xC3: UnimplementedInstruction(state); break;
        case 0xC4: UnimplementedInstruction(state); break;
        case 0xC5: UnimplementedInstruction(state); break;
        case 0xC6: {  //ADI byte
            uint16_t result = (uint16_t) state->a + (uint16_t) opcode[1];
            state->cc.z = ((result & 0xff) == 0);
            state->cc.s = ((result & 0x80) != 0);
            state->cc.cy = (result > 0xff);
            state->cc.p = Parity(result&0xff);
            state->a = result & 0xff;

            opbytes = 2;
            break;
        }
        case 0xC7: UnimplementedInstruction(state); break;
        case 0xC8: UnimplementedInstruction(state); break;
        case 0xC9: UnimplementedInstruction(state); break;
        case 0xCA: UnimplementedInstruction(state); break;
        case 0xCB: UnimplementedInstruction(state); break;
        case 0xCC: UnimplementedInstruction(state); break;
        case 0xCD: UnimplementedInstruction(state); break;
        case 0xCE: UnimplementedInstruction(state); break;
        case 0xCF: UnimplementedInstruction(state); break;
        case 0xD0: UnimplementedInstruction(state); break;
        case 0xD1: UnimplementedInstruction(state); break;
        case 0xD2: UnimplementedInstruction(state); break;
        case 0xD3: UnimplementedInstruction(state); break;
        case 0xD4: UnimplementedInstruction(state); break;
        case 0xD5: UnimplementedInstruction(state); break;
        case 0xD6: UnimplementedInstruction(state); break;
        case 0xD7: UnimplementedInstruction(state); break;
        case 0xD8: UnimplementedInstruction(state); break;
        case 0xD9: UnimplementedInstruction(state); break;
        case 0xDA: UnimplementedInstruction(state); break;
        case 0xDB: UnimplementedInstruction(state); break;
        case 0xDC: UnimplementedInstruction(state); break;
        case 0xDD: UnimplementedInstruction(state); break;
        case 0xDE: UnimplementedInstruction(state); break;
        case 0xDF: UnimplementedInstruction(state); break;
        case 0xE0: UnimplementedInstruction(state); break;
        case 0xE1: UnimplementedInstruction(state); break;
        case 0xE2: UnimplementedInstruction(state); break;
        case 0xE3: UnimplementedInstruction(state); break;
        case 0xE4: UnimplementedInstruction(state); break;
        case 0xE5: UnimplementedInstruction(state); break;
        case 0xE6: UnimplementedInstruction(state); break;
        case 0xE7: UnimplementedInstruction(state); break;
        case 0xE8: UnimplementedInstruction(state); break;
        case 0xE9: UnimplementedInstruction(state); break;
        case 0xEA: UnimplementedInstruction(state); break;
        case 0xEB: UnimplementedInstruction(state); break;
        case 0xEC: UnimplementedInstruction(state); break;
        case 0xED: UnimplementedInstruction(state); break;
        case 0xEE: UnimplementedInstruction(state); break;
        case 0xEF: UnimplementedInstruction(state); break;
        case 0xF0: UnimplementedInstruction(state); break;
        case 0xF1: UnimplementedInstruction(state); break;
        case 0xF2: UnimplementedInstruction(state); break;
        case 0xF3: UnimplementedInstruction(state); break;
        case 0xF4: UnimplementedInstruction(state); break;
        case 0xF5: UnimplementedInstruction(state); break;
        case 0xF6: UnimplementedInstruction(state); break;
        case 0xF7: UnimplementedInstruction(state); break;
        case 0xF8: UnimplementedInstruction(state); break;
        case 0xF9: UnimplementedInstruction(state); break;
        case 0xFA: UnimplementedInstruction(state); break;
        case 0xFB: UnimplementedInstruction(state); break;
        case 0xFC: UnimplementedInstruction(state); break;
        case 0xFD: UnimplementedInstruction(state); break;
        case 0xFE: UnimplementedInstruction(state); break;
        case 0xFF: UnimplementedInstruction(state); break;
    }    
    state->pc+=opbytes;  //for the opcode
    return opbytes;
}