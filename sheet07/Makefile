CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

labyrinth: labyrinth.c libBMP.h
	$(CC) $(CFLAGS) -lm -o labyrinth.exe labyrinth.c
mandelbrot: mandelbrot.c libBMP.h
	$(CC) $(CFLAGS) -lm -o mandelbrot.exe mandelbrot.c

run lab: 
	./labyrinth.exe

run mandelbrot:
	./mandelbrot.exe
