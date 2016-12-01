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

int main(int argc, char *argv[]) {
  // Vordefinierte Farben
  uint32_t colors[] = { BLACK, WHITE, RED, GREEN, BLUE };

  int bmp_height = -1;
  int bmp_width = -1;

  sscanf(argv[1], "%d", &bmp_height);
  sscanf(argv[2], "%d", &bmp_width);
  printf("Hoehe %d und Breite %d wurden angegeben.\n", bmp_height, bmp_width);

  // Generiere Daten reserviere genug Speicher für das Bild
  uint32_t *data = malloc(sizeof(bmp_height*bmp_width)); 

  // Random
  srand(time(NULL));
  for (int y = 0; y < bmp_height; y++) {
    for (int x = 0; x < bmp_width; x++) {
      bmp_set_pixel(data, bmp_width, bmp_height, x, y, colors[rand() % 5]);
    }
  }

  // bmpCreate 
  bmp_create("Random_Bild", data, bmp_width, bmp_height);

  // freigabe der Ressourcen
  free(data);
  return 0;
}
