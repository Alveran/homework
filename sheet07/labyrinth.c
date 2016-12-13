#include <time.h>
#include <stdio.h>
#include "libBMP.h"

#define N 10
#define M 10
#define WALL '@'
#define MAUS 'o'
#define START_MAUS_X N/2
#define START_MAUS_Y M/2

#define WHITE 0x00FFFFFF
#define BLACK 0x00000000
#define RED 0x00FF0000
#define BLUE 0x000000FF


char pos[N][M]; 
int isExitDrawn = 0;

int GetRandomValue() {
   srand(time(NULL));
   return rand()%M;
}

void ResetLabyrinth(int x, int y, int randomValue) {
   if(x == 0 || y==0 || x==M || y==N) {
      if(isExitDrawn<2 && randomValue==y && y!=0) {
         isExitDrawn++;
         pos[x][y] = ' ';
      } else if(x==N-1 && y==M && (isExitDrawn<1)) {
         pos[x][y] = ' ';
      } else {
         pos[x][y] = WALL; 
      }
   } else {
      pos[x][y] = ' ';
   }
}

void AddWalls() {
   pos[5][3] = '*';
   pos[7][4] = '*';
   pos[7][5] = '*';
   pos[8][5] = '*';
   pos[3][8] = '*';
   pos[8][2] = '*';
   pos[6][5] = '*';
   pos[2][8] = '*';
}

void PrintLabyrinth() {
   printf("\n\n\n\n");
   for(int y = 0; y <= M; ++y) {
      for(int x=0; x<=N; ++x) {
         printf("%c", pos[x][y]);
      }
      printf("\n");
   }
}

void PrintBMP(uint32_t *data) {
   for(int y = 0; y <= M; ++y) {
      for(int x=0; x<=N; ++x) {
         if(pos[x][y]==WALL || pos[x][y]=='*') {
            bmp_rect(data, BLACK,BLACK,x+20);
         }
      }
   }
}

void Init() {
   int randomValue = GetRandomValue();
   for(int y = 0; y <= M; ++y) {
      for(int x=0; x<=N; ++x) {
        ResetLabyrinth(x,y,randomValue); 
        AddWalls();
      }
   }
}

int maus(int x, int y) {
   pos[x][y] = MAUS;

   int north = pos[x][y-1];
   int east = pos[x+1][y];
   int south = pos[x][y+1];
   int west = pos[x-1][y];

   if((x==M || y==M) && pos[x][y]==' ') {
      return 1;
   } else if(north==' '){
      maus(x, y-1);     
   } else if(east==' ') {
      maus(x+1, y);     
   } else if(south==' ') {
      maus(x, y+1);     
   } else if(west==' ') {
      maus(x-1,y);     
   }
   return 0;
}

int main() {
   Init();
   maus(START_MAUS_X,START_MAUS_Y);
   PrintLabyrinth();

   int bmp_width = (N+1) * 20;
   int bmp_height = (M+1) * 20;
   int area = bmp_width * bmp_height;
   uint32_t *data = malloc(area * sizeof(uint32_t));

   bmp_rect(data, RED, WHITE, bmp_width);
   PrintBMP(data);
   bmp_create("lab.bmp", data, bmp_width, bmp_height);
   return 0;
}
