/*
Rafal Praitnickas, Student
*******************************************
Laboratorium 1. Obliczyc funkcja y = ax^2 znaczenia, gdy a - stale, x jest wybierany z tablicy X(n)
*******************************************
2022.10.11
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
    int n;
    double a, x[n], y;
    printf("Prosze, podac dlugosc tablicy:");
    scanf("%d", &n);
    
    printf("Prosze, podac a:");
    scanf("%lf", &a);
    
    for(int i=0; i < n; i++)
    {
        printf("Podaj x%d:", i+1);
        scanf("%lf", &x[i]);
    }
    for(int i=0; i < n; i++)
    {
        y = (a*x[i]*x[i]);
        printf("Wynik: y = %.lf , a = %.lf , x z Tablicy = %.lf \n", y, a, x[i]);
    }
    }
