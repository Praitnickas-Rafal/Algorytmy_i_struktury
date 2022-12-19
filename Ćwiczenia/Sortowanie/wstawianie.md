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
# Sortowanie przez wstawianie
```
insertion(arr) {
   for (i= 0; i < n - 1; i++) 
   {
   	for (j = i; j > 0 && prior(arr[j], arr[j-1]); j--) 
   	{
	swap(arr, j, j-1);
   	}
   }
}
```
# Komentarz
```
Pseudokod oprocowałem z prezetacji
```
