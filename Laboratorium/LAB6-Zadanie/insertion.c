//Wykonał: Rafal Praitnickas
//Data: 2023.12.23
#include <stdio.h>

int insertion(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i; j > 0 && prior(arr, j, j - 1); j--) {
      swap(arr, j, j - 1);
    }
  }
}
