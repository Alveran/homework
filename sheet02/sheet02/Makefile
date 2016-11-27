#
# Variablen helfen in Makefiles copy&paste zu verringern und die "Rezepte"
# uebersichtlicher zu gestalten.
#

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

# Rezept wird aufgerufen mit "make"
all:
	$(CC) $(CFLAGS) -o aufg04.exe aufg04.c
	$(CC) $(CFLAGS) -o aufg04_2.exe aufg04_2.c
	$(CC) $(CFLAGS) -o aufg04_3.exe aufg04_3.c

# Rezept wird aufgerufen mit "make run"
run1:
	./aufg04.exe
run2:
	./aufg04_2.exe
run3:
	./aufg04_3.exe

