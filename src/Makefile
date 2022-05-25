CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = 

prog: main.c table.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf prog
