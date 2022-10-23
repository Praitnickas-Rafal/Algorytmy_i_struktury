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

## indukcja matematyczna 

<img width="674" alt="image" src="https://user-images.githubusercontent.com/115026306/197411917-2c1d24eb-e4ea-4476-ac86-d62b28a6cc53.png">

<img width="674" alt="image" src="https://user-images.githubusercontent.com/115026306/197411930-d585e9d9-1223-400c-a267-676f0af42c6f.png">

<img width="673" alt="image" src="https://user-images.githubusercontent.com/115026306/197411969-bbf9cb36-ffad-4e10-936b-3f768d5704ee.png">

```
Stąd wychodzi że algorytm liczy cześciowo poprawnie i  jest całkowicie poprawny z udowodnienia przez matematyczna indukcji.
```

