// Rafal Praitnickas. Student
// Lista jednokierunkowa niesortowana
// 2022-10-24
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  float value;
  struct Item *next;
} ItemType;

int find(float value, ItemType *head);          // zmieniłem i dobawiłem

int locate(float value, int *head);         //???

int retrieve(ItemType *item, int *head);    //???

void insert(ItemType **head, float value, int position);   // zmieniłem i dobawiłem

void deleteElement(ItemType **head, int position);    // zmieniłem i dobawiłem
                                               
int size(ItemType *head);                       // zmieniłem int na ItemType

int findMax(ItemType **head);                   // zmieniłem i dobawiłem

int findMin(ItemType **head);                   // zmieniłem i dobawiłem

void printList(ItemType *head);                 // zmieniłem na void

int isEmpty(ItemType *head);                    // zmieniłem i dobawiłem

void next(ItemType **head, int cyfra);          // zmieniłem i dobawiłem                 

void previous(ItemType **head, float value);    // zmieniłem i dobawiłem

void makeNull(ItemType **head);                 // zmieniłem i dobawiłem

int main(void) {

  ItemType *head;
  head = (ItemType *)malloc(sizeof(ItemType));
  head = NULL;

  /*-----------------------------------------------------*/
  // sprawdzamy funkcyji previuos(head, number) i printlist()
  
  previous(&head, 6.0); 
  previous(&head, 5.0);
  previous(&head, 8.0);
  printList(head);

  /*-----------------------------------------------------*/
  // sprawdzamy funkcje size()

  int i = size(head); 
  printf("%d \n", i);

  /*-----------------------------------------------------*/
  // sprawdzamy funkcyje deleteElement(head, position)

  deleteElement(&head, 0); 
  printList(head);

  /*-----------------------------------------------------*/
  // sprawdzamy funkcyje next(head, number)

  next(&head, 5.0); 
  printList(head);

  /*-----------------------------------------------------*/
  // sprawdzamy funkcyje insert(head, number, position)

  insert(&head, -7.0, 1); 
  printList(head);

  /*-----------------------------------------------------*/
  // s - rezultat //sprawdzamy funkcyje isEmpty(head)

  int s = isEmpty(head); 

  if (s == 1) {
    printf("\n The list is not empty: \n");
  } else {
    printf("\n List is empty: \n");
  }

  /*-----------------------------------------------------*/
  // sprawdzamy funkcyje find(number, head)

  int index = find(5.0, head); 

  if (index == -1)
    printf("\n Item not found \n");
  else
    printf("\n Item found at position: %d \n", index + 1);

  /*-----------------------------------------------------*/
  // sprawdzamy funkcyje findMax(head)

  int max = findMax(&head); 
  printf("\n max: %d \n", max);

  /*-----------------------------------------------------*/
  // sprawdzamy funkcyje findMin(head)

  int min = findMin(&head); 
  printf("\n min: %d \n", min);

  /*-----------------------------------------------------*/
  // sprawdzamy funkcyje makeNull(head)

  makeNull(&head);        

  /*-----------------------------------------------------*/

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
  return counter; 
}

void printList(ItemType *head) {
  printf("\n");
  if (head == NULL) {
    printf("List is empty");
  } else {
    ItemType *current = head;
    do {
      printf("%.f", current->value);
      printf("\n");
      current = current->next;
    } while (current != NULL);
  }
}
void deleteElement(ItemType **head, int position) {
  if (position == 0) {
    ItemType *tmp = NULL;

    if (*head != NULL) {
      tmp = (*head)->next;
      free(*head);
      *head = tmp;
    }
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

void insert(ItemType **head, float value, int position) {
  if (position == 0)
    previous(head, value);
  else {
    if (position == size(*head))
      next(head, value);
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
      current->next->value = value; 
      current->next->next = tmp;
    }
  }
}

int isEmpty(ItemType *head) {
  if (head == NULL) {
    return 0;
  } else {
    return 1;
  }
}

int find(float value, ItemType *head) {
  ItemType *current = head;
  int index = 0;

  while (current != NULL) {
    if (current->value == value) {
      return index;
    }
    current = current->next;
    index++;
  }
  return -1;
}

int findMax(ItemType **head) {
  ItemType *current;
  int max;
  current = *head;
  max = current->value;

  while (current != NULL) {
    if (current->value > max) {
      max = current->value;
    }
    current = current->next;
  }
  return max;
}

int findMin(ItemType **head) {
  ItemType *current;
  int min;
  current = *head;
  min = current->value;

  while (current != NULL) {
    if (current->value < min) {
      min = current->value;
    }
    current = current->next;
  }
  return min;
}

void makeNull(ItemType **head)
{
  ItemType *temp = NULL;

  while (*head!=NULL){
      temp = (*head) -> next;
      free(*head);
      *head = temp;
    }
}
