//Wykonał: Rafal Praitnickas, Student
//Data: 2023;01;29
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//dziesiętny system konwertujemy na binarny ->
int convert(int number) {
  int binary = 0, i = 0;
  while (number != 0) {
    int momento = number % 2;
    binary += momento * pow(10, i);
    number /= 2;
    i++;
  }
  return binary;
}
//Testowanie programu ->
int main(void) {
  int gray, top;
  int bity = 2; 
  
  top = pow(2, bity) - 1;
  
  for (int i = 0; i <= top; i++) {
    gray = i ^ (i >> 1);
    printf("%d\n", convert(gray));
  }
  return 0;
}

//Console: 0 1 11 10, przy podaniu parametru 2 (bity)
