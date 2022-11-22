# Pseudokod ciągu geometrycznego
```
geo(n, q, a){
 if (n == 1){ 
  return a
 }
 else{
  return geo(n-1, q, a) * q
 }
}
```
