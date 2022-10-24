# Zadanie czwarte
## Srednia pseudokod
```
Obliczenia_srednej(n, tab){
  suma = 0
  i = 0

  while (i < n){
    suma += tab[i]
    i++
  }
  srednia = tab[i] / n
  return srednia
}
```
## Udowodnienie
```
załóżmy że, mami trzy różne liczby, których średnia arytmetyczna jest równa 4, oraz dwie inne liczby, których
średnia jest równa 2, uzasadnim, że średnia arytmetyczna zestawu tych pięciu liczb jest równa 3,2 to znaczy dla
sumy całej średniej arytmetycznej zostani podzielona przez ona 5
```
```
Założenie:
```
<img width="96" alt="image" src="https://user-images.githubusercontent.com/115026306/197415714-06384bf0-47e8-4f39-84bf-fde23b972e92.png">

```
wprowadziłyśmy x, y, z i zostało podzielona przez 3, bo są trzy niewiadome
```

<img width="131" alt="image" src="https://user-images.githubusercontent.com/115026306/197415884-4af7290d-27a1-4961-a550-2966023a0e42.png">

```
wprowadziłyśmy r, w i zostało podzielona przez 2, bo są dwa niewiadome
```
<img width="167" alt="image" src="https://user-images.githubusercontent.com/115026306/197416590-6ec36f99-999d-45a0-a801-a3d8e8dc5104.png">

```
upożądkowaliśmy założenie
```
```
Teza:
```

<img width="253" alt="image" src="https://user-images.githubusercontent.com/115026306/197416421-09986580-93bb-4de9-a8b3-e599afb15b79.png">

```
Dowód:
```
<img width="417" alt="image" src="https://user-images.githubusercontent.com/115026306/197416501-55472261-c539-4a9f-ba61-ca7c78ebd5a0.png">

```
Za pomoca założenie my podstowujemy 12 i 4 i obliczamy
```

```
Stąd wychodzi że prawa strona jest równa lewa, i może stego zrozumieć że algorytm jest całkowicie 
poprawny za pomoca założenia matematycznej
```




