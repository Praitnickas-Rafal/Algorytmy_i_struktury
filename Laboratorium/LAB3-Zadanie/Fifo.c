// Rafal Praitnickas. Student
    
    // kolejka
    // 2022-10-24
    // czas kiedy został dobawiony 22:11

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  //dla INT_MIN

struct ItemType {

  int front, rear, value;
  int *array;
  unsigned capacity;
};

struct ItemType *createQueue(unsigned capacity) {
  struct ItemType *queue = (struct ItemType *)malloc(sizeof(struct ItemType));
  queue->capacity = capacity;
  queue->front = queue->value = 0;

  queue->rear = capacity - 1;
  queue->array = (int *)malloc(queue->capacity * sizeof(int));
  return queue;
}

void Insert(struct ItemType *queue, int item) {
  if (queue->value == queue->capacity)
    return;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->value = queue->value + 1;
  printf("%d w kolejce \n", item);
}

int deletequeue(struct ItemType *queue) {
  if (queue->value == 0)
    return INT_MIN;
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->value = queue->value - 1;
  return item;
}

int front(struct ItemType *queue) { //dobawilem 
  if (queue->value == 0)
    return INT_MIN;
  return queue->array[queue->front];
}

int rear(struct ItemType *queue) { //dobawilem
  if (queue->value == 0)
    return INT_MIN;
  return queue->array[queue->rear];
}

int main() {
  
  struct ItemType *queue = createQueue(1000); //Tworze tablice na 1000 elementów
  
  //Sprawdzenie
  
  Insert(queue, 11);
  Insert(queue, 12);
  Insert(queue, 13);
  Insert(queue, 14);
  Insert(queue, 17);


  printf("\n %d usuniety z kolejki\n", deletequeue(queue));
  printf("\n %d usuniety z kolejki\n", deletequeue(queue));
  printf("\n");
  
  printf("Przedni element jest: %d\n", front(queue));
  printf("Tylny element to: %d\n", rear(queue));

  return 0;
}
