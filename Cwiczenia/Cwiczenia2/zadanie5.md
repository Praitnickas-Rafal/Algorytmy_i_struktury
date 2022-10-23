# Zadanie piąte

## Minimalny pseudokod
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
## Udowodnienie

<img width="537" alt="image" src="https://user-images.githubusercontent.com/115026306/197417686-29492021-4cb8-47f8-af0b-193cc9e2b4d1.png">

<img width="728" alt="image" src="https://user-images.githubusercontent.com/115026306/197417318-801235aa-611f-4e3f-848b-f6fee26c7338.png">

```
Stąd wychodzi że algorytm  jest całkowicie poprawny za pomoca zasady Minimum
```

## Maxsimalny pseudokod

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
## Udowodnienie

<img width="571" alt="image" src="https://user-images.githubusercontent.com/115026306/197417897-cbf2519c-e2e6-4488-8484-b1b756e218f6.png">

<img width="859" alt="image" src="https://user-images.githubusercontent.com/115026306/197417930-e26c0888-7176-4f1c-b766-fb57f29b6d7f.png">


```
Stąd wychodzi że algorytm  jest całkowicie poprawny za pomoca zasadów Minimum, indukcji zupełnej, 
indukcji matematycznej i oczywiście samej zasady maksimum.
```



