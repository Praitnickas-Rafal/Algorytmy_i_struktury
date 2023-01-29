# Algorytm wyszukiwania liczb niepodzielnych przez zadane liczby

## Praca wykonał [Rafal Praitnickas](https://github.com/Praitnickas-Rafal/)

### Projekt do przedmiotu "Algorytmy i truktury danych"
### UwB Wydział Ekonomiczno-Informatyczny w Wilnie

### Data: 2023.01.29

- [Zadanie](#zadanie)
- [Chciwy algorytm](#chciwy)
- [Algorytm śledzenia wstecznego](#algorytm)

## Zadanie

Żeby rozwiązać zadanie i napisać program, musimy wziąść przykładowy zadanie, co trzeba do tego i jaka jest podstawową ideja programu.

## Przekłady

## Pomocnicze

Przekłodowa metoda jest metoda brutalna polega na tym że wszystkie wartości przechodzą w danym przedziale liczbowym i sprawdzeniu każdej z nich, czy spełnia wymagane warunki. Jeśli odpowiedz pozytywna, to znaleziona liczba jest przekazywana na wyjście.

Wejście: 

C - całkowitych liczby
a - początek przedziału, a należy do C
b - koniec przedziału, b należy do C, a < b

Wyjście:

Liczby z przedziału [a, b], które spełniają zadane warunek

Pomocnicze:

i - kolejne liczby w przedziałe [a, b], i nałeży do C
```
Lista kroków:

Krok1: Dla i = a, a + 1, ..., b:
       wykonuj:
        Jeśli i spełnia warunek,
        to pisz i
Krok2: Zakończ
```
## Chciwy algorytm

## Pseudokod


