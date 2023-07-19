#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


typedef struct Node{
  int data;
  struct Node *next;
}Node;

typedef struct queue{
  Node *front, *rear;
  int count;
} queue;

typedef queue* Queue;

void initQueue(Queue *Q);
void enqueue(Queue Q, int data);
int dequeue(Queue Q);

int peekQ(Queue Q);

