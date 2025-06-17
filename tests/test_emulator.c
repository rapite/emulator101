#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/emulator.h"

Test(emulator, opcode_NOP) {
    // Setup: Initialize CPU state
    State8080 state = {0};

    state.memory = calloc(2, sizeof(uint8_t));

    // Load 0x00 (NOP) into memory at PC=0
    state.pc = 0x00;
    state.memory[state.pc] = 0x00;

    // Save original state values to ensure no side effects
    unsigned short original_sp = state.sp;
    unsigned char original_a = state.a;
    unsigned char original_b = state.b;
    unsigned char original_flags = *((unsigned char *)&state.cc); // assume flat flags
    
    // Execute NOP
    int opbytes = Emulate8080Op(&state);

    // Expect program counter incremented by 1
    cr_assert_eq(state.pc, 0x01, "NOP should increment PC by 1");
    
    // Ensure no side effects on registers or flags
    cr_assert_eq(state.sp, original_sp, "NOP should not modify SP");
    cr_assert_eq(state.a, original_a, "NOP should not modify A register");
    cr_assert_eq(state.b, original_b, "NOP should not modify B register");

    // Compare contents of original flags
    cr_assert_eq(*((unsigned char *) &state.cc), original_flags, "NOP should not modify flags");

    // Optionally verify return value (if Emulate8080Op returns opbytes)
    cr_assert_eq(opbytes, 1, "NOP is a 1-byte instruction");
}