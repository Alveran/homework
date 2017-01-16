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
  int bmp_height = 1024;
  int bmp_width = 1024;

  // Benötigen für die Fläche des Bilder genug Speicher für jede Farbinformation je Pixel.
  int area = bmp_height * bmp_width;
  uint32_t *data = malloc(area * sizeof(uint32_t));

  bmp_rect(data, RED, WHITE);

  // ellipse
  bmp_ellipse(data, bmp_width, 512, 512, 300, 300, BLACK);
  for (int i=299; i > 0; i--) {
     bmp_ellipse(data, bmp_width,512,512,i,i, GREEN);
  }
  bmp_triangle(data,BLACK,BLUE,bmp_width,212,512,812,512,700,278); 
  bmp_line(data, RED, bmp_width, 512, 700, 512, 278);
  bmp_create("zweite.bmp", data, bmp_width, bmp_height);

  // freigabe der Ressourcen
  free(data);
  return 0;
}
