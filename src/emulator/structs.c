#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include "../../include/emulator.h"

void printData(State8080* s) {
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

int main() {
    State8080 s1;
    State8080 s2 = {0};
    State8080 s3 = { 
        .cc = { 1, 1, 1, 1, 1, 4 }
    };

    printf("PRINTING STRUCTURE 1\n"); printData(&s1);
    printf("\n");
    printf("PRINTING STRUCTURE 2\n"); printData(&s2);
    printf("\n");
    printf("PRINTING STRUCTURE 3\n"); printData(&s3);

    return 0;
}
