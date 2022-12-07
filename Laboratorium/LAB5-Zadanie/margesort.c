//Rafal Praitnickas, Student
//2022-12-07
//TabMerge szukałem informacji na stronach internetowych, ale sam algorytm zrozumiałem
//Tylko powstał probłem w liniejce 66 i 74 (warning)
#include <stdio.h>
#include <stdlib.h>
void TabMerge( int tab[], int L, int P, int mid){
  int roz1, roz2;
  
  roz1 = mid - L + 1;
  roz2 = P - mid;

  int pTab[roz2], lTab[roz1];
  int a, b, i;
  
  for(i=0; i < roz1; i++){
    lTab[i] = tab[L+i];}
  
  for(a=0; a < roz2; a++){
    pTab[a] = tab[mid + 1 + a];}
  
  i = 0;
  a = 0;
  b = L;

  while(i < roz1 && a < roz2)
    {
      if(lTab[i] <= pTab[a])
      {
        tab[b] = lTab[i];
        i++;
      }else{
        tab[b] = pTab[a];
        a++;
      }
      b++;
    }
  while(i < roz1){
    tab[b]= lTab[i];
    i++;
    b++;
  }
  while( a < roz2){
    tab[b]=pTab[a];
    a++;
    b++;
  }}
  
void MergeSort(int tab[], int L, int P )
{
  if(L<P)
  {
    int mid = L + (P - L)/2;

    //Rekurencja
    MergeSort(tab, L, mid);
    MergeSort(tab, mid + 1, P);
    TabMerge(tab, L, P, mid);
  }
}

int main(void) {
    //Sprawdzenie
    int roz=0;
    printf("Podaj rozmiar: ");
    scanf("%d", &roz);
    int tab[roz];
    printf("Wprowadz elementy tablicy: ");
    int licznik = 0;
    for (int i = 0; i < roz; i++)
    {  
        licznik++;
        printf("\n %d. Podaj:", licznik);
        scanf("%d", &tab[i]);
    }
    //Wywołanie funkcji
    MergeSort(tab, 0, roz - 1);
 
    printf("Posortowane: ");
    for (int i = 0; i < roz; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    return 0;
}
