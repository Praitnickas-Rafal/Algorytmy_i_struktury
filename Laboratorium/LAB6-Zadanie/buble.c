//Wykonał: Rafal Praitnicas, Student
//Data: 2022.12.23
#include <stdio.h>

int bubble(int *arr, int s) {
  for (int i = 0; i < s - 1; i++) 
  {
    for (int j = s - 1; j > i; j--) 
    {
      if (prior(arr, j, j - 1)) 
      {
        swap(arr, j, j - 1);
      }
    }
  }
}
