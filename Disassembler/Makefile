CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGETS = test main

main: main.o disassembler.o
	$(CC) -o main disassembler.o main.o

test: test.o disassembler.o
	$(CC) -o test test.o disassembler.o -lcriterion

char: char.o
	$(CC) -o char char.o

char.o:
	$(CC) $(CFLAGS) -c src/char.c

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

test.o: tests/test.c
	$(CC) $(CFLAGS) -c tests/test.c

disassembler.o: src/disassembler.c
	$(CC) $(CFLAGS) -c src/disassembler.c

clean:
	rm *.o $(TARGETS)