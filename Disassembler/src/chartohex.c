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

    // convert these strings into byte code
    // Skipping the first eight characters
    char *counter = line1 + 8;
    char captured[5]; 
    char captured2[5]; 

    strncpy(captured, counter, 4);
    counter += 5;
    strncpy(captured2, counter, 4);
    captured[4] = '\0';
    captured2[4] = '\0';

    unsigned int val1 = (unsigned int)strtoul(captured, NULL, 16);
    unsigned int val2 = (unsigned int)strtoul(captured2, NULL, 16);

    unsigned char buffer[5];
    buffer[0] = val1 & 0xFF;
    buffer[1] = (val1 >> 8) & 0xFF;
    buffer[2] = val2 & 0xFF;
    buffer[3] = (val2 >> 8) & 0xFF;
    buffer[4] = '\0';

    printf("0x%02X 0x%02X\n", buffer[0], buffer[1]);
    printf("0x%02X 0x%02X\n", buffer[2], buffer[3]);
    
    return 0;
}