# Zadanie trzecie
## Pseudokod NWD
```
NWD(a, b)
{
  dzielnik = 0
  while (liczba2 != 0)
        {
        r = b
        b = a % b
        a = b
        }
  return b
}
```
# Udowodnienie
## udowodnienie za pomoca algorytmu Euklidesa
```
1. Wczytaj liczby a,b>0.
2. Oblicz r jako resztę z dzielenia a przez b.
3. Zastąp a przez b, zaś  b przez r.
4. Jeżeli  b=0 to zwróć a w przeciwnym wypadku przejdz do 2 punktu.
```
<img width="508" alt="image" src="https://user-images.githubusercontent.com/115026306/197414660-62ba7ad0-9f49-44f0-860d-937b57a3f804.png">

<img width="327" alt="image" src="https://user-images.githubusercontent.com/115026306/197414679-cb63f947-d62f-450d-8a87-d8274bdb531b.png">

```
Stąd wychodzi że algorytm jest całkowicie poprawny za pomoca algorytmu Euklidesa
```
