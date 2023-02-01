# Algorytm usuwania elementu z początku listy jednokierunkowej

## Praca wykonał [Rafal Praitnickas](https://github.com/Praitnickas-Rafal/)

### Projekt do przedmiotu "Algorytmy i truktury danych"
### UwB Wydział Ekonomiczno-Informatyczny w Wilnie

### Data: 2023.02.01

- [Zadanie](#zadanie)
- [Rozwiązanie](#rozwiązanie)
- [Pseudokod](#pseudokod)
- [Żłożoność obliczeniowa algorytmu](#złożonośćobliczeniowaalgorytmu)
- [Poprawność całkowita](#poprawnośćcałkowita)

## Zadanie

Żeby rozwiązać zadanie i napisać program, musimy wziąść przykładowy zadanie,  
co trzeba do tego żeby rozwiązać zadanie i jaka jest podstawową ideja programu.

## Przykład

Załóżmy, iż mamy daną listę jednokierunkową. Naszym zadaniem jest dodanie nowego 
elementu na początku tej listy. Tworzymy dynamicznie w pamięci nowy element listy. 
Wprowadzamy do niego dane. W polu next nowego elementu umieszczamy adres przechowywany 
przez zmienną head. W ten sposób następnikiem nowego elementu stanie się obecny pierwszy 
element listy. W zmiennej head umieszczamy adres nowego elementu. Po tej operacji początkiem   
listy staje się nowy stworzony element. Podsumowując sen jest taki samy, tylko zadanie prosi o  
niedodawaniu elementu na początek listy, a usunięciu jego.

## Opisanie rozwiązanie

Lista jednokierunkowa w odróżnieniu od tablicy jest rozrzucona po pamięci aplikacji.  
Jej elementy nie występują kolejno po sobie. Element poprzedni wskazuje na element  
następny. Dlatego tak ważne jest przypisywanie odpowiednich wskaźników (pointery)  
do nowych elementów. Uwaga i druga, jeżeli usuwamy pierwszy element (głowa/head) -  
wystarczy ustawić nowy początek list jednokierunkowej z elementu $n$ na $n+1$, co w  
naszym wypadku jest potrzebne.  

Jeśli lista jednokierunkowa jest pusta, to nic nie zrobimy, czyli nie ma co usunuć.    
Załóżmy, że mamy daną listę jednokierunkową która ma zapełnioną liste (w końcu musimy   
będziemy zaimplementować taką funkcje dodawanie, ponieważ bez tego program prawidłowo  
nie będzi działać), z której początku należy usunąć element zaznaczony na rysunku kolorem  
czerwonym.

<img width="309" alt="image" src="https://user-images.githubusercontent.com/115026306/216159397-40787112-52ac-4b91-9ea9-8b8ee3fd36e9.png">

W zmiennej head umieszczamy zawartość pola next usuwanego elementu. W ten sposób początek  
listy jednokierunkowej rozpocznie się w następniku (next), a usuwany element zostanie wyżucony  z listy jednokierunkowej:

<img width="308" alt="image" src="https://user-images.githubusercontent.com/115026306/216159831-a870d2e7-162d-447f-b81b-c6383171d16f.png">

Trzecim krokiem będzi wyżucony albo może odłączony element usuwamy z pamięci listy.  

<img width="308" alt="image" src="https://user-images.githubusercontent.com/115026306/216160142-033db903-51ff-4d38-9b2d-1ea8edbcc4e2.png">

Final otrzymujemy listę bez pierwszego elementu, czy pierwszy został usunięty z  
listy jednokierunkowej.  


#### Wejście: 

head - zmienna wskazująca na początek listy jednokierunkowej.

#### Wyjście:

Otrzymujemy listą jednokierunkową bez pierwszego elementu.

Zmienne pomocnicze:  

p - wskazanie elementu listy

#### Lista kroków
```
Krok1: p <- head

Krok2: Jeśli p = nil (NULL)

Krok3: head <- (p -> next)

Krok4: Usuń z pamięci element wskazany przez p

Krok5: Zakończ program
```

#### Krótki opis

Zapamiętaj pierwszy element, zakończ jeśli jest pusta, początkiem listy  
element będzie następny ( $n + 1$ ) w listej jednokierunkowej.  

## Pseudokod
```
pop(Wezel **head) {
  if (*head == NULL) {
    drukuj(Nie ma co usunąć.)
  } else {
    Wezel *tym = NULL
    tym = (*head)->next;
    free(*head)
    *head = tym
  }
  zakończ
}
```
#### Program w C języku  
[-klikni żeby zobaczyć](https://github.com/Praitnickas-Rafal/Algorytmy_i_struktury/blob/main/Projekt/ProgramyProjeku/lista.c)

## Złożoność obliczeniowa algorytmu

Złożoność obliczeniowa algorytmu określa, jak wydajny jest algorytm, 
ile musi on wykonać oprecaji w zależności ilości danych oraz ile potrzebuje pamięci.
Złożoność obliczeniową dzielimy na złożoność pamięciową oraz złożoność czasową. 
Ale do wymagań które są do algorytmu, to będziemy wykorzystowali złożoność czasową.  

#### Złożoność czasową

W naszym przypadku tej implementacji usunięcie elementu z początku listy ma złożoność Ο(1),  
czyli stała (od jednego do kilku operacji).  

Złożoność stała, niezależna od liczby danych wejściowych. Mówimy, że problem o złożoności Ο(1) 
możemy rozwiązać w stałym czasie niezależnie od wielkości danych wejściowych. Przykład problemu, 
dla którego istnieje algorytm Ο(1)  

Podsumowując program jest bardzej wydajny, iż mniejsza złożoność algorytmu, tym jest on bardziej wydajny.

## Poprawność całkowita

Program jest częsciowy poprawny, algorytm usuwania elementu z początku listy jednokierunkowej  
ma wszystkie punkty, który musi mięć prawidłowy algorytm, czyli jednoznaczność (Każdy z
jego kroków, a także dane wejściowe/wyjściowe mają jasne i dają tylko jedną wartość.)
Dane wejściowe - czyli ma dobrze zdefiniowane dane wejściowe. Są wyjście, na KROKU5 program
zakończyć się po skończonej liczbie kroków. Wykonalność i niezależność, jest wydajny ponieważ 
złożoność jest stała i przy kompiliowaniu program pięknie działa i wypełnia swoją misję, czyli  
usuwa element początkowy z list jednokierunkowej. 

#### Przejdź do Projektu pierwszego [(-klikni żeby zobaczyć)](https://github.com/Praitnickas-Rafal/Algorytmy_i_struktury/blob/main/Projekt/projekt1.md)

## Literatura i Źródła

#### Projekt 1

- [Algorytmy i Struktury Dane](https://eduinf.waw.pl/inf/alg/001_search/0004.php)
- [Algorytmy i Struktury Dane (Książka)](https://helion.pl/ksiazki/algorytmy-i-struktury-danych-lech-banachowski-wojciech-rytter-krzysztof-maria,e_0xyu.htm#format/e)
- [Wikipedia](https://pl.wikipedia.org/wiki/Dzielnik)

#### Projekt 2

- [Algorytmy i Struktury Dane (Książka)](https://helion.pl/ksiazki/algorytmy-i-struktury-danych-lech-banachowski-wojciech-rytter-krzysztof-maria,e_0xyu.htm#format/e)
- [Wikipedia](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)
- [Złożoność obliczeniowa](https://www.algorytm.edu.pl/matura-informatyka/zlozonosc-algorytmu)

#### Projekt 3
- [Prezetacja](http://staff.iiar.pwr.wroc.pl/wojciech.bozejko/elearning/Wyk3_listy.pdf)
- [Algorytmy i Struktury Dane (Książka)](https://helion.pl/ksiazki/algorytmy-i-struktury-danych-lech-banachowski-wojciech-rytter-krzysztof-maria,e_0xyu.htm#format/e)

#### Ogólna

- [Github](https://github.com/)
- [Replit](https://replit.com/~)
- [VU Biblioteka](https://biblioteka.vu.lt/)
