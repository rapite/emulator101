CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGETS = test
test: test.o disassembler.o
	$(CC) -o test test.o disassembler.o -lcriterion

test.o:
	$(CC) $(CFLAGS) -c tests/test.c

disassembler.o:
	$(CC) $(CFLAGS) -c src/disassembler.c

clean:
	rm *.o $(TARGETS)