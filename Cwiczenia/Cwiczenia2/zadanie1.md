# Zadanie pierwsze
## Factorial pseudokod
```
factorial(lic){  
  // lic - liczba
  i = 0
  silnia = 1 

  while ( i < lic ){
        silnia *= i
        i++
    }
    return silnia
}
```
# Udowodnienie factoriala
## Pętla
```
Q (warunek wstępny): i = 0 oraz silnia = 1
B (warunek zatrzymania): while ( i < lic)
S (ciało pętli): silnia *= i oraz i++
R (warunek końcowy): test_wzoru
Niezmiennik(i, silnia) = 0 =< i =< lic
```
## Wlasnosć stopu
```
- algorytm zatrzyma się, kiedy zajdzie i =< len - jest iteracja i oraz lic skończoną liczbą naturalną
- lic jest stała i skończoną liczbą naturalną - tak
- wartość zmiennej i rośnie o 1 każdej iteracji - tak
```
## Przypadek podstawowy
```
Udowdnimy że niezmiennik pętli jest prawdziwy po osiągnieciu pętli

1. Na starcie pętli i = 0 oraz silnia = 1
2. Niezmiennik(0, 1) = 0 =< 1 =< lic test_wzoru
3. Obydwa tych założenia są prawdziwe
```
# Krok indukcii

## Nieformalnie

```
Załóżmy, że niezmiennik i warunek zatrzymania są prawdziwe na końcu dowolnej iteracji.

- Na końcu dowolnej iteracji i niezmiennik będący prawdą oznacza, że iloczyn jest iloczynem 
pierwszych i elementów silnia.

- Po jeszcze jednej iteracji dodajemy silnia[i]  do sumy, dlatego suma staje się suma 
pierwszych i + 1 elementów silnia.

- Aby "naprawić to", musimy zwiększyć i o 1
- dokładnie to robi pętla
- więc niezmiennik pętli pozostaje prawdziwy
```
## Formalnie
```
Załóżmy, że niezmiennik i warunek zatrzymania są prawdziwe na końcu dowolnej iteracji.

Indeksu dolnego 0 używamy dla wartości przed iteracją, a 1 dla wartości po iteracji.

Zakładamy dwie rzeczy, niezmiennik i warunek zatrzymania przed pętlami


```
