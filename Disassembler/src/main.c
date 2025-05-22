#include <stdio.h>
#include <stdlib.h>
#include "../include/disassembler.h"

int main() {
    unsigned char codebuffer[] = {0x11, 0x34, 0x12};
    disassemble8080Op(codebuffer, 0);
    return 0;
}