
CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

aufg2: aufg2.c libSVG.h
	$(CC) $(CFLAGS) -o aufg2 aufg2.c
aufg1: aufg1.c 
	$(CC) $(CFLAGS) -lm -o aufg1 aufg1.c

run1: aufg1
	./aufg1 1

run2: aufg2
	./aufg2 5
