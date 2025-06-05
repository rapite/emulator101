#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/disassembler.h"

int main(int argc, char*argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s hexdump.txt\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("error: Couldn't open %s\n", argv[1]);
        exit(1);
    }

    //Get the file size and read it into a memory buffer    
    fseek(f, 0L, SEEK_END);    
    int fsize = ftell(f);    
    fseek(f, 0L, SEEK_SET);

    unsigned char *buffer=malloc(fsize);
    
    char line[256]; // Buffer for each line

    // Read lines from file
    int i = 0;
    while(fgets(line, sizeof(line), f)) {
        char *counter = line + 8;
        char captured[5];
        
        for (int j = 0; j < 8; j++) {
            strncpy(captured, counter, 4);
            captured[4] = '\0';

            unsigned int val = (unsigned int)strtoul(captured, NULL, 16);
            buffer[i] = val & 0xFF;
            buffer[i+1] = (val >> 8) & 0xFF;
            i += 2;
            counter += 5;
        }
    }
    fclose(f);
    
    int pc = 0;
    while (pc < i) {    
        pc += disassemble8080Op(buffer, pc);
    }    

    free(buffer);
    return 0;
}