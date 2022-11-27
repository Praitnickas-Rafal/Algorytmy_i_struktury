//Rafal Praitnickas, Student
//2022-11-27

#include <math.h>
#include <stdio.h>
int fib( int n){
  if(0 == n){
    return 0;
  }
  else if(n <=  2){
    return 1;
  }
  else{
    return fib(n-2)+fib(n-1);
  }
}
int main(void) {
  int rezultat = fib(0);
  printf("REZULTAT: %d", rezultat);
  //wyswietla - wyraz ciagu ile ma wartosci
}
