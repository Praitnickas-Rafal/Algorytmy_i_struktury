// Rafal Praitnickas. Student
// Lista jednokierunkowa niesortowana
// 2022-10-24
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  float value;
  struct Item *next;
} ItemType;

int find(float value, int *head);

int locate(float value, int *head); //??

int retrieve(ItemType *item, int *head);

void insert(ItemType **head, float value, int cyfra,
            int position); // zmieniłem i dobawiłem

void remove1(ItemType **head,
             int position); // zmieniłem ItemType *head na int position i do
                            // headu dobawiłem jeszcze jeden pointer

int size(ItemType *head); // zmieniłem int na ItemType

ItemType findMax(int *head);

ItemType findMin(int *head);

void printList(int *head); // zmieniłem na void

int isEmpty(int *head);

void next(ItemType **head,
          int cyfra); //?? next co?? czyli na koniec dodaj element? zmieniłem
                      //ItemType *head na int cyfra i do headu dobawiłem jeszcze
                      //jeden pointer

void previous(ItemType **head,
              float value); // zmieniłem ItemType *head na float value i do headu
                          // dobawiłem jeszcze jeden pointer

int makeNull(int *head);

int main(void) {

  ItemType *head;
  head = (ItemType *)malloc(sizeof(ItemType));
  head = NULL;

  printList(head);
  previous(&head, 6);
  printList(head);
  previous(&head, 5);

  return 0;
}

int size(ItemType *head) {
  int counter = 0;
  if (head == NULL)
    return counter;
  else {
    ItemType *current = head;
    do {
      counter++;
      current = current->next;
    } while (current != NULL);
  }
  return counter; // test
}

void printList(int *head) {
  printf("\n");
  if (head == NULL) {
    printf("List is empty");
  } else {
    ItemType *current = head;
    do {
      printf("%f", current->value);
      printf("\n");
      current = current->next;
    } while (current != NULL);
  }
}
void remove1(ItemType **head, int position) {
  if (position == 0) {
    ItemType *tmp = NULL;

    if (*head != NULL) {
      tmp = (*head)->next;
      free(*head);
      *head = tmp;
    } else {
      ItemType *current = *head;
      ItemType *tmp;
      int i = 0;

      while (current->next != NULL && i < position - 1) {
        current = current->next;
        i++;
      }
      tmp = current->next;
      current->next = tmp->next;
      free(tmp);
    }
  }
}
void previous(ItemType **head, float value) {

  ItemType *current;
  current = (ItemType *)malloc(sizeof(ItemType));

  current->value = value;
  current->next = *head;
  *head = current;
}
void next(ItemType **head, int cyfra) {

  if (*head == NULL) {
    *head = (ItemType *)malloc(sizeof(ItemType));
    (*head)->value = cyfra;
    (*head)->next = NULL;
  } else {
    ItemType *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = (ItemType *)malloc(sizeof(ItemType));
    current->next->value = cyfra;
    current->next->next = NULL;
  }
}

void insert(ItemType **head, float value, int cyfra, int position) {
  if (position == 0)
    previous(head, cyfra);
  else {
    if (position == size(*head))
      next(head, cyfra);
    else {
      ItemType *current = *head;
      ItemType *tmp;

      int i = 0;
      while (current->next != NULL && i < position - 1) {
        current = current->next;
        i++;
      }

      tmp = current->next;
      current->next = (ItemType *)malloc(sizeof(ItemType));
      current->next->value = cyfra;
      current->next->next = tmp;
    }
  }
}
