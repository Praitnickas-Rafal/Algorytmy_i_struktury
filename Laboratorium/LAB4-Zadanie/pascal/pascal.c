//Rafal Praitnickas, Student
//2022-11-28

#include <math.h>
#include <stdio.h>

int pascal(n , k){
  if(n == k || n == 0){
  return 1;
  }
  else{
  return pascal(n-1, k-1) + pascal(n - 1, k);
  }
}
int main(void) {
  int rezultat = pascal(5, 2);
  printf("REZULTAT: %d", rezultat);
}
