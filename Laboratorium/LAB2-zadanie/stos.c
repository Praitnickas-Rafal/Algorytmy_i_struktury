// Rafal Praitnickas. student
// Stos
// 2022-11-12
// czas 18:38
#include <stdio.h>
#include <stdlib.h>

float max_size; // dla rozmiaru stosu

typedef struct Item {
  float value;
  struct Item *next;
} ItemType;

void top1(ItemType *top); // dobawil 

void makeNull(ItemType **top); // dobawil 

int pop(ItemType **top); /// dobawil 

int push(ItemType **top, float valueS); /// dobawil 

void isEmpty(ItemType *top); /// dobawil 

void printlist(ItemType *top); // dobawil (pomocnicza)

int main(void) {

  max_size = 8.0; // maksymalny rozmiar stosu

  if (max_size <= 0) {
    return 1;
  }
  ItemType *top;
  top = NULL;

  isEmpty(top);

  printf("\n Stos przed Scieraniem Elementu: \n");
  push(&top, 5.0);
  push(&top, 6.0);
  push(&top, 7.0);
  push(&top, 4.0);
  push(&top, 9.0);

  printlist(top);

  pop(&top);

  printf("\n Stos po Scieraniu Elementu: \n");

  printlist(top);
  top1(top);

  isEmpty(top);

  makeNull(&top);

  printf("\nPo uczyciu MakeNULL ->");

  printlist(top);
  return 0;
}

// size funkcyja (pomocnicza)

int size(ItemType *top) {

  int licznik = 0;
  ItemType *sNew = top;

  while (sNew != NULL) {

    licznik++;
    sNew = sNew->next;
  }
}

// printlist funkcyja (pomocnicza)

void printlist(ItemType *top) {

  printf("\n");

  if (top == NULL) {
    printf("Stos jest Pusty: \n");
  } else {
    ItemType *sNew = top;
    do {

      printf("%.1f", sNew->value);
      printf("\n");

      sNew = sNew->next;
    } while (sNew != NULL);
    printf("\n");
  }
}

// push funkcyja

int push(ItemType **top, float valueS) {
  if (size(*top) == max_size) {
    printf("\n Przepelnienie stosu, niewyjdzi dodac elementu. \n");
    return 1;
  }
  if (*top == NULL) {

    *top = (ItemType *)malloc(sizeof(ItemType));
    (*top)->value = valueS;
    (*top)->next = NULL;
  } else {
    ItemType *newElement;

    newElement = (ItemType *)malloc(sizeof(ItemType));
    newElement->value = valueS;
    newElement->next = *top;
    *top = newElement;
  }
}

// pop funkcyja

int pop(ItemType **top) {
  if (*top == NULL) {
    printf("\n Nie ma stosu, czyli nie masz co zdjac.");
  } else {
    ItemType *tym = NULL;
    tym = (*top)->next;
    free(*top);
    *top = tym;
  }
}

// empty funkcyja

void isEmpty(ItemType *top) {
  (top == NULL) ? printf("\n Stos jest pusty: \n")
                : printf("\n Stos nie jest pusty: \n");

  // zastosowalem question mark operator, czyli condition ? result_if_true : result_if_false
}

// top funkcyja

void top1(ItemType *top) {

  ItemType *sNew = top;

  float peek = sNew->value;
  printf("\n %.1f jest topem w stosie: \n", peek);
}

// MakeNULL funkcyja

void makeNull(ItemType **top) {
  ItemType *tym = NULL;

  while (*top != NULL) {
    tym = (*top)->next;
    free(*top);
    *top = tym;
  }
}
