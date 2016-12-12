#include <time.h>
#include <stdio.h>
#define N 10
#define M 10
#define WALL '@'
#define MAUS 'o'

char labyrinth[N][M]; 
int isExitDrawn = 0;

int GetRandomValue() {
   srand(time(NULL));
   return rand()%M;
}

void ResetLabyrinth(int x, int y, int randomValue) {
   if(x == 0 || y==0 || x==M || y==N) {
      if(isExitDrawn<2 && randomValue==y) {
         isExitDrawn++;
         labyrinth[x][y] = ' ';
      } else if(x==N-1 && y==M && isExitDrawn==0) {
         labyrinth[x][y] = ' ';
      } else {
         labyrinth[x][y] = WALL; 
      }
   } else if(N/2==x && M/2==y) {
      labyrinth[x][y] = MAUS;
   } else {
      labyrinth[x][y] = ' ';
   }
}

void PrintLabyrinth() {
   for(int y = 0; y <= M; ++y) {
      for(int x=0; x<=N; ++x) {
         printf("%c", labyrinth[x][y]);
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
   PrintLabyrinth();
}

int main() {
   Init();
   return 0;
}
