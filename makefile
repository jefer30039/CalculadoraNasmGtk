CC = gcc
CFLAGS = `pkg-config --cflags --libs gtk4`
PROG = main

$(PROG): $(PROG).c
	$(CC) $(PROG).c -o $(PROG) $(CFLAGS)

clean:
	rm -f $(PROG)

run:
	./$(PROG)