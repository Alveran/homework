#include <stdio.h>

int main() {
   unsigned short const MAX = 65535;
   int const MIN = 0;
   int targetNumber = 12345;
   // need a 15 instead of 16, due to MAX being 2^16 -1
   int powerOf = 15;
   int binaryNumber[powerOf];

   if (targetNumber > MAX || targetNumber < MIN) {
      printf("Die eingebene Zahl liegt nicht innerhalb der Grenzen des vorgegebenen Wertebereichs.\n");
      return 0; 
   } else {
       while (targetNumber > 0) {
         int counter = powerOf;
         while (counter >= 0) {
            // does not work from zero
            long binaryValue = 1 << counter;
            if (targetNumber - binaryValue >= 0) {
               targetNumber -= binaryValue; 
               binaryNumber[counter] = 1;
            } else {
               binaryNumber[counter] = 0;
            }
            counter--;
         }
         // sadly have to catch the last array slot due to
         // shiftoperation limitations starting at one
         if (targetNumber == 1) {
            binaryNumber[0] = 1;
            targetNumber = 0;
         }
      }
   }

   printf("The number is:");

   // Prints the values of the array
   for (int i = powerOf; i >= 0; i--) {
      printf("%d", binaryNumber[i]);
   }
   printf("\n");
   return 0;
}
