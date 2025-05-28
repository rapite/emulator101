#include <stdio.h>
#include <stdlib.h>
#include "../include/disassembler.h"

int main() {
    unsigned char codebuffer[] = { 0x06, 0x80, 0x00 };
    disassemble8080Op(codebuffer, 0);
    disassemble8080Op(codebuffer, 2);
    return 0;
}