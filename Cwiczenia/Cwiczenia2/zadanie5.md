# Zadanie 5

## Znachodzi najmniejsza liczbe
```
min(Tablica[], dlugosc){

    min = Tablica[0]
    i = 0
  
    while(i < dlugosc){
      if (Tablica[i] < min){
          min = Tablica[i]
      }
      i++
    }
    return min
}
```
## Znachodzi najwieksza liczbe
```
max(Tablica[], dlugosc){

    max = Tablica[0]
    i = 0
  
    while(i < dlugosc){
      if (Tablica[i] > max){
          max = Tablica[i]
      }
      i++
    }
    return max
}
```
