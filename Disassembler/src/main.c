#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/disassembler.h"

int main(int argc, char*argv[]) {
    (void)argc;
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("error: Couldn't open %s\n", argv[1]);
        exit(1);
    }

    //Get the file size and read it into a memory buffer    
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);

    unsigned char *buffer=malloc(fsize);
    
    int i = 0;
    long pos = 0;
    unsigned char *byte1 = malloc(2);
    unsigned char *byte2 = malloc(2);
    while (i < 2) {
        fseek(f, pos + 8, SEEK_SET);
        int j; 
        for (j = 0; j < 8; j++) {
            fread(byte2, 1, 2, f); // two spaces in f
            fread(byte1, 1, 2, f); // two spaces in f

            memcpy(buffer + pos, byte1, 2); pos+=2;
            memcpy(buffer + pos, " ", 1); pos+=1;
            memcpy(buffer + pos, byte2, 2); pos+=2;
            memcpy(buffer + pos, " ", 1); pos+=1;
            fread(byte1, 1, 1, f); // one space in f
        } 
        memcpy(buffer + pos, byte1, 1);
        i++;
    }

    printf("%s\n", buffer);
    fclose(f);
    
    int pc = 0;
    while (pc < 100) {    
        pc += disassemble8080Op(buffer, pc);
    }    

    return 0;
}