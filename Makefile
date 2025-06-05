CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGETS = test main char char2 hexout

main: main.o disassembler.o
	$(CC) -o main disassembler.o main.o

test: test.o disassembler.o
	$(CC) -o test test.o disassembler.o -lcriterion

char: char.o
	$(CC) -o char char.o

char.o: src/disassembler/char.c
	$(CC) $(CFLAGS) -c src/disassembler/char.c

main.o: src/disassembler/main.c
	$(CC) $(CFLAGS) -c src/disassembler/main.c

test.o: tests/disassembler/test.c
	$(CC) $(CFLAGS) -c tests/disassembler/test.c

disassembler.o: src/disassembler/disassembler.c
	$(CC) $(CFLAGS) -c src/disassembler/disassembler.c

clean:
	rm *.o $(TARGETS)