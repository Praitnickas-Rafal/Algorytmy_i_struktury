//Rafal Praitnickas, Student
//2022-11-28

#include <math.h>
#include <stdio.h>

int geo(n, q, a){
 if (n == 1){ 
  return a;
 }
 else{
  return geo(n-1, q, a) * q;
 }
}
int main(void) {
  int rezultat = geo(5, 2, 3);
  printf("REZULTAT: %d", rezultat);
}
