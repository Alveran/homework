#
# Das erste Makefile
# ------------------
#
# Ein Makefile ist eine Art "Kochbuch" mit Rezepten fuer den Zusammenbau
# eines Programms. Hier in der Vorlesung mit der Dateiendung ".exe"
# (EXEcutable = ausfuehrbar) gekennzeichnet.
#
# Definiert wird ein Rezept "all" zum Erstellen von der ausfuehrbaren
# Datei "aufg01.exe" aus der Quelldatei "aufg01.c", wenn in der
# Kommandozeile der Befehl
#
#   "make" bzw. "mingw32-make" unter Windows
#
# eingegeben wird. Was die einzelnen Parameter hinter "gcc" bedeuten,
# entnehmen Sie den folgenden Links:
#
#   -std=c99
#   https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html
#
#   -pedantic -Wall -Wextra
#   https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
#
#   -o
#   https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html
#
#
# ACHTUNG: Vor "gcc" muss ein TAB-Zeichen stehen. Ein Leerzeichen reicht
#          nicht. Mehr Informationen unter:
#
#   https://www.gnu.org/software/make/manual/make.html#Rule-Introduction
#

all:
	gcc -std=c99 -pedantic -Wall -Wextra -o aufg01.exe aufg01.c
run:
	./aufg01.exe
aufgabe2:
	gcc -std=c99 -pedantic -Wall -Wextra -o aufg02.exe aufg02.c
run2:
	./aufg02.exe
