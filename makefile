CC = cc
CFLAGS = -O3 -Wall -Wextra

all: main

main: mult.o
	$(CC) $(CFLAGS) main.c $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o