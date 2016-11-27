/**
 * Prozedurale Programmierung
 *
 * Bibliothek fuer SVG (Scalable Vector Graphics) Elemente
 */
#ifndef __libSVG_h__
#define __libSVG_h__

#include <stdio.h>
#include <stdlib.h>

/**
 * Erstellt ein SVG Bild.
 *
 * svg_name - Name des SVG Bildes
 * width - Bildbreite (in Pixel)
 * height - Bildhoehe (in Pixel)
 */
FILE *svg_create(char *svg_name, int width, int height) {
  FILE *svg = fopen(svg_name, "w");
  if (svg == NULL) {
    fprintf(stderr, "\nSVG Bilddatei konnte nicht geoeffnet werden!\n");
    exit(EXIT_FAILURE);
  }
  fprintf(svg, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\"\n");
  fprintf(svg, "     xmlns:xlink=\"http://www.w3.org/1999/xlink\"\n");
  fprintf(svg, "     xmlns:ev=\"http://www.w3.org/2001/xml-events\"\n");
  fprintf(svg, "     version=\"1.1\"\n");
  fprintf(svg, "     baseProfile=\"full\"\n");
  fprintf(svg, "     width=\"%d\"\n", width);
  fprintf(svg, "     height=\"%d\">\n\n", height);
  return svg;
}



/**
 * Definiert ein farbgefuelltes Rechteck mit farbigem Rand.
 *
 * svg - Zeiger auf das SVG Bild
 * x - X-Koordinate der oberen linken Ecke (in Pixel)
 * y - Y-Koordinate der oberen linken Ecke (in Pixel)
 * width - Rechteckbreite (in Pixel)
 * height - Rechteckhoehe (in Pixel)
 * stroke - Farbe des Randes
 * stroke_width - Dicke des Randes (in Pixel)
 * fill- Fuellfarbe
 */
void svg_rect(FILE * svg, int x, int y, int width, int height,
              char *stroke, int stroke_width, char *fill) {
  if (svg == NULL) {
    fprintf(stderr, "\nUngueltiges SVG Bild!\n");
    exit(EXIT_FAILURE);
  }
  fprintf(svg,
          "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\" stroke-width=\"%d\" fill=\"%s\" />\n",
          x, y, width, height, stroke, stroke_width, fill);
}



/**
 * Definiert eine farbige Linie.
 *
 * svg - Zeiger auf das SVG Bild
 * x1 - X-Koordinate des Startpunktes (in Pixel)
 * y1 - Y-Koordinate des Startpunktes (in Pixel)
 * x2 - X-Koordinate des Endpunktes (in Pixel)
 * y2 - Y-Koordinate des Endpunktes (in Pixel)
 * stroke - Farbe der Linie
 * stroke_width - Dicke der Linie (in Pixel)
 */
void svg_line(FILE * svg, int x1, int y1, int x2, int y2, char *stroke,
              int stroke_width) {
  if (svg == NULL) {
    fprintf(stderr, "\nUngueltiges SVG Bild!\n");
    exit(EXIT_FAILURE);
  }
  fprintf(svg,
          "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"%d\" />\n",
          x1, y1, x2, y2, stroke, stroke_width);
}



/**
 * Definiert einen farbige Text.
 *
 * svg - Zeiger auf das SVG Bild
 * x - X-Koordinate des Textes (in Pixel)
 * y - Y-Koordinate des Textes (in Pixel)
 * fill - Schriftfarbe
 * font_size - Schriftgroesse (in Pixel)
 * transform - Schrifteffekt
 * text - Text der dargestellt wird
 */
void svg_text(FILE * svg, int x, int y, char *fill, int font_size,
              char *transform, char *text) {
  if (svg == NULL) {
    fprintf(stderr, "\nUngueltiges SVG Bild!\n");
    exit(EXIT_FAILURE);
  }
  fprintf(svg,
          "<text x=\"%d\" y=\"%d\" fill=\"%s\" font-size=\"%d\"  transform=\"%s\">%s</text>\n",
          x, y, fill, font_size, transform, text);
}



/**
 * Definiert eine farbige Zahl als Text.
 *
 * svg - Zeiger auf das SVG Bild
 * x - X-Koordinate des Textes (in Pixel)
 * y - Y-Koordinate des Textes (in Pixel)
 * fill - Schriftfarbe
 * font_size - Schriftgroesse (in Pixel)
 * transform - Schrifteffekt
 * number - Zahl, die als Text dargestellt wird
 */
void svg_number_as_text(FILE * svg, int x, int y, char *fill, int font_size,
                        char *transform, int number) {
  if (svg == NULL) {
    fprintf(stderr, "\nUngueltiges SVG Bild!\n");
    exit(EXIT_FAILURE);
  }
  fprintf(svg,
          "<text x=\"%d\" y=\"%d\" fill=\"%s\" font-size=\"%d\"  transform=\"%s\">%d</text>\n",
          x, y, fill, font_size, transform, number);
}



/**
 * Schliesst die SVG Bilderstellung ab.
 *
 * svg - Zeiger auf das SVG Bild
 */
void svg_finish(FILE * svg) {
  if (svg == NULL) {
    fprintf(stderr, "\nUngueltiges SVG Bild!\n");
    exit(EXIT_FAILURE);
  }
  fprintf(svg, "</svg>\n");
  fclose(svg);
}

#endif
