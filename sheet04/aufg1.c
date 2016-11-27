#include <stdio.h>
#include <math.h>
const short MAX=8;

long factorial(int value) {
   long result = 1;
   do {
      result *= value;
      value--;
   } while (value > 0);
   return result;
}

long exponentiation(int base, int exponent) {
   int value = 1;
   for(int i=0; i<exponent; i++) {
      value *= base;
   }
   return value;   
}

double my_sin(int x) {
   double value;
   // differenz zwischen Schritt eins und Schritt zwei.
   // der mathematischen Fkt.
   // Abbruchbedingung Hilfsvariable y_old.
   // 
   for(int k = 0; k <= MAX; k++) {
      long top= exponentiation(x, (2*k + 1));
      long bottom = factorial(2*k+1);
      double fraction = (double) top / bottom;
      value += (double) exponentiation(-1, k) * fraction;
   }
   return value;
}

double my_arctan(double x) {
   // todo: darf nur zwischen -1, 1
   double result;
   for(int k=0; k <=MAX; k++) {
      long top=exponentiation(x, (2*k + 1));
      long bottom=2*k+1;
      double fraction = (double) top / bottom;
      result += (double) exponentiation(-1, k) * fraction;
   }
   return result;
}

double iArctan(double x) {
   double c = x;
   double y = c;
   double y_old = y-1;
   for (int k =1; y != y_old; k++) {
      y_old = y;
      c *= (-1) * x * x * (2 * (k -1 ) + 1) / (2 * k + 1);
      y += c;
      printf("c==%.20f, k == %d\n", c, k);
   }
   return y;
}

double my_log(double x) {
   // TODO: darf nur zwischen 0 -> 2
   double result;
   for(int k=1; k <=MAX; k++) {
      long top=exponentiation((x-1), k);
      double fraction=(double) top / k;
      result+=(double) exponentiation(-1, (k+1)) * fraction;
   } 
   return result;
}

int main(int argc, char *args[]) {
   printf("is %f\n", iArctan(0.99));
   printf("is %f\n", atan(0.99));
   printf("******************\n");


   return 0;
}
