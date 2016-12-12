#include <stdio.h>

int fak(int n) {
   if(n > 1) {
      return n *fak(n-1);
   } else {
      return n;
   }
}


int main() {
   printf("%d\n", fak(20));
   return 0;
}
