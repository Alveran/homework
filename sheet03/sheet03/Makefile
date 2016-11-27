
CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

#
# Vorbedingungen fuer Rezepte stehen hinter dem ":". Die folgende Zeile
# bewirkt, dass der Aufruf "make" dem Aufruf "make run" gleichbedeutend ist,
# da ebenfalls das Rezept "run" abgearbeitet werden muss.
#

all: run

#
# Der Aufruf "make aufg09.exe" muss erst die Rezepte "aufg09.c" und "libSVG.h"
# abarbeiten, um fehlerfrei zu laufen. Da "aufg09.c" und "libSVG.h
# Quelldateien sind, wird lediglich geprueft, ob die Dateien veraendert wurden.
#

aufg09.exe: aufg09.c libSVG.h
	$(CC) $(CFLAGS) -o aufg09.exe aufg09.c
koordinaten: koordinatensystem.c 
	$(CC) $(CFLAGS) -o koordinatensystem koordinatensystem.c

#
# Der Aufruf "make run" muss erst das Rezept "aufg09.exe" abarbeiten, um
# fehlerfrei zu laufen.
#

run: aufg09.exe
	./aufg09.exe
