// Rafal Praitnickas. Student
// Lista dwuchkierunkowa niesortowana
// 2022-11-14
// czas 21:26
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  float value;
  struct Item *next;
  struct Item *prev;
} ItemType;

float find(float value, ItemType **head);

void insert(ItemType *head, float value);

void removeByElement(ItemType **head, ItemType *r);

int size(ItemType *head);

int findMax(ItemType **head);

int findMin(ItemType **head);

void printList(ItemType *head);

void isEmpty(ItemType *head);

void next(ItemType **head, float value);

void previuos(ItemType **head, float value);

void makeNull(ItemType **head);

int main(void) {

  ItemType *head = NULL;
  //relizacja funkcyji
  printf("Po uzyciu isEmpty ->");
  isEmpty(head);
  next(&head, 3.0);
  insert(head, 5.0);
  insert(head, 7.0);
  previuos(&head, 9.0);
  printList(head);
  printf("\n\nPo uzyciu isEmpty ->");
  isEmpty(head);
  removeByElement(&head, head);
  removeByElement(&head, head->next);

  printf("\n\nZmodyfikowana lista: \n");
  printList(head);
  float re = findMax(&head);
  printf("\n\nMaksymalny Element w liscie: %.1f \n\n", re);
  float rs = findMin(&head);
  printf("Minimalny Element w liscie: %.1f \n\n", rs);
  float search = 7.0;
  float rt = find(search, &head);
  printf("Liczba %.1f znachodzi sie na pozycji: %.f \n", search, rt);
  makeNull(&head);
  printf("\nPo uzyciu MakeNull -> \n");
  printList(head);

  return 0;
}

int size(ItemType *head) {
  int licznik = 0;
  if (head == NULL)
    return licznik;
  else {
    ItemType *licznik = head;

    do {
      licznik++;
      licznik = licznik->next;
    } while (licznik != NULL);
  }
  return licznik;
}
void printList(ItemType *head) {
  if (head == NULL) {
    printf("Lista jest pusta:\n");
  } else {
    ItemType *S;
    printf("\nKierunek do przodu: \n");
    while (head != NULL) {
      printf("%.1f \t", head->value);
      S = head;
      head = head->next;
    }
    printf("\nKierunek do tylu:\n");
    while (S != NULL) {
      printf("%.1f \t", S->value);
      S = S->prev;
    }
  }
}
void removeByElement(ItemType **head, ItemType *r) {

  if (*head == NULL || r == NULL) {
    return;
  }
  if (*head == r) {
    *head = r->next;
  }
  if (r->next != NULL) {
    r->next->prev = r->prev;
  }
  if (r->prev != NULL) {
    r->prev->next = r->next;
  }
  free(r);
  return;
}

void next(ItemType **head, float value) {

  ItemType *variable = (ItemType *)malloc(sizeof(ItemType));
  ItemType *koniec = *head;

  variable->value = value;
  variable->next = NULL;

  if (*head == NULL) {
    variable->prev = NULL;
    *head = variable;
    return;

    while (koniec->next != NULL)
      koniec = koniec->next;
    koniec->next = variable;
    variable->prev = koniec;

    return;
  }
}
void previuos(ItemType **head, float value) {

  ItemType *variable = (ItemType *)malloc(sizeof(ItemType));

  variable->value = value;
  variable->next = (*head);
  variable->prev = NULL;

  if ((*head) != NULL)
    (*head)->prev = variable;
  (*head) = variable;
}
void insert(ItemType *head, float value) {

  if (head == NULL) {
    printf("Dany wezel nie moze byc NULLem:");
    return;
  }
  ItemType *variable = (ItemType *)malloc(sizeof(ItemType));

  variable->value = value;
  variable->next = head->next;
  head->next = variable;
  variable->prev = head;

  if (variable->next != NULL) {
    variable->next->prev = variable;
  }
}

void isEmpty(ItemType *head) {
  (head == NULL) ? printf("\nLista jest pusta: \n") : printf("\nLista nie jest pusta: \n");
  // zastosowalem question mark operator, czyli condition ? result_if_true : result_if_false
}
int findMax(ItemType **head) {

  ItemType *max, *tym; // tym - tymczasowy
  tym = max = *head;

  while (tym != NULL) {
    if (tym->value > max->value)
      max = tym;
    tym = tym->next;
  }
  return max->value;
}
int findMin(ItemType **head) {

  ItemType *min, *tym; // tym - tymczasowy
  tym = min = *head;

  while (tym != NULL) {
    if (tym->value < min->value)
      min = tym;
    tym = tym->next;
  }
  return min->value;
}
float find(float value, ItemType **head) {

  ItemType *tym = *head;
  int position = 0;

  while (tym->value != value && tym->next != NULL) {
    position++;
    tym = tym->next;
  }
  if (tym->value != value)
    return -1;
  return (position + 1);
}
void makeNull(ItemType **head) {
  ItemType *tym = NULL;

  while (*head != NULL) {
    tym = (*head)->next;
    free(*head);
    *head = tym;
  }
}
