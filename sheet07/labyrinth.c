#include <stdio.h>
#define N 10
#define M 10
#define WALL '*'
#define MAUS 'o'

char labyrinth[N][M]; 

void ResetLabyrinth(int x, int y) {
   if(x == 0 || y==0 || x==M || y==N) {
      labyrinth[x][y] = WALL; 
   } else if(N/2==x && M/2==y) {
      labyrinth[x][y] = MAUS;
   } else {
      labyrinth[x][y] = ' ';
   }
}

void Init() {
   for(int y = 0; y <= M; ++y) {
      for(int x=0; x<=N; ++x) {
        ResetLabyrinth(x,y); 
      }
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

int main() {
   Init();
   PrintLabyrinth();
   return 0;
}
