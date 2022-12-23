//Wykonał: Rafal Praitnickas, Student
//Data: 2022-12-23
#include <stdbool.h>
#include <stdio.h>

bool prior(int *arr, int X, int Y) {
  if (arr[X] <= arr[Y]) {
    return true;
  }
    return false;
}
