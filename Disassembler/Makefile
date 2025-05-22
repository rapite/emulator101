CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGETS = test main

main: main.o disassembler.o
	$(CC) -o main disassembler.o main.o

test: test.o disassembler.o
	$(CC) -o test test.o disassembler.o -lcriterion

main.o:
	$(CC) $(CFLAGS) -c src/main.c

test.o:
	$(CC) $(CFLAGS) -c tests/test.c

disassembler.o:
	$(CC) $(CFLAGS) -c src/disassembler.c

clean:
	rm *.o $(TARGETS)