/**
 * Prozedurale Programmierung
 *
 * Bibliothek fuer BMP (Windows Bitmap)
 */
#ifndef __libBMP_h__
#define __libBMP_h__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * Im BMP zugeordneten Daten-Array "data" wird an der Koordinate (x,y) der
 * Pixel auf den Wert "color" gesetzt.
 *
 * data - BMP Daten-Array.
 * width - Bildbreite (in Pixel)
 * height - Bildhoehe (in Pixel)
 * x - X-Koordinate im BMP.
 * y - Y-Koordinate im BMP.
 * color - Pixelfarbe.
 */
void bmp_set_pixel(uint32_t * data, int width, int x, int y, uint32_t color) {
   data[y * width + x] = color;
}

void bmp_rect(uint32_t * data, uint32_t red, uint32_t white) {
   int width = 1024;
   for(int y = 0; y < width; y++) {
     for(int x = 0; x < width; x++) {
        if (y == 0 || y==width-1) { 
           bmp_set_pixel(data, width, x, y, red);
        } else if (x==0 || x==width-1) {
           bmp_set_pixel(data, width, x,y,red);
        } else {
           bmp_set_pixel(data, width, x, y, white);
        }
     }
   }
}

void bmp_line(uint32_t * data, uint32_t color, int width, int x0, int y0, int x1, int y1) {
   int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
   int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
   int err = dx+dy, e2; /* error value e_xy */

   while(1){
      bmp_set_pixel(data, width, x0,y0, color);
      if (x0==x1 && y0==y1) break;
      e2 = 2*err;
      if (e2 > dy) { err += dy; x0 += sx; }/*e_xy+e_x>0 */
      if (e2 < dx) { err += dx; y0 += sy; }/*e_xy+e_y<0*/
   }
}

void bmp_ellipse(uint32_t * data, int width, int xm, int ym, int a, int b, uint32_t color)
{
   int dx = 0, dy = b; /* im I. Quadranten von links oben nach rechts unten */
   long a2 = a*a, b2 = b*b;
   long err = b2-(2*b-1)*a2, e2; /* Fehler im 1. Schritt */

   do {
      bmp_set_pixel(data, width, xm+dx, ym+dy, color); /* I. Quadrant */
      bmp_set_pixel(data, width, xm-dx, ym+dy, color); /* II. Quadrant */
      bmp_set_pixel(data, width, xm-dx, ym-dy, color); /* III. Quadrant */
      bmp_set_pixel(data, width, xm+dx, ym-dy, color); /* IV. Quadrant */

     e2 = 2*err;
     if (e2 <  (2*dx+1)*b2) { dx++; err += (2*dx+1)*b2; }
     if (e2 > -(2*dy-1)*a2) { dy--; err -= (2*dy-1)*a2; }
   } while (dy >= 0);

   while (dx++ < a) { /* fehlerhafter Abbruch bei flachen Ellipsen (b=1) */
         bmp_set_pixel(data, width, xm+dx, ym, color); /* -> Spitze der Ellipse vollenden */
         bmp_set_pixel(data, width, xm-dx, ym, color);
   }
}

void bmp_triangle(uint32_t * data, uint32_t border_color, uint32_t bg_color,int width, int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) {

   bmp_line(data,border_color, width, p2x, p3x, p2y, p3y);
   bmp_line(data,border_color, width, p1x, p3x, p1y, p3y);
   for (int i = p1x; i < p2x; ++i) {
      bmp_line(data, bg_color, width, i, p3x, p1y, p3y);
      bmp_set_pixel(data, width, i, p1y+189, border_color);
   }
}

/**
* Schreibt die N letzten Bytes eines 64-bit Integers in ein BMP Bild.
* Das am wenigsten signifikante Byte (LSB) wird zuerst geschrieben.
* (Little Endian).
*
* bmp - Zeiger auf das bmp Bild
* byte - Byte-Muster.
* N - Anzahl der zu schreibenden Bytes (N <= 8).
*/
void bmp_write_N_byte(FILE * bmp, uint64_t byte, int N) {
  for (int i = 0; ((i < N) && (i < 8)); i++) {
    fputc(byte % 256, bmp);
    byte /= 256;
  }
}

/**
 * Erstellt einen BMP-File-Header, insgesamt 14 Byte.
 *
 * bmp - Zeiger auf das bmp Bild
 * width - Bildbreite (in Pixel)
 * height - Bildhoehe (in Pixel)
 */
void bitmap_file_header(FILE * bmp, int width, int height) {
  // (2 Byte, uint16_t) ASCII-Zeichenkette "BM" (Hex: 0x42 0x4D Dez: 19778).
  fputc('B', bmp);
  fputc('M', bmp);
  // (4 Byte, uint32_t) Groesse der BMP-Datei in Byte.
  // = bitmap_file_header + bitmap_info_header + Daten
  bmp_write_N_byte(bmp, 14 + 40 + width * height * 32, 4);
  // (4 Byte, uint32_t) Reserviert, Standard: 0
  bmp_write_N_byte(bmp, 0, 4);
  // (4 Byte, uint32_t) Offset der Bilddaten in Byte vom Beginn der Datei an,
  // bei Echtfarben fast immer 54 (manche Software ignoriert diese Angabe
  // daher fehlerhafterweise).
  bmp_write_N_byte(bmp, 54, 4);
}



/**
 * Erstellt einen BMP-Info-Header, insgesamt 40 Byte.
 *
 * bmp - Zeiger auf das bmp Bild
 * width - Bildbreite (in Pixel)
 * height - Bildhoehe (in Pixel)
 */
void bitmap_info_header(FILE * bmp, int width, int height) {
  // (4 Byte, uint32_t) Groesse von bitmap_info_header in Byte
  bmp_write_N_byte(bmp, 40, 4);
  // (4 Byte, int32_t) Breite der Bitmap in Pixel.
  bmp_write_N_byte(bmp, width, 4);
  // (4 Byte, int32_t) Hoehe der Bitmap in Pixel. Negativ: top-bottom.
  bmp_write_N_byte(bmp, -height, 4);
  // (2 Byte, uint16_t) Anzahl der Farbebenen, nicht fuer BMP verwendet
  bmp_write_N_byte(bmp, 1, 2);
  // (2 Byte, uint16_t) Gibt die Farbtiefe der Bitmap in bpp an; muss einer
  // der folgenden Werte sein: 1, 4, 8, 16, 24 oder 32. Bei 1, 4 und 8 bpp
  // sind die Farben indiziert.
  bmp_write_N_byte(bmp, 32, 2);
  // (4 Byte, uint32_t) Keine Kompression verwendet = 0
  bmp_write_N_byte(bmp, 0, 4);
  // (4 Byte, uint32_t) Groesse der reinen Bilddaten in Byte (mit padding).
  bmp_write_N_byte(bmp, width * height * 32, 4);
  // (4 Byte, int32_t) Horizontale Aufloesung des Zielausgabegerätes in Pixel
  // pro Meter; wird aber fuer BMP-Dateien meistens auf 0 gesetzt.
  bmp_write_N_byte(bmp, 0, 4);
  // (4 Byte, int32_t) Vertikale Aufloesung des Zielausgabegerätes in Pixel
  // pro Meter; wird aber fuer BMP-Dateien meistens auf 0 gesetzt.
  bmp_write_N_byte(bmp, 0, 4);
  // (4 Byte, uint32_t) Anzahl der Eintraege der Farbtabelle; 0 bedeutet keine.
  bmp_write_N_byte(bmp, 0, 4);
  // (4 Byte, uint32_t) Anzahl wichtiger Farben; 0 bedeutet alle sind wichtig.
  bmp_write_N_byte(bmp, 0, 4);
}

/**
 * Erstellt ein BMP Bild.
 *
 * bmp_name - Name des BMP Bildes
 * data - BMP Daten-Array.
 * width - Bildbreite (in Pixel)
 * height - Bildhoehe (in Pixel)
 */
void bmp_create(char *bmp_name, uint32_t * data, int width, int height) {
  FILE *bmp = fopen(bmp_name, "w");
  if (bmp == NULL) {
    fprintf(stderr, "\nbmp Bilddatei konnte nicht geoeffnet werden!\n");
    exit(EXIT_FAILURE);
  }
  bitmap_file_header(bmp, width, height);
  bitmap_info_header(bmp, width, height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      bmp_write_N_byte(bmp, data[y * width + x], 4);
    }
  }
  fclose(bmp);
}

#endif
