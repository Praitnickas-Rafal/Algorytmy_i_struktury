/* Rafal Praitnickas. Student
*-------------------------------
Obliczyc funkcja y = ax^2 znaczenia, gdy a ir x zmeniajan sie jednoczesnie: a z
1 krokiem 0.5, x - z 2 do 6 krokiem 2
*-------------------------------
2022.10.11 
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  float a = 1.0;
  float x = 2.0;
  float y = 0;

  while (x <= 6) {
    printf("%.f ", x);
    
    y = a * pow(x, 2);
    a = a + 0.5;
    x = x + 2.0;
    
    printf("%.f \n", y);
  }
  return 0;
}
