//Rafal Praitnickas, Student
//2022-12-07
//Tylko powstał probłem z scanfem w liniejce 24, 26 i 73 (warning)
#include <stdio.h>
//rekurencja
int binarySearchRecursion(int tab[], int start, int end, int index){
  if(start > end){
    index = 0; 
  }else{
    int midIndex = start + (end - start)/2;
   if (tab[midIndex] == index)
         return midIndex;
      if (tab[midIndex] > index)
         return binarySearchRecursion(tab, start, midIndex-1, index);
      return binarySearchRecursion(tab, midIndex+1, end, index);
   }
   return -1;
  }

int main(void){
//Sprawdzenie
  int n=0, index;
    printf("Podaj rozmiar: ");
    scanf("%d", &n);
    printf("Podaj index: ");
    scanf("%d", &index);
    int tab[n];
    printf("Wprowadz liczby do tablicy: ");
    int licznik = 0;
    for (int i = 0; i < n; i++)
    {  
        licznik++;
        printf("\n %d. Podaj:", licznik);
        scanf("%d", &tab[i]);
    }
   int r = binarySearchRecursion(tab, 0, n-1, index);
   if(r == -1 ) {
      printf("Index został nieznaleziony:");
   }
   else {
      printf("Index został znaleziony: %d", r);
   }
   return 0;
}
