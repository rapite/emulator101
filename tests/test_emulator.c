#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/emulator.h"

void init8080 (State8080* state) {
    state->memory = calloc(2, sizeof(uint8_t));
    if (!(state->memory)) {
        exit(1);
    }

    state->pc = 0x00;
    state->memory[state->pc] = 0x00;
}

Test(emulator, opcode_NOP) {
    // Setup: Initialize CPU state
    State8080 state = {0};

    State8080 original_state = {0};

    init8080(&state);
    init8080(&original_state);

    original_state.sp = state.sp;
    original_state.a = state.a;
    original_state.b = state.b;
    original_state.cc = state.cc;
    
    // Execute NOP
    int opbytes = Emulate8080Op(&state);

    // Expect program counter incremented by 1
    cr_assert_eq(state.pc, 0x0001, "NOP should increment PC by 1");
    
    // Ensure no side effects on registers or flags
    cr_assert_eq(state.sp, original_state.sp, "NOP should not modify SP");
    cr_assert_eq(state.a, original_state.a, "NOP should not modify A register");
    cr_assert_eq(state.b, original_state.b, "NOP should not modify B register");

    // Compare contents of original flags
    cr_assert_eq(*((unsigned char *) &state.cc), *((unsigned char*) &state.cc), "NOP should not modify flags");

    cr_assert_eq(opbytes, 1, "NOP is a 1-byte instruction");
    free(state.memory);
    free(original_state.memory);
}

Test(emulator, opcode_LXI_B) {
    // Setup: Initialize CPU state
    State8080 state = {0};

    uint8_t buffer[] = {0x01, 0x34, 0x12};
    state.memory = buffer;
    
    int opbytes = Emulate8080Op(&state);
    // Expect program counter incremented by 3 (total)
    // 1 for instruction, 2
    cr_assert_eq(state.pc, 0x0003, "LXI B should increment PC by 3");
    cr_assert_eq(state.b, 0x12, "state.b should store (0x12)" );
    cr_assert_eq(state.c, 0x34, "state.c should store (0x34)");

    cr_assert_eq(opbytes, 3, "LXI B is a 3-byte instruction");
}
