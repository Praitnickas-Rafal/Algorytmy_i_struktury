//Wykonał: Rafal Praitnickas, Student
//Data: 2023-01-02
//meteriał wypożyczony z Interneru
//Program przytłumaczony z C++ na C, nie dokońca działa.
#include <stdlib.h>
#include <stdio.h>


const int N = 79;  // długość łańcucha s
const int M =  5;  // długość wzorca p

int main( )
{

  char s[] = "AABABBBBABBBBABABAAABBBAABBBABABBABABBAABABBBBBAABAAAAAAABABBBABBBABAABBBBAAAAB"; 
  char p[] = "BABBB";
  int PI [ M + 1 ], i, b, pp;

  PI [ 0 ] = b = -1;
  for( i = 1; i <= M; i++ )
  {
    while( ( b > -1 ) && ( p [ b ] != p [ i - 1 ] ) ) b = PI [ b ];
    PI [ i ] = ++b;
  }

  printf("%s \n", p);

  printf("%s", s);

  pp = b = 0;
  for( i = 0; i < N; i++ )
  {
    while( ( b > -1 ) && ( p [ b ] != s [ i ] ) ) b = PI [ b ];
    if( ++b == M )
    {
      while( pp < i - b + 1 )
      {
        printf(" "); pp++;
      }
        printf("^"); pp++;
        b = PI [ b ];
    }
  }
  return 0;
} 
