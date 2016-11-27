#include <stdio.h>
#include <stdint.h>

int main() {
  // short Datentyp hat nur 2^16-1 Werte, also 65535 oder -65536 ist hoechste Wert
  int16_t y = 1024, z = 65; // auch "short" als Datentyp verwendbar


  // 1024 * 65 = 66560
  y = y * z;

  // Hier kommt der Wert von y heraus. 
  printf("1. Ausgabe: %d\n", y);
  // y - y, muesste eigentlich hier hearausgegeben werden...?
  // Links nach rechts Auswertung, Kommazahlendarstellung. 1024 / 3 ergibt eine
  printf("2. Ausgabe: %d\n", y / 3 * 3 - 3 * y / 3);
  printf("\n");

  return 0;
}
