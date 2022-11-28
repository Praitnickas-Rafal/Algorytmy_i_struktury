//Rafal Praitnickas, Student
//2022-11-28
#include <math.h>
#include <stdio.h>

int Arytm(int n,int a, int d){
  if (n == 1)
  {
    return a;
  }
  else{
    return Arytm(n-1, a, d) + d;
  }
}
int main(void) {
  int rezultat = Arytm(5, 2, 3);
  printf("REZULTAT: %d", rezultat);
}
