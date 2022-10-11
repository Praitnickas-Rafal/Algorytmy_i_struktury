/*
Rafal Praitnickas, Student
************************************
Obliczyc funkcja y = ax^2 znaczenia, gdy a - stale. x - zmieniase z x0 do xn, krokiem hx
***********************************
2022.10.11
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){

float a, y;
float x = 0, x_od_przedzialu = 0, x_do_przedzialu = 0;
float xh = 0; //czyli kroki
int n=0;
	
	do {
		printf("Prosze, Podac a:\n"); 
		scanf("%f", &a);
	}
		while ( a == 0);
		
		printf("X od przedzialu jest:\n");
		scanf("%f", &x_od_przedzialu);
		
	do {
		printf("X do przedzialu jest:\n");
		scanf("%f", &x_do_przedzialu);
		}
		while (x_od_przedzialu > x_do_przedzialu);

	do {
		printf("Prosze, podac krok:\n");
		scanf("%f", &xh);
		}
		while (xh <= 0);
		
		if (x_do_przedzialu > x_od_przedzialu){
			x = x_od_przedzialu;
			
			while(x < x_do_przedzialu){
			y = a * pow(x, 2);
			printf("Wynik: x= %.f y= %.f \n", x, y);
			x+=xh;
			}
		}
}
