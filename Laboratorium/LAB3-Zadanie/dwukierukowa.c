// Rafal Praitnickas. Student
// Lista jednokierunkowa niesortowana
// 2022-10-24
//czas został dobawiony 23:27

typedef struct Item {
  float value;
  struct Item *next;
  struct Item *prev;
} ItemType;

float find(float value, ItemType *head);

ItemType locate(float value, ItemType *head); // pointer

float retrieve(ItemType *item); // wartosc

void insert(ItemType **head, float value, int position);

void removeByElement(ItemType **head, float value, int position);

int size(ItemType *head);

ItemType findMax(ItemType *head);

ItemType findMin(ItemType *head);

void printList(ItemType *head);

int isEmpty(ItemType *head);

void next(ItemType **head, float value);

void previuos(ItemType **head, float value);

void makeNull(ItemType *head);

#include <stdio.h>

void main(void) {
  // realizacja

  return;
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
  printf("\n");

  if (head == NULL)
    printf("Lista jest pusta: \n");
  else {
    ItemType *kr = head;
    do {
      printf("%f", kr->value);
      printf("\n");
      kr = kr->next;
    } while (kr != NULL);
  }
}
void removeByElement(ItemType **head, float value, int position) {

  if (position == 0) {
    if (*head == NULL) {
      *head = (ItemType *)malloc(sizeof(ItemType));
      (*head)->value = value;
      (*head)->prev = NULL;
      (*head)->next = NULL;
    } else {
      ItemType *kr;
      kr = (ItemType *)malloc(sizeof(ItemType));
      kr->value = value;
      kr->prev = NULL;
      kr->next = (*head);
      (*head)->prev = kr;
      *head = kr;
    }
  } else {
    if (position == size(*head)) {
      if (*head == NULL) {
        *head = (ItemType *)malloc(sizeof(ItemType));
        (*head)->value = value;
        (*head)->prev = NULL;
        (*head)->next = NULL;
      } else {
        ItemType *current = *head;
        ItemType *nowy_element;

        while (current->next != NULL) {
          current = current->next;
        }

        current->next = (ItemType *)malloc(sizeof(ItemType));
        current->next->value = value;
        current->next->prev = current;
        current->next->next = NULL;
      }
    } else {
      ItemType *kr = *head;
      ItemType *tmp;

      int i = 0;
      while (kr->next != NULL && i < position - 1) {
        kr = kr->next;
        i++;
      }

      tmp = kr->next;
      kr->next = (ItemType *)malloc(sizeof(ItemType));
      kr->next->value = value;
      kr->next->prev = kr;
      tmp->prev = kr->next;
      kr->next->next = tmp;
    }
  }
}

void next(ItemType **head, float value) {
  if (*head == NULL) {
    *head = (ItemType *)malloc(sizeof(ItemType));
    (*head)->value = value;
    (*head)->prev = NULL;
    (*head)->next = NULL;
  } else {
    ItemType *kr;
    kr = (ItemType *)malloc(sizeof(ItemType));
    kr->value = value;
    kr->prev = NULL;
    kr->next = (*head);
    (*head)->prev = kr;
    *head = kr;
  }
}
void previuos(ItemType **head, float value)
{
	
	if(*head==NULL)
	{
		*head = (ItemType *)malloc(sizeof(ItemType));
   		(*head)->value = value;
   		(*head)->prev = NULL;
    	(*head)->next = NULL;
	}else
	{
		ItemType *kr=*head;
		ItemType *nowy_element;
	
	    while (kr->next != NULL) {
	        kr = kr->next;
	    }
	
	    kr->next = (ItemType *)malloc(sizeof(ItemType));
	    kr->next->value = value;
	    kr->next->prev=kr;
	    kr->next->next = NULL;	
	}
}
void insert(ItemType **head, float value, int position) {

  if (position == 0)
    next(head, value);
  else {
    if (position == size(*head)){
      previuos(head, value);}
    else {
      ItemType *kr=*head;
      ItemType *tmp;

      int i = 0;
      while (kr->next != NULL && i < position - 1) {
        kr = kr->next;
        i++;
      }

      tmp = kr->next;
      kr->next = (ItemType *)malloc(sizeof(ItemType));
      kr->next->value = value;
      kr->next->prev = kr;
      tmp->prev = kr->next;
      kr->next->next = tmp;
    }
  }
}
