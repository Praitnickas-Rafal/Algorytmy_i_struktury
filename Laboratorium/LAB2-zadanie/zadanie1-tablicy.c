// Rafal Praitnickas. Student
// Tablica
// 2022-10-24
#include <stdio.h>
#include <stdlib.h>
int findElement(int szukanaLiczba, int *arr, int arrSize);

void insert(int item, int position, int *arr);

void deleteByElement(int position, int *arr, int arrSize);

int size(int *arr);

int findMax(int arrSize, int *arr);

int findMin(int arrSize, int *arr);

void printTable(int *arr, int arrSize);

void main(void) {
  
  int arr[100];
  
}

void insert(int item, int position, int *arr) { arr[position] = item; }

int size(int *arr) {
  int element = sizeof(&arr) / sizeof(int);

  return element;
}

void printTable(int *arr, int arrSize) {
  int i;

  for (i = 0; i < arrSize; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");
  printf("\n");
}
void deleteByElement(int position, int *arr, int arrSize) {
  int i;
  int zerowaP = 0;
  i = position;

  for (i = position; i < arrSize - 1; i++) {
    arr[i] = arr[i + 1];
  }
  arr[arrSize - 1] = zerowaP;
}

int findMax(int arrSize, int *arr) {
  int p = 0;
  int maximalnyElement = arr[p];

  for (int i = 0; i < arrSize; i++) {
    if (maximalnyElement < arr[i]) {
      maximalnyElement = arr[i];
    }
  }
  return maximalnyElement;
}

int findMin(int arrSize, int *arr) {
  int p = 0;
  int minimalnyElement = arr[p];

  for (int i = 0; i < arrSize; i++) {
    if (minimalnyElement > arr[i]) {
      minimalnyElement = arr[i];
    }
  }
  return minimalnyElement;
}
int findElement(int szukanaLiczba, int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    if (szukanaLiczba == arr[i]) {
      return i; // returnie liczbe
    }
  }
  return -1;
}
