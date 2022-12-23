//Wykonał: Rafal Praitnickas
//Data: 2023.12.23
#include <stdio.h>

void quickSort(int *arr, int left, int right) {
  int i, j, pivot, temp;
  if (left < right) {
    pivot = left;
    i = left;
    j = right;
    while (i < j) {
      while (arr[i] <= arr[pivot] && i < right)
        i++;
      while (arr[j] > arr[pivot])
        j--;
      if (i < j) {
        swap(arr, i, j);
      }
    }
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
  }
}
