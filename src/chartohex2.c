/** 
 * @file chartohex2.c
 * @brief Converts file representations of hexadecimal words into bytecode using strtoul.
 * 
 * @details This program demonstrates how to convert space-separated hexadecimal words within
 * a file into byte values, which are then stored in a buffer.
 * 
 * Notes:
 * - The extracted words are manually null-terminated to satisfy strtoul.
 * - This program builds on the work of chartohex.c by reading from files
 * 
 * @author Andy J. Lee
 * @date 2025-06-02
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("input.txt", "r");  // Open file
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[256];  // Buffer for each line (adjust size as needed)

    // Read lines from file
    while (fgets(line, sizeof(line), file)) {
        // Optional: Skip empty lines or comment lines if needed
        if (line[0] == '\n' || line[0] == '#') continue;

        // Process the line like you did with line1
        char *counter = line + 8;  // Adjust based on format of input
        char captured[5];
        char captured2[5];

        strncpy(captured, counter, 4);
        captured[4] = '\0';
        counter += 5;  // Move past space
        strncpy(captured2, counter, 4);
        captured2[4] = '\0';

        unsigned int val1 = (unsigned int)strtoul(captured, NULL, 16);
        unsigned int val2 = (unsigned int)strtoul(captured2, NULL, 16);

        unsigned char buffer[4];
        buffer[0] = val1 & 0xFF;
        buffer[1] = (val1 >> 8) & 0xFF;
        buffer[2] = val2 & 0xFF;
        buffer[3] = (val2 >> 8) & 0xFF;

        // Print or process the buffer
        printf("0x%02X 0x%02X\n", buffer[0], buffer[1]);
        printf("0x%02X 0x%02X\n", buffer[2], buffer[3]);
    }

    fclose(file);  // Close file
    return 0;
}
