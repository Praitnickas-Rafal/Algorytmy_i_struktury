//Rafal Praitnickas, Student
//2022-11-27
#include <math.h>
#include <stdio.h>

int X(int n, int a) {
  if (pow(2, a - 1) <= n && n <= pow(2, a) && n > 1) {
    return X(n - 1, a) + a;
  } else {
    return 1;
  }
}

int main(void) {

  int rezultat = X(255, 2);
  printf("REZULTAT: %d", rezultat);
}
