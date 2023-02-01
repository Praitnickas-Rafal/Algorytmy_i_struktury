# Algorytm Morrisa-Pratta wyszukiwania wzorca

## Praca wykonał [Rafal Praitnickas](https://github.com/Praitnickas-Rafal/)

### Projekt do przedmiotu "Algorytmy i truktury danych"
### UwB Wydział Ekonomiczno-Informatyczny w Wilnie

### Data: 2023.02.01

- [Zadanie](#zadanie)
- [Rozwiązanie](#rozwiązanie)
- [Pseudokod](#pseudokod)
- [Żłożoność obliczeniowa algorytmu](#złożoność_obliczeniowa_algorytmu)
- [Poprawność całkowita](#poprawnoś_ćcałkowita)

## Zadanie

Żeby rozwiązać zadanie i napisać program, musimy wziąść przykładowy zadanie,  
co trzeba do tego żeby rozwiązać i jaka jest podstawową ideja programu.

#### Problem:

W łańcuchu s należy wyznaczyć wszystkie wystąpienia wzorca p.  

## Przykład

Algorytm wykorzystuje fakt, że w przypadku wystąpienia niezgodności   
ze wzorcem, sam wzorzec zawiera w sobie informację pozwalającą   
określić, gdzie powinna się  zacząć kolejna próba dopasowania,  
pomijając ponowne porównywanie już dopasowaanych znaków. Dzięki  
temu właściwy algorytm działa w okresie liniowym względem długości  
przeszukiwanego tekstu i wzroca. 

## Opisanie rozwiązania

Zadanie znajdowania wzorca w łańcuchu rozwiązuje algorytm opracowany przez J. H.  
Morrisa i V.R. Pratta w 1997. W algorytmie Morrisa-Pratta (w dalniejszym opisaniu    
będa używał skrócenie MP) wykorzystuje się tablicę $/prod$, czyli jest to wyszukiwania  
maksymalnego prefiksa-sufiksa.  

Załóżmy, że szukamy pierwszego wystąpienie wzorca, czyli $p$ w danym łańcuchu tekstowym $s$.  
W procesie porównywania kolejnych znaków łańcucha ze znakami wzorca, trafialiśmy na  
sytuację, w której prefiks wzorca $p$, o długości $b$ znaków, pasowało do profiksu okna w    
łańcuchu s przez pozycją $i-tą$, jednak znak $s[i]$ oznaczony na rysunku symbolem A) różni  
się od znaku $p[b]$ (oznaczonym symbolem B), który znajduje się we wzorcu tuż za pasującym      
prefiksem.  

<img width="506" alt="image" src="https://user-images.githubusercontent.com/115026306/216096326-a036c6d3-b5f1-46ff-a170-a1e54e733918.png">

Algorytm w takiej sytuacji przesuwa okno wzroca o jdeną pozcję w prawo względem przeszukiwanego  
tekstu i zaczyna od początku porównywanie znaków wzorca $p$ ze znakami okna nie korzystając  
zupełnie z faktu zgodności części znaków, czyli okazuje się iż wykorzystując fakt istnienia  
pasującego nam prefiksu, możemy pominąc pewne porównania znaków bez żadnej szkody na wyniku  
wyszukiwań. Dlatego po stwierdzeniu niezgodności okno wzorca przesuwamy, tak aby przed znakiem $s[i]$  
znalazł się maksymalny prefiks-sufiks wzorca p:

<img width="542" alt="image" src="https://user-images.githubusercontent.com/115026306/216100496-2d935525-dc0b-4097-a500-6a6e46046565.png">

Dzięki tej możliwości my pomijamy niepotrzebne porównania znaków oraz unikamy cofania się indeksu $i$  

Każdy prefiks wzorca szerokość maksymalnego prefiksu-sufiksu można wyznaczyć przed rozpoczęciem  
szukiwania - do tego właśnie celu generujemy tablicę $\prod$. Danej dlugości prefiksu $b$ możemy  
z tej tablicy odczytać szerokość maksymalnego prefikso-sufiksu tego prefiksu, czyli w naszym wypadku  
będzie to: $bb=\prod [b]$


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
#### Program w C języku  
[-klikni żeby zobaczyć](https://github.com/Praitnickas-Rafal/Algorytmy_i_struktury/blob/main/Projekt/ProgramyProjeku/Algorytm.c)

## Złożoność obliczeniowa algorytmu

Złożoność obliczeniowa algorytmu określa, jak wydajny jest algorytm,  
ile musi on wykonać oprecaji w zależności ilości danych oraz ile potrzebuje pamięci.
Złożoność obliczeniową dzielimy na złożoność pamięciową oraz złożoność czasową. 
Ale do wymagań które są do algorytmu, to będziemy wykorzystowali złożoność czasową.  

#### Złożoność czasową

W naszym wypadku algorytm ma złożoność kwadratowa, czyli $O(n^{2})$, gdy dla danych  
wejściowych o rozmiarze n liczba operacji w zależności od liczby elementów będzie wyrażona  
wzorcem funkcji kwadratowej: $f(n)=an^{2}+bn+c$  

Gdy analizujemy przedstawiony przez mnie algorytm to możemy zauważyć, że program składa się  
z dwóch pętli zagnieżdżonych (pętla w pętli), a każda z nich będzie miała liniową złożoność.  

## Poprawność całkowita

Program jest częsciowy poprawny, ponieważ program znachodzi liczby niepodzielne przez dane liczby,    
to możemy zobaczyć w pseudokodzie, gdzie jest pętla, jeśli jakiś dzielnik dzieli X to przechodzimy  
do następnej liczby, w przyciwnym wypadku jeżeli żaden dzielnik nie dzieli X to wyprowadzamy je,     
czyli program ma wejście i wyjście co jego robi częsciowo poprawny, ma także zastonowienie się, czyli    
przedział [a, b] mają rol zastonawianie się programu, czyli ustaliamy granicy programu.  

#### Przejdź do Projektu drugiego [(-klikni żeby zobaczyć)](https://github.com/Praitnickas-Rafal/Algorytmy_i_struktury/blob/main/Projekt/projekt2.md)
