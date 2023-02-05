# Pseudokod Swap
```
swap( *x, *y)
{
  tymczasowa
  tymczasowa = *x
  *x = *y
  *y = tymczasowa
}
// x, y - zmienne
```
# Pseudokod do Permutacji
```
permute( *a, b, x){
  i
  if (b == x)
  drukuj(a)
  else {
  for (i = b; i <= x; i++;){
      swap((a + b), (a + i))
      permute(a, b + 1, x)
      swap((a + b), (a + i))
      }
  }
}
// a - Ciąg, b - Początkowy indeks łańcucha, x - Indeks końcowy łańcucha 
```
# Pseudokod Convert
```
 convert(number){
 binary = 0
 i = 0
   while(number !=0){
       momento = number % 2
       binary += momento * pow(10, i)
       number /= 2
       i++
   }
   return binary
 }
//number to cyfra która zostaje konvertowana, wyjście binary
```
# Pseudokod Greya
```
Greya(bity){

  gray, top
  top = pow(2, bity) - 1
  
  for (i = 0; i <= top; i++){
      gray = i ^ (i >> 1)
      drukuj(convert(gray))
  }
}
```
