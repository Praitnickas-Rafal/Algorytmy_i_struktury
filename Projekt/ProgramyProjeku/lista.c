// Wykonał: Rafal Praitnickas, Student
// Data 2023-02-01
// Program poprawnie działa
#include <stdio.h>
#include <stdlib.h>

float max_size; 

typedef struct Item {
  float value;
  struct Item *next;
} ItemType;

int pop(ItemType **head); /// dobawil 

int push(ItemType **head, float valueS); /// dobawil  

void printlist(ItemType *head); // dobawil (pomocnicza)

int main(void) {

  max_size = 8.0; 

  if (max_size <= 0) {
    return 1;
  }
  ItemType *head;
  head = NULL;

  printf("\n Lista przed Scieraniem Elementu: \n");
  push(&head, 5.0);
  push(&head, 6.0);
  push(&head, 7.0);
  push(&head, 4.0);
  push(&head, 9.0);
  printlist(head);
   printf("\n Lista po Scieraniem Elementu: \n");
  pop(&head);
  printlist(head);
  return 0;
}

// size funkcyja (pomocnicza)

int size(ItemType *head) {

  int licznik = 0;
  ItemType *sNew = head;

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

int push(ItemType **head, float valueS) {
  if (size(*head) == max_size) {
    printf("\n uwaga, overfloat:\n");
    return 1;
  }
  if (*head == NULL) {

    *head = (ItemType *)malloc(sizeof(ItemType));
    (*head)->value = valueS;
    (*head)->next = NULL;
  } else {
    ItemType *newElement;

    newElement = (ItemType *)malloc(sizeof(ItemType));
    newElement->value = valueS;
    newElement->next = *head;
    *head = newElement;
  }
  }


// pop funkcyja

int pop(ItemType **head) {
  if (*head == NULL) {
    printf("\n Nie ma co usunąć.");
  } else {
    ItemType *tym = NULL;
    tym = (*head)->next;
    free(*head);
    *head = tym;
  }
}
