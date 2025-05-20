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
 * @return number of bytes of the op
 */
int init8080Op(const char* path, int pc);


#endif