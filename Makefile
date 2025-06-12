CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGETS = test disassembler chartohex chartohex2 hexout

disassembler: main_disassembler.o disassembler.o
	$(CC) -o main disassembler.o main_disassembler.o

test_emulator: test_emulator.o emulator.o
	$(CC) -o test test_emulator.o disassembler.o -lcriterion

test_disassembler: test_disassembler.o disassembler.o
	$(CC) -o test test_disassembler.o disassembler.o -lcriterion

char: src/disassembler/chartohex.c src/disassembler/chartohex2.c disassembler.o
	$(CC) $(CFLAGS) -c src/disassembler/chartohex.c src/disassembler/chartohex2.c
	$(CC) -o chartohex chartohex.o disassembler.o
	$(CC) -o chartohex2 chartohex2.o disassembler.o

main_disassembler.o: src/disassembler/main_disassembler.c
	$(CC) $(CFLAGS) -c src/disassembler/main_disassembler.c

test_emulator.o: tests/test_emulator.c
	$(CC) $(CFLAGS) -c tests/test_emulator.c

test_disassembler.o: tests/test_disassembler.c
	$(CC) $(CFLAGS) -c tests/test_disassembler.c

disassembler.o: src/disassembler/disassembler.c
	$(CC) $(CFLAGS) -c src/disassembler/disassembler.c

emulator.o: src/emulator/emulator.c
	$(CC) $(CFLAGS) -c src/emulator/emulator.c

clean:
	rm *.o $(TARGETS)