/**
 * Prozedurale Programmierung
 *
 * Hallo Tutor als SVG-Grafik
 */

#include <stdio.h>  // System Bibliothek
#include "libSVG.h" // Eigene Bibliothek

int main() {
  /* Die Funktion erstellt ein SVG Bild "hallo_tutor.svg" im gleichen
   * Verzeichnis, wo das compilierte Programm ausgefuehrt wird.
   * Der Umgang mit Dateien wird in spaeteren Uebungen ausfuehrlich erklaert!
   * "svg" ist jetzt ein Zeiger auf die geoeffnete Datei und muss an jede
   * Funktion uebergeben werden.
   */
  FILE *svg = svg_create("hallo_tutor.svg", 500, 500);

  svg_rect(svg, 0, 0, 500, 500, "black", 10, "yellow");
  // svg_line(svg, 20, 250, 480, 250, "black", 4);
  int counter = 2900; 
  int lineThickness = 1;
  int xStart = 0;
  int yStart = 180;
  int xEnd = 550;
  int yEnd = 550;
  char* colour = "pink";
  
  do {
     svg_line(svg, xStart, yStart, xEnd, yEnd, colour, lineThickness);
     if (counter % 5 == 1) {
         yEnd += 10;
         colour = "pink";
     } else if (counter % 2 == 1) {   
        yEnd *= -1;
        colour = "gold";
     } else {
        colour = "lightpink";
        yEnd += 2;
     }
     yStart += .5;
     counter--;
  } while (counter > 0);
  svg_text(svg, 100, 100, "darkred", 50, "", "Unicorns");
  svg_text(svg, 280, 130, "pink", 70, "rotate(30 250 110)", "Rock!");


  svg_finish(svg);  // Schliesst die Bilderstellung ab

  return 0;
}
