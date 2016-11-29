#include <stdio.h>
#include "libSVG.h"
#include <math.h>

// Vorgaben der jetzigen Aufgaben.
#define SVG_WIDTH 800
#define SVG_HEIGHT 600

#define X_MIN 5
#define X_MAX 9

#define Y_MIN 7
#define Y_MAX 9

// Die Grösse eines Kästchens in Pixeln
#define BOX 20
// Textgrösse für Ziffern
#define TEXT_SIZE 12
// Breite der gezeichneten Linien
#define LINE_SVG_WIDTH 2

char *colour = "black";
char *line_colour = "red";

double x_svg2mat(int x_svg) {
   int x_diff = X_MAX-X_MIN;
   return X_MIN + x_svg * x_diff/SVG_WIDTH;
}

double y_svg2mat(int y_svg) {
   int y_diff = Y_MAX - Y_MIN;
   return Y_MIN - y_svg * y_diff/SVG_HEIGHT;
}

// Nimmt den Abstand entlang der x-Achse in Box Einheiten
int x_mat2svg(double x_coord) {
   return SVG_WIDTH/2 + x_coord * BOX;   
}

// Nimmt den Abstan entlang der y-Achse in Box Einheiten
int y_mat2svg(double y_coord) {
   return SVG_HEIGHT/2 - y_coord * BOX; 
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
void draw_coordinateLines(FILE *svg, int center_x, int center_y) {
   int below_y = center_y - (Y_MIN * BOX);
   int above_y = center_y + (Y_MAX * BOX + BOX);
   int below_x = center_x - (X_MIN * BOX);
   int above_x = center_x + (X_MAX * BOX);

   svg_line(svg, center_x, center_y, center_x, below_y, colour, LINE_SVG_WIDTH); 
   svg_line(svg, center_x, center_y, center_x, above_y, colour, LINE_SVG_WIDTH); 
   svg_line(svg, center_x, center_y, below_x, center_y, colour, LINE_SVG_WIDTH); 
   svg_line(svg, center_x, center_y, above_x, center_y, colour, LINE_SVG_WIDTH); 
}

// Zeichnet die Nummern entlang der x-koordinate
void draw_x_numbers(FILE *svg, int center_x, int center_y) {
   for(int i=1; i<=X_MAX; i++) {
      char value_to_string[8];
      sprintf(value_to_string, "%d", i);
      svg_text(svg, center_x + i*BOX-TEXT_SIZE/4, center_y + BOX/2, colour, TEXT_SIZE, "", value_to_string);
   }
   for(int i=1; i<=X_MIN; i++) {
      char value_to_string[8];
      sprintf(value_to_string, "-%d", i);
      svg_text(svg, center_x - i*BOX-TEXT_SIZE/3, center_y + BOX/2, colour, TEXT_SIZE, "", value_to_string);
   }
}

// Zeichnet die Ziffern entlang der y koordinate
void draw_y_numbers(FILE *svg, int center_x, int center_y) {
   for(int i=1; i<=Y_MIN; i++) {
      char value_to_string[8];
      sprintf(value_to_string, "%d", i);
      svg_text(svg, center_x+BOX/2, center_y - i*BOX+TEXT_SIZE/3, colour, TEXT_SIZE, "", value_to_string);
   }
   for(int i=1; i<=Y_MAX; i++) {
      char value_to_string[8];
      sprintf(value_to_string, "-%d", i);
      svg_text(svg, center_x+BOX/3, center_y + i*BOX+TEXT_SIZE/3, colour, TEXT_SIZE, "", value_to_string);
   }
}

// Lösung der Aufgabe fünf mit eigener Pow Lösung, kann allerdings eigentlich jede Math function ersetzt werden.
void draw_functions(FILE *svg, int start, int end) {
   for (int i = start; i<end; i++) {
      svg_line(svg, x_mat2svg(i), y_mat2svg(tgamma(i)), x_mat2svg(i+1), y_mat2svg(tgamma(i+1)) , line_colour, LINE_SVG_WIDTH); 
      svg_text(svg, x_mat2svg(i)-3, y_mat2svg(tgamma(i))+3, line_colour, TEXT_SIZE, "", "o");
   }
}

// This is where the magic happens
int main() {
   // creates file
   FILE *svg = svg_create("KoordinatenSystem.svg", SVG_WIDTH, SVG_HEIGHT);
   // Draws canvas
   svg_rect(svg, 0, 0, SVG_WIDTH, SVG_HEIGHT, colour, 10, "white");
   int center_x = SVG_WIDTH / 2;
   int center_y = SVG_HEIGHT / 2;

   // siehe Funktionsdokumentation
   draw_background(svg);
   draw_coordinateLines(svg, center_x, center_y);
   draw_x_numbers(svg, center_x, center_y);
   draw_y_numbers(svg, center_x, center_y);
   
   draw_functions(svg, -5, 5);

   // Ab hier nur noch die enden der jeweiligen Achsen, also > x und ^ y.
   svg_text(svg, center_x + X_MAX * BOX + 2, center_y + TEXT_SIZE/3, colour, TEXT_SIZE, "", "> x");
   svg_text(svg, center_x - TEXT_SIZE/4, center_y - Y_MIN * BOX, colour, TEXT_SIZE, "", "^");
   svg_text(svg, center_x - TEXT_SIZE/4, center_y - Y_MIN * BOX - TEXT_SIZE, colour, TEXT_SIZE, "", "y");

   svg_finish(svg); 
}
