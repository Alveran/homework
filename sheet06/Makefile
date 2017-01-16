
CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
LDFLAGS = -lm

aufg1: aufg13.c libBMP.h
	$(CC) $(CFLAGS) -lm -o aufg13.exe aufg13.c 

aufg2: aufg2.c libBMP.h
	$(CC) $(CFLAGS) -lm -o aufg2.exe aufg2.c 

run: aufg13.exe
	./aufg13.exe 100 100
run2: aufg2.c
	./aufg2.exe
