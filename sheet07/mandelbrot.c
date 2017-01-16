#include <stdio.h>
#include <complex.h>
#include "libBMP.h"

#define BLACK 0x00000000
#define WHITE 0x00FFFFFF
#define RED 0x00FF0000
#define BLUE 0x000000FF

#define NMAX 10
#define SIZE 1024

int mandelbrot(double c, int z, int n) {
   if(z<0) z *= -1;
   if(z>=2 || n==NMAX) return n;
   
   z = z * z + c;

   mandelbrot(c,z,++n);
}

int main() {
  int area = SIZE * SIZE;
  uint32_t *data = malloc(area*sizeof(uint32_t));

  bmp_rect(data,RED,WHITE,SIZE);

  for(int y=0; y<SIZE;++y) {
     for(int x=0; x<SIZE;++x) { 
        
        double c = -0.75+ (x-SIZE/2)*0.005 + I * (y-SIZE/2)*0.005;

        int recursionLevel = mandelbrot(c,0, 0);
        uint32_t color = BLACK;
        if(recursionLevel==1) {
           color = RED;
        } else if(recursionLevel==2) {
          color = BLUE;
        }
        bmp_set_pixel(data,SIZE,x,y,color);
     }
  }

  bmp_create("Mandelbrot.bmp", data, SIZE, SIZE);
  free(data);
}
