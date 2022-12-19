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
# Sortowanie bąbelkowe
```
Buble(arr, rozmiar)
{
i = 0
while (i < rozmiar)
{
      j = rozmiar - 1
      while ( j > i )
            {   
            if (prior(arr[j], arr[j-l]))
              {
                swap(arr, j, j-1)
              }
            j--
            }
      i++
      }
}
```
