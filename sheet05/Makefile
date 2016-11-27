
CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

koordinatenSystem: koordinatenSystem.c libSVG.h
	$(CC) $(CFLAGS) -lm -o koordinatenSystem.exe koordinatenSystem.c 

run: koordinatenSystem
	./koordinatenSystem.exe
