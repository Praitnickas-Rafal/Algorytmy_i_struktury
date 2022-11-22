# Pseudokod Trojkąta Pascala
```
pascal(n , k){
  if(n == k || n == 0){
  return 1
  }
  else{
  return pascal(n-1, k-1) + pascal(n - 1, k)
  }
}
```
