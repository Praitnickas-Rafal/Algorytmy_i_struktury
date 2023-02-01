//Wykonał: Rafal Praitnickas
//Data: 2023.02.01
//Praca była wypożyczona z internetu, algorytm zrozumiałem
//przyrobiony z języka C++ na C.
#include <stdio.h>
#include <stdbool.h>

const int MAXP = 1000;

int main( )
{
  int a, b, i, j, n, P [ MAXP ];
  bool t;

  scanf("%d %d %d", &a, &b, &n);
  for( i = 0; i < n; i++ )
    scanf("%d", &P[i]);
  for( i = a; i <= b; i++ )
  {
    t = true;
    for( j = 0; j < n; j++ )
      if( i % P [ j ] == 0 )
      {
        t = false;
        break;
      }
    if( t ) printf("%d\n", i);
  }
  return 0;
} 
