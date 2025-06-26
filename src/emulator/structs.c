#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include "../../include/emulator.h"

int main() {
    State8080 s1;
    State8080 s2 = {0};
    State8080 s3 = { 
        .cc = { 1, 1, 1, 1, 1, 4 }
    };

    printf("PRINTING STRUCTURE 1\n"); printStateData(&s1);
    printf("\n");
    printf("PRINTING STRUCTURE 2\n"); printStateData(&s2);
    printf("\n");
    printf("PRINTING STRUCTURE 3\n"); printStateData(&s3);

    return 0;
}
