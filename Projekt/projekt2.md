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

Dalej porównujemy znak wzorca $p[bb]$ (oznaczamy na obrazku symbolem C) z znakiem $s[i]$ (symbol A),  
jeżeli wciąż mamy niezgodność, to cykl powtarzamy, aż dopóki wyczerpi nam prefiks-sufiks, czyli w takim  
wypadku okno wzroca oraz indeks i przesuwamy o jedną pozycję w prawo. Jeśli będzi pozytywna zgodność, to  
pasujący prefiks zwiększamy do długość o znak 1 i przesuwamy znak na tej pozycji co został już wykorzystany  
przez algorytmem MP.  

Jeśli prefiks obejmie cały wzorzec $(b = |s|), to szukana zostanie pozycja wzorca w $s$ i będzie  
równa $i - b + 1$. W przeciwnym razie poszukiwania kontyjumjemy. 

#### Wejście: 

s - łańcuch znakowy
p - poszukiwany wzorzec

#### Wyjście:

Kolejna pozycja wystąpienia wzorca w łańcuchu o wartości -1 nie  
wskazuje żadnej pozycji wzorca i oznacza, iż wzorzec nie wystepuje  
w przeszukiwanym łańcuchu.  

#### Zmienne pomocnicze:  

pp - zawiera wyznaczenia pozycje wzorca, czyli $pp \in C$  
i - pozycja porównowanego znaku w łańcuchu tekstowym s, czyli $i \in N, 0 \leq i \leq |s|$  
b - długość prefiksu wzorca p  pasującego do prefiksu okna wzorca w łańcuchu s, $b \in N, 0 \leq b \leq |p|$  
$\prod$ - tablica o indeksach od 0 do |p|, przechuwująca długości maksymalnych prefiksów-sufiksów kolejnych  
prefiksów wzorca p, $\prod \in C$  

#### Lista kroków

<img width="279" alt="image" src="https://user-images.githubusercontent.com/115026306/216113261-b3251d13-617f-435d-9b3c-cea21e9545e3.png">

```
Krok1:        wyznaczamy tablicę maksymalnych prefikso-sufiksów  
Krok2:        wstępna pozycja wzorca ustawiona na -1  
Krok3:        wstępną długość prefikso-sufiksu ustawiamy na 0  
Krok4:        pętla wyznacza znaki łańcucha do porównania ze znakami wzorca  
Krok5:        zukamy we wzorcu p rozszerzalnego prefiksu pasującego do prefiksu  
              okna wzorca. Pętlę K05 przerywamy, jeśli znajdziemy rozszerzalny  
              prefiks lub napotkamy wartownika -1  
Krok6:        Rozszerzamy prefiks o 1 znak. Jeśli prefiks był wartownikiem, to  
              otrzymuje wartość 0.
Krok7:        Jeśli prefiks nie obejmuje całego wzorca, to kontynuujemy pętlę K04, 
              czyli porównujemy znak p [ b ] z kolejnym znakiem łańcucha s.  
Krok8:        wyznaczamy pozycję wzorca p w łańcuchu s  
Krok9:        wyprowadzamy tę pozycję  
Krok10:       redukujemy b do długości prefikso-sufiksu wzorca  
Krok11:       jeśli wzorzec p nie występuje w s, wyprowadzamy -1  
Krok12:       Zakończ
```


## Pseudokod
```
MorissPratta(){
 s, p
 M = 79
 N = 5
 PI [M + 1], i, b, pp
 PI [0] = b = -1
 for( i = 1; i <= M; i++ )
 {
       while( ( b > -1) && ( p [b] != p [i - PI] = ++b
 }
 wypisujemy(p)
 wypisujemy(s)
 pp = b = 0
 for( i = 0; i < N; i++ ){
       while( ( b > -1 ) && ( p [b] != s [i] ) ) b = PI [b]
       if ( ++b == M )
       {
             while ( pp < i - b + 1)
             {
             wypisujemy("")
             pp++
             }
             wypisujemy("^")
             pp++
             b = PI[b]
       }
  }
  wypisujemy(\n)
  zakończ
}

```
#### Program w C języku  
[-klikni żeby zobaczyć](https://github.com/Praitnickas-Rafal/Algorytmy_i_struktury/commit/210b15c3a1b131256caa27cc0cda9de8ebc43ab9)

## Złożoność obliczeniowa algorytmu

Złożoność obliczeniowa algorytmu określa, jak wydajny jest algorytm,    
ile musi on wykonać oprecaji w zależności ilości danych oraz ile potrzebuje pamięci.  
Złożoność obliczeniową dzielimy na złożoność pamięciową oraz złożoność czasową.   
Ale do wymagań które są do algorytmu, to będziemy wykorzystowali złożoność czasową.    

#### Złożoność czasową

W naszym wypadku algorytm działa $O(n + m)$, gdzie n jest długością poszukiwanego    
łańcucha, a m jest długością poszukiwanego wzorca.  

## Poprawność całkowita

Program jest częsciowy poprawny, program wyszukiwanie wzorca algorytmem Morrisa-Pratta,     
ma wszystkie punkty, który musi mięć prawidłowy algorytm, czyli jednoznaczność (Każdy z  
jego kroków, a także dane wejściowe/wyjściowe muszą być jasne i dawać tylko jedną wartość.)   
Dane wejściowe - czyli ma dobrze zdefiniowane dane wejściowe. Są wyjście, na KROKU12 program  
zakończyć się po skończonej liczbie kroków. Wykonalność i niezależność, czyli podsomuwując  
program działa.

#### Przejdź do Projektu trzyciego [(-klikni żeby zobaczyć)](https://github.com/Praitnickas-Rafal/Algorytmy_i_struktury/blob/main/Projekt/projekt2.md)
