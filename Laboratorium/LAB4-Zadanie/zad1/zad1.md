# Pseudokod funkcyji
```
funX(n, a){
  if(pow(2, a-1) <= n && n < pow(2, a) && n>1)
  {
    return funX(n-1, a) + a
  }
  else{
    return 1
  }
}
```
