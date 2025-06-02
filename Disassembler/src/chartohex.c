/** 
 * @file chartohex.c
 * 
 * @brief This file implements the general schema of characters -> bytes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/disassembler.h"

int main() {
    char line1[] = "0000000 0000 c300 18d4 0000 c5f5 e5d5 8cc3 0000\n";
    char line2[] = "0000010 c5f5 e5d5 803e 7232 2120 20c0 cd35 17cd\n";
    char line3[] = "0000020 01db da0f 0067 ea3a a720 42ca 3a00 20eb\n";

    // convert these strings into byte code
    // Skipping the first eight characters
    // Read them into

    printf("%ld\n", sizeof(line1));
    printf("%c\n", line1[48]);

    return 0;
}