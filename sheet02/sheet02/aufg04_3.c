#include <stdio.h>

int main() {
   int n = 8;
   int counter = 1;
   int lineWidth = (n * 2) - 1;
   int sideCounter = 0;

   printf("\n");
   // main counter
   while (counter <= n) {
      int tempLineWidth = lineWidth;
      int whiteSpace = (tempLineWidth - sideCounter) / 2;
      int moreWhiteSpace = (tempLineWidth - sideCounter) / 2;
      int tempNumber = 1;
      int tempCounter = counter;

      // Line Width 
      while (tempLineWidth >= 0) {
        // in whitespaces
        while (whiteSpace > 0) {
           printf(" "); 
           whiteSpace--;
        }
        // count up
        while (tempNumber < counter) {
           printf("%d", tempNumber);
           tempNumber++;
        }
        // count down
        while (tempCounter > 0) {
           printf("%d", tempCounter);
           tempCounter--;
        }
        // out whiteSpaces
        while (moreWhiteSpace > 0) {
           printf(" "); 
           moreWhiteSpace--;
        }
        tempLineWidth--;
      }
      // Linebreak and counters for the next line
      counter++;
      sideCounter += 2;
      printf("\n");
   }
   printf("\n");
}
