# Sortowanie przez CountingSort
```
countingSort(arr, size, max) {
   result = [] 
   count = []

   for (i = 0; i < max; i++) {
     count[i] = 0 
   }

   for (j = 0; j < size; j++) {
     count[arr[j]] = arr[j] + 1 
   }

   for (i = 0; i < max; i++) {
     count[i] = count[i] + count[i - 1] 
   }

   for (j = size - 1; j > 0; j--) {
     result[count[arr[j]] - 1] = arr[j] 
	 count[arr[j]] = count[arr[j]] - 1
   }
   return result
}
```
