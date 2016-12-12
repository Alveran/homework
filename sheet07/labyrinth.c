#include <time.h>
#include <stdio.h>
#define N 10
#define M 10
#define WALL '@'
#define MAUS 'o'
#define START_MAUS_X N/2
#define START_MAUS_Y M/2

char pos[N][M]; 
int isExitDrawn = 0;

int GetRandomValue() {
   srand(time(NULL));
   return rand()%M-2+1;
}

void ResetLabyrinth(int x, int y, int randomValue) {
   if(x == 0 || y==0 || x==M || y==N) {
      if(isExitDrawn<2 && randomValue==y) {
         isExitDrawn++;
         pos[x][y] = ' ';
      } else if(x==N-1 && y==M && isExitDrawn<2) {
         pos[x][y] = ' ';
      } else {
         pos[x][y] = WALL; 
      }
   } else {

      pos[x][y] = ' ';
   }
}

void PrintLabyrinth() {
   for(int y = 0; y <= M; ++y) {
      for(int x=0; x<=N; ++x) {
         printf("%c", pos[x][y]);
      }
      printf("\n");
   }
}

void Init() {
   int randomValue = GetRandomValue();
   for(int y = 0; y <= M; ++y) {
      for(int x=0; x<=N; ++x) {
        ResetLabyrinth(x,y,randomValue); 
      }
   }
}

int maus(int x, int y) {
   pos[x][y] = MAUS;

   int north = pos[x][y-1];
   int east = pos[x+1][y];
   int south = pos[x][y+1];
   int west = pos[x-1][y];

   if(x==M || y==M && pos[x][y]==' ') {
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
   return 0;
}
