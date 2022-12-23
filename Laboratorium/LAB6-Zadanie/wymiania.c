//Wykonał: Rafal Praitnickas, Student
//Data: 2023.12.23
#include <stdio.h>

int selection(int *arr, int n) 
{
for (i= 0; i < n - 1; i++)
   {
    int lowIndex = i;
    for (int j = n-1; j > i; j--) 
    {
     	if (prior(arr[j], arr[lowIndex])) 
     	{
	lowIndex = j;
	swap(arr, i, lowIndex)
     	}
    }
   }
}
