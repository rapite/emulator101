CC = gcc
CFLAGS = -Wall -Werror -Wextra

test: test.o disassembler.o
	$(CC) -o test test.o disassembler.o -lcriterion

test.o: tests/tests.c src/disassembler.c
	$(CC) $(CFLAGS) -c tests/test.c

disassembler.o: src/disassembler.c
	$(CC) $(CFLAGS) -c src/disassembler