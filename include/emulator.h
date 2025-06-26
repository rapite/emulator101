#ifndef EMULATOR_H
#define EMULATOR_H

#include <stdint.h>

typedef struct ConditionCodes {
    uint8_t z:1;
    uint8_t s:1;
    uint8_t p:1;
    uint8_t cy:1;
    uint8_t ac:1;
    uint8_t pad:3;
} ConditionCodes;

typedef struct State8080 {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;
    uint16_t sp;
    uint16_t pc;
    uint8_t *memory;
    struct ConditionCodes cc;
    uint8_t int_enable;
} State8080;

/**
 * @brief 
 * 
 * Prints to stream no valid implementation of state->opcode
 *
 * @param[in] state is a valid struct of State8080
 *
 */
void UnimplementedInstruction(State8080* state);

/**
 * @brief 
 * 
 * Updates the set of registers, program counter (pc), stack pointer (sp),
 * condition codes (flags), and the memory array provided a valid
 * pointer to a state container.
 * 
 * @param[in] state is a valid State8080 pointer.
 * 
 * State includes the register set, pc, sp, flags, and memory array. 
 * The memory array is a collection of valid opcode, detailing the 
 * instruction set. 
 *
 * @return 
 */
int Emulate8080Op(State8080* state);

void printStateData(State8080* s);

#endif
