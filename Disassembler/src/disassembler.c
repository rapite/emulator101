#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/disassembler.h"

/**
 * @brief Initializes Disassembler
 */
int init8080Op(const char* path, int pc) {
    FILE* fp = fopen(path, "r");
    if (!fp) {
        perror("Failed to open path");
        return -1;
    }
}

// TODO: Implement all Opcodes from 0x00 to 0xff
