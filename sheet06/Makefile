
CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
LDFLAGS = -lm

all: run

%.exe:%.c libBMP.h
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

run: aufg13.exe
	./aufg13.exe 100 100

