# Sortowanie QuickSort
```
partition(arr, left, right, pivot) {
   while (left <= right) {
      while (prior(pivot, arr[left])) {
         left++
      }
      while (prior(arr[right], pivot)) {
         right--
      }
      if (left <= right) {
			  swap(arr, left, right)
              left++
              right--
     }
   }
   return left
}

function findPivot(arr, i, j) {
	return ((i + j ) / 2)
}

function quickSort(arr, left, right) {
   if (right <= left) {
		return
   }

   pivotIndex = findPivot(arr, left, right) 
   swap(array, pivotIndex, right)
   k = partition(array, left- 1, right, arr[right])
   swap(arr, k, right)
   quickSort(arr, left, k - 1)
   quickSort(arr, k + 1, right)
}
```
