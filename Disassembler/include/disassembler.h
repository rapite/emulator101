#ifndef MY_HEADER_H
#define MY_HEADER_H

/**
 * @brief Initializes Disassembler
 *
 * Sets up internal data structures
 *
 * @param[in] path is file path to hexdump output
 * @param[in] pc is program counter
 *
 * @return success or failure
 */
int init8080Op(const char* path);

/**
 * @brief Disassembles 8080Op
 *
 * Prints Opcode of program instruction based on case
 *
 * @param[in] codebuffer is a valid pointer to 8080 assembly
 * @param[in] pc is offset into code
 *
 * @return number of bytes of the op
 */
int disassemble8080Op(unsigned char *codebuffer, int pc);

#endif
