/**
 * Prozedurale Programmierung
 *
 * Zufallsbild (BMP)
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "libBMP.h"

#define BLACK 0x00000000
#define WHITE 0x00FFFFFF
#define RED   0x00FF0000
#define GREEN 0x0000FF00
#define BLUE  0x000000FF

int main() {
  // Vordefinierte Farben
  uint32_t colors[] = { BLACK, WHITE, RED, GREEN, BLUE };

  int bmp_height = -1;
  int bmp_width = -1;

  //Frage Benutzer nach Bildgroesse (bmp_height, bmp_width)
printf("Please enter desired width: \n");
scanf("%d", &bmp_width);

printf("Please enter desired height: \n");
scanf("%d", &bmp_height);

  // Generiere Daten
  uint32_t *data = NULL; //Speicher mit malloc reservieren
    data = malloc(sizeof(bmp_height*bmp_width));

  // Random
  srand(time(NULL));
  for (int y = 0; y < bmp_height; y++) {
    for (int x = 0; x < bmp_width; x++) {
      bmp_set_pixel(data, bmp_width, bmp_height, x, y, colors[rand() % 5]);
    }
  }

  // TODO: Schreibe BMP Datei mit bmp_create
bmp_create("zufall.bmp", data, bmp_width, bmp_height);

  //Speicher data mit free freigeben
void free(data);
  return 0;
}
