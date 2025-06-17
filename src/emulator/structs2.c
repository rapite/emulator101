#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include "../../include/emulator.h"

int main() {
    State8080 s1 = {0};
    s1.memory = calloc(2, sizeof(uint8_t));
    
    s1.pc = 0x00;
    s1.memory[s1.pc] = 0x00;

    int opbytes = Emulate8080Op(&s1);
    
    printf("%d\n", opbytes);
    
    free(s1.memory);

    return 0;
}
