# Algorytm wyszukiwania liczb niepodzielnych przez zadane liczby

## Praca wykonał [Rafal Praitnickas](https://github.com/Praitnickas-Rafal/)

### Projekt do przedmiotu "Algorytmy i truktury danych"
### UwB Wydział Ekonomiczno-Informatyczny w Wilnie

### Data: 2023.01.29

- [Zadanie](#zadanie)
- [Chciwy algorytm](#chciwy)
- [Algorytm śledzenia wstecznego](#algorytm)

## Zadanie

Żeby rozwiązać zadanie i napisać program, musimy wziąść przykładowy zadanie,  
co trzeba do tego i jaka jest podstawową ideja programu.

## Przykład

Przekłodowa metoda jest metoda brutalna polega na tym że wszystkie wartości   
przechodzą w danym przedziale liczbowym i sprawdzeniu każdej z nich, czy  
spełnia wymagane warunki. Jeśli odpowiedz pozytywna, to znaleziona liczba    
jest przekazywana na wyjście.  

Wejście:  

C - całkowitych liczby   
a - początek przedziału, a należy do   
b - koniec przedziału, b należy do C, a < b  

Wyjście:  

Liczby z przedziału [a, b], które spełniają zadane warunek  

Pomocnicze:

i - kolejne liczby w przedziałe [a, b], i nałeży do C

Tworzymy pętlę przechodzącą przez kolejne liczby w przedziale i wybierami  
kolejną liczbą, jeżeli program spełnie warunki to mówi zakończ.
```
Lista kroków:

Krok1: Dla i = a, a + 1, ..., b:
       wykonuj:
        Jeśli i spełnia warunek,
        to wypisz i
Krok2: Zakończ
```
## Rozwiązanie

Stosując rozwiązanie z przykładu przebiegamy przez kolejne liczby w przedziale [a, b].  
Sprawdzamy każdą liczbę na podzielność przez podzielniki z P ( P - podzielniki). Jeżeli  
któryś z nich dzieli liczbę, to przechodzimy do następnej liczby w przedziału [a, b],  
przeciwnym wypadku wyprowadzamy na wyjście, jeżeli żaden nie dzieli liczby.

#### Wejście: 

a - początek przedziału, a $\in C$  
b - koniec przedziału, b $\in C$  
n - liczba podzielników, n $\in N$  
P - tablica, której kolejne elementy są podzielnikami. P $\in C$

#### Wyjście:

Kolejne licby z przedziału [a, b] niepodzielne przez żaden z podzielników w tablicy P. 

Zmienne pomocnicze:  

X - przechodzi przez kolejne liczby w przedziale [a, b] X $\in C$   
index - przechodzi przez indeksy podzielników w tablicy P. index $\in N$.

#### Lista kroków
```
Krok1: pętla przebiegająca przez kolejne liczby z [a, b] 

Krok2: pętla która sprawdza podzielność przez dzielniki z P 

Krok3: jeśli jakiś dzielnik dzieli X to przechodzimy do następnej liczby, 
       w przyciwnym wypadku jeżeli żaden dzielnik nie dzieli X

Krok4: wyprowadzamy X

Krok5: Zakończ program 
```

## Pseudokod
```
Algorytm(){
       a, b, n   
       i = 0, j = 0  
       P[1000]
       bool t
       wprowadz(a, b, n)
       
       for( i; i < n; i++ )
          wprowadz(P[i])
       for( i=a; i<=b; i++ )
       { 
          t = true
          for( j; j < n; j++ )
              if( i % P[j] == 0 )
              {
                 t = false
                 break
              }
              if(t) wyprowadz(i)
       }
       zakończ
 }
```
####Program C języku
[-klikni żeby zobaczyć](https://github.com/Praitnickas-Rafal/Algorytmy_i_struktury/blob/main/Projekt/ProgramyProjeku/Algorytm.c)


