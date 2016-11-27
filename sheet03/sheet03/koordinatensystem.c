#include <stdio.h>

int rowWidth(int width) {
   return width * 3 + 1;
}

int columnHeight(int height) {
   // added one for top
   return height * 2 + 1;
}

void printRight() {
   printf("> x \n"); 
}

// brauchen wir um die Zahlen an der Y achse richtig dar
// zustellen. 32 ist das char space und positive Zifferen 
// sollen mit fuehrendem Leerzeichen dargestellt werden.
void printNumbersY(int currentN) {
   if (currentN > 0 && currentN < 32) {
      putchar(' ');
      printf("%d", currentN);
   } else if (currentN < 0) {
      printf("%d", currentN);
   } else {
      putchar(currentN);
   }
}

// Druckt saemtliche Zeilen ohne die x-Achse aus
void printRow(int width,char c, char mid, int isMiddleLine, int currentN) {
   int half = width;
   int temp = half;
   int counter = 2;

   do {
      do {
         putchar(c);
         temp--;
      } while (temp > 0);

      if (counter == 2) {
         putchar(mid);
         printNumbersY(currentN);
         temp = half;
      } else if (isMiddleLine == 1 && counter == 1) {
         printRight();
      }
      // one less due to center position not req.
      temp = half - 1;
      counter--;
   } while (counter > 0);
}

void printTop(int width) {
   char space = ' ';
   printRow(width, ' ', 'y', 0, space);
   printf("\n");
   printRow(width, ' ', '^', 0, space);
   printf("\n");
}

// Druckt die Reihe mit den Ziffern unter der X-Achse
// Erweiterung der Function an dieser Stelle moeglich
// Alles > 10 durch 5 teilen damit die Angaben noch
// auf den Schirm passen und die spaces entsprechend ent
// fernen
void printNumberRow(int N, char centerY) {
   int tempN = N;
   int minus = '-';
   int space = ' ';

   do {
     putchar(minus);
     printf("%d", tempN);
     putchar(space);
     tempN--; 
   } while(tempN > 0);
   putchar(space);
   putchar(centerY);
   do {
      tempN++;
      putchar(space);
      putchar(space);
      printf("%d",tempN);
   } while(tempN < N);
}

int getCoordinateSystemSize(char *N) {
   char *endptr;
   int n = strtol(N, &endptr, 10);
   if(n > 9 || n < 1) {
      printf("%d", n);
      n = 10;
   }
   return n;
}

int main(int argc, char *argv[]){
   if (argc != 2) {
      printf("Nutzung: %s N {0 > N < 10}\n", argv[0]);
      return 1;
   }

   int N = getCoordinateSystemSize(argv[1]);

   int width = rowWidth(N);
   int height = columnHeight(N);
   int yPositionCounter = 2;
   char centerX = '-';
   char centerY = '|';
   char zero = '+';
   char space = ' ';
   int tempHeight = height;
   int tempN = N;

   printTop(width);
   do { 
      // Koennte man ab hier nochmal refactorn
      do
      {
         if (tempHeight%2 == 1) {
            printRow(width, space, centerY, 0, tempN);
         } else {
            printRow(width, space, centerY, 0, space);
            tempN--;
         }
         printf("\n");
         tempHeight--;
      } while (tempHeight / 2 > 0);

      if (yPositionCounter == 2) {
         // added a centerX here due to being x axis
         printRow(width, centerX, zero, 1, centerX);
         printNumberRow(N, centerY);
         printf("\n");
         tempN--;
      }
      yPositionCounter--;
      tempHeight = height;
   } while(yPositionCounter > 0);
   return 0;
}
