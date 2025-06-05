#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H 

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
