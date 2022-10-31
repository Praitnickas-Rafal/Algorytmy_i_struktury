// Rafal Praitnickas. Student
// Lista jednokierunkowa niesortowana
// 2022-10-24
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Item {
  float value;
  struct Item *next;
} ItemType;

int find(float value, ItemType *head); //zmieniłem int *head na itemtype *head

int locate(float value, int *head); //???

int retrieve(ItemType *item, int *head); //???

void insert(ItemType **head, float value, 
            int position); // zmieniłem i dobawiłem

void remove1(ItemType **head,
             int position); // zmieniłem ItemType *head na int position i do
                            // headu dobawiłem jeszcze jeden pointer

int size(ItemType *head); // zmieniłem int na ItemType

int findMax(ItemType **head); //zmieniłem i dobawiłem

int findMin(ItemType *head);  //zmieniłem i dobawiłem

void printList(ItemType *head); // zmieniłem na void

int isEmpty(ItemType *head); //zmieniłem i dobawiłem

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

  /*-----------------------------------------------------*/
  
    previous(&head, 6);    //sprawdzamy funkcyji previuos() i printlist()
    previous(&head, 5);
    previous(&head, 8);
    printList(head);
  
  /*-----------------------------------------------------*/
  
    int i = size(head);     //sprawdzamy funkcje size()
    printf("%d \n", i);
  
  /*-----------------------------------------------------*/
  
    remove1(&head, 0);      //sprawdzamy funkcyje deleteElement(head, position)
    printList(head);
  
  /*-----------------------------------------------------*/
  
    next(&head, 5);        //sprawdzamy funkcyje next(head, number)
    printList(head);
  
  /*-----------------------------------------------------*/
  
    insert(&head, 7, 1);   //sprawdzamy funkcyje insert(head, number, position)
    printList(head);

  /*-----------------------------------------------------*/
  
    int s = isEmpty(head); // s - rezultat //sprawdzamy funkcyje isEmpty(head)
  
    if (s == 1){
      printf("\n The list is not empty: \n");
    }
    else
    {
      printf("\n List is empty: \n");
    }  
  
  /*-----------------------------------------------------*/
  
  int index = find(5.0, head);      //sprawdzamy funkcyje find()
    
    if(index == -1)
        printf("\n Item not found \n");
    else
        printf("\n Item found at position: %d \n", index+1);
    
  /*-----------------------------------------------------*/

   int max = findMax(&head);       //sprawdzamy funkcyje findMax()
   printf("\n max: %d \n", max);

  /*-----------------------------------------------------*/
   
   int min = findMin(head);        //sprawdzamy funkcyje findMin()
   printf("\n min: %d \n", min);

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
  return counter; // test
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
void remove1(ItemType **head, int position) {
  if (position == 0) {
    ItemType * tmp = NULL;

    if (*head != NULL) {
      tmp = (*head)->next;
      free(*head);
      *head = tmp;
    } }
    else {
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
      current->next->value = value; //
      current->next->next = tmp;
    }
  }
}
int isEmpty(ItemType *head)
{
   if(head == NULL)
   {
     return 0;
   }
   else
   {
     return 1;
   }
  
}
int find(float value, ItemType *head)
{
  ItemType *current = head;
  int index = 0;

  while (current != NULL)
    {
      if(current->value == value){
        return index;
      }
      current = current->next;
      index++;
    }
    return -1;
}

int findMax(ItemType **head)
{
    ItemType *current;
    int max=0;
    current = *head;
    
    
    while(current!=NULL) {
    if(current->value>max) {
        max=current->value;
    }
    current=current->next;
}
  return max;
}
int findMin(ItemType *head)
{
    
    int min=head->value;

    while(head->value < min){
      min = head -> value;
      head=head->next;
      }
      return min;
}
