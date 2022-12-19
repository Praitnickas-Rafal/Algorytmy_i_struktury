# Prior
```
prior(array, X, Y)
{
  if (array[X] <= array[Y]){
    return true 
  }
    return false
}
```
# Swap 
```
swap(arr, X, Y)
{
    tem = arr[X]
    arr[X] = arr[Y]
    arr[Y] = tem
}
```
# Sortowania przez wymiana
```
selection(arr) 
{
   for (i= 0; i < n - 1; i++)
   {
		lowIndex = i;
		for (j = n-1; j > i; j--) 
    {
     if (prior(array[j], array[lowIndex])) 
     {
				lowIndex = j
				swap(array, i, lowIndex);
		 }
    }
   }
}
```
