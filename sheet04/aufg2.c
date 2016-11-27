#include <stdio.h>
#include "libSVG.h"

#define WIDTH 800
#define HEIGHT 600
#define BOX 25
char *colour = "black";
short const LINE_WIDTH = 1;
short const TEXT_SIZE = 12;

void draw_background(FILE *svg) {
   for(int i=0; i<WIDTH;i+=BOX) {
      svg_line(svg, i, 0, i, HEIGHT, "lightgrey", LINE_WIDTH);
   }
   for(int j=0; j<HEIGHT;j+=BOX) {
      svg_line(svg, 0, j, WIDTH, j, "lightgrey", LINE_WIDTH);
   }
}

void draw_coordinateLines(FILE *svg, int value, int center_x, int center_y) {
   int below_y = center_y - (value * BOX);
   int above_y = center_y + (value * BOX);
   int below_x = center_x - (value * BOX);
   int above_x = center_x + (value * BOX);

   svg_line(svg, center_x, center_y, center_x, below_y, colour, LINE_WIDTH); 
   svg_line(svg, center_x, center_y, center_x, above_y, colour, LINE_WIDTH); 
   svg_line(svg, center_x, center_y, below_x, center_y, colour, LINE_WIDTH); 
   svg_line(svg, center_x, center_y, above_x, center_y, colour, LINE_WIDTH); 
}

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

int main(int argc, char *argv[]) {
   char *endptr;
   int value;
   if (argc < 2) {
      printf("Usage: %s byte", argv[0]);
      return 1;
   } else {
      value = strtol(argv[1], &endptr, 10); 
   }
   // creates file
   FILE *svg = svg_create("KoordinatenSystem.svg", WIDTH, HEIGHT);
   // Draws canvas
   svg_rect(svg, 0, 0, WIDTH, HEIGHT, colour, 10, "white");
   int center_x = WIDTH / 2;
   int center_y = HEIGHT / 2;

   draw_background(svg);
   draw_coordinateLines(svg, value, center_x, center_y);
   draw_x_numbers(svg, value, center_x, center_y);
   draw_y_numbers(svg, value, center_x, center_y);
   svg_text(svg, center_x + value * BOX + 2, center_y + TEXT_SIZE/3, colour, TEXT_SIZE, "", "> x");
   svg_text(svg, center_x - TEXT_SIZE/4, center_y - value * BOX, colour, TEXT_SIZE, "", "^");
   svg_text(svg, center_x - TEXT_SIZE/4, center_y - value * BOX - TEXT_SIZE, colour, TEXT_SIZE, "", "y");

   svg_finish(svg); 
}
