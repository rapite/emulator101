CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGETS = test_emulator test_disassembler disassembler chartohex chartohex2 hexout structs structs2

disassembler: main_disassembler.o disassembler.o
	$(CC) -o main disassembler.o main_disassembler.o

test_emulator: test_emulator.o emulator.o
	$(CC) -o test_emulator test_emulator.o emulator.o -lcriterion

test_disassembler: test_disassembler.o disassembler.o
	$(CC) -o test_disassembler test_disassembler.o disassembler.o -lcriterion

char: src/disassembler/chartohex.c src/disassembler/chartohex2.c disassembler.o
	$(CC) $(CFLAGS) -c src/disassembler/chartohex.c src/disassembler/chartohex2.c
	$(CC) -o chartohex chartohex.o disassembler.o
	$(CC) -o chartohex2 chartohex2.o disassembler.o

structs: src/emulator/structs.c emulator.o
	$(CC) $(CFLAGS) -c src/emulator/structs.c 
	$(CC) -o structs structs.o emulator.o
	
structs2: src/emulator/structs2.c emulator.o
	$(CC) $(CFLAGS) -c src/emulator/structs2.c
	$(CC) -o structs2 structs2.o emulator.o

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