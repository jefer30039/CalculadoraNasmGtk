CC = gcc
CFLAGS = `pkg-config --cflags --libs gtk4`
PROG = main

$(PROG): $(PROG).c
	nasm -f elf64 -o operaciones.o operaciones.asm
	$(CC) $(PROG).c -o $(PROG) $(CFLAGS) operaciones.o

clean:
	rm -f $(PROG)

run:
	./$(PROG)