#include <stdio.h>
#include "libSVG.h"

// Vorgaben der jetzigen Aufgaben.
#define SVG_WIDTH 800
#define SVG_HEIGHT 600

#define X_MIN SVG_HEIGHT/2
#define X_MAX SVG_WIDTH

#define Y_MIN SVG_HEIGHT
#define Y_MAX SVG_WIDTH/2

// Die Grösse eines Kästchens in Pixeln
#define BOX 25
// Textgrösse für Ziffern
#define TEXT_SIZE 12
// Breite der gezeichneten Linien
#define LINE_SVG_WIDTH 1

char *colour = "black";

double x_svg2mat(int x_svg) {
   int x_diff = X_MAX-X_MIN;
   return X_MIN + x_svg * x_diff/SVG_WIDTH;
}

double y_svg2mat(int y_svg) {
   int y_diff = Y_MAX - Y_MIN;
   return Y_MIN + y_svg * y_diff/SVG_HEIGHT;
}

// Nimmt den Abstand entlang der x-Achse in Box Einheiten
int x_mat2svg(double x_coord) {
   return X_MIN + x_coord * BOX;   
}

// Nimmt den Abstan entlang der y-Achse in Box Einheiten
int y_mat2svg(double y_coord) {
   return Y_MAX + y_coord * BOX; 
}

// Zeichnet die einzelnen kästchen.
void draw_background(FILE *svg) {
   for(int i=0; i<SVG_WIDTH;i+=BOX) {
      svg_line(svg, i, 0, i, SVG_HEIGHT, "lightgrey", LINE_SVG_WIDTH);
   }
   for(int j=0; j<SVG_HEIGHT;j+=BOX) {
      svg_line(svg, 0, j, SVG_WIDTH, j, "lightgrey", LINE_SVG_WIDTH);
   }
}

// Zeichnet die jeweilgen Achsen ausgehend von der Mitte nach aussen. 
// Hier steckt die Hauptarbeit drin, da wir nun andere Werte haben müssen.
void draw_coordinateLines(FILE *svg, int value, int center_x, int center_y) {
   int below_y = center_y - (value * BOX);
   int above_y = center_y + (value * BOX);
   int below_x = center_x - (value * BOX);
   int above_x = center_x + (value * BOX);

   svg_line(svg, center_x, center_y, center_x, below_y, colour, LINE_SVG_WIDTH); 
   svg_line(svg, center_x, center_y, center_x, above_y, colour, LINE_SVG_WIDTH); 
   svg_line(svg, center_x, center_y, below_x, center_y, colour, LINE_SVG_WIDTH); 
   svg_line(svg, center_x, center_y, above_x, center_y, colour, LINE_SVG_WIDTH); 
}

// Zeichnet die Nummern entlang der x-koordinate
void draw_x_numbers(FILE *svg, int value, int center_x, int center_y) {
   for(int i=1; i<=value; i++) {
      char value_to_string[8];
      sprintf(value_to_string, "%d", i);
      svg_text(svg, center_x + i*BOX-TEXT_SIZE/4, center_y + BOX/2, colour, TEXT_SIZE, "", value_to_string);
   }
   for(int i=1; i<=value; i++) {
      char value_to_string[8];
      sprintf(value_to_string, "-%d", i);
      svg_text(svg, center_x - i*BOX-TEXT_SIZE/3, center_y + BOX/2, colour, TEXT_SIZE, "", value_to_string);
   }
}

// Zeichnet die Ziffern entlang der y koordinate
void draw_y_numbers(FILE *svg, int value, int center_x, int center_y) {
   for(int i=1; i<=value; i++) {
      char value_to_string[8];
      sprintf(value_to_string, "%d", i);
      svg_text(svg, center_x+BOX/2, center_y - i*BOX+TEXT_SIZE/3, colour, TEXT_SIZE, "", value_to_string);
   }
   for(int i=1; i<=value; i++) {
      char value_to_string[8];
      sprintf(value_to_string, "-%d", i);
      svg_text(svg, center_x+BOX/3, center_y + i*BOX+TEXT_SIZE/3, colour, TEXT_SIZE, "", value_to_string);
   }
}

// This is where the magic happens
int main(int argc, char *argv[]) {
   // Damit man parameter beim Aufruf des Programms mitgeben kann
   // z.B. aufg2.exe 5, wobei die 5 die Größe des Koordinaten-Systems ist.
   char *endptr;
   int value;
   if (argc < 2) {
      printf("Usage: %s byte(Angabe der Länge der Achsen)\n", argv[0]);
      return 1;
   } else {
      value = strtol(argv[1], &endptr, 10); 
   }
   // creates file
   FILE *svg = svg_create("KoordinatenSystem.svg", SVG_WIDTH, SVG_HEIGHT);
   // Draws canvas
   svg_rect(svg, 0, 0, SVG_WIDTH, SVG_HEIGHT, colour, 10, "white");
   int center_x = SVG_WIDTH / 2;
   int center_y = SVG_HEIGHT / 2;

   // siehe Funktionsdokumentation
   draw_background(svg);
   draw_coordinateLines(svg, value, center_x, center_y);
   draw_x_numbers(svg, value, center_x, center_y);
   draw_y_numbers(svg, value, center_x, center_y);

   // Ab hier nur noch die enden der jeweiligen Achsen, also > x und ^ y.
   svg_text(svg, center_x + value * BOX + 2, center_y + TEXT_SIZE/3, colour, TEXT_SIZE, "", "> x");
   svg_text(svg, center_x - TEXT_SIZE/4, center_y - value * BOX, colour, TEXT_SIZE, "", "^");
   svg_text(svg, center_x - TEXT_SIZE/4, center_y - value * BOX - TEXT_SIZE, colour, TEXT_SIZE, "", "y");

   svg_finish(svg); 
}
