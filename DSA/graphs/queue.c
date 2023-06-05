#include "queue.h"


void initQueue(Queue *Q){
  *Q = NULL;

  Queue temp = (Queue) malloc(sizeof(queue));
  temp->front = temp->rear = NULL;
  temp->count = 0;
  *Q = temp;
  return;
}


void enqueue(Queue Q, int data){

  Node* nn = (Node*) malloc(sizeof(Node));
  nn->data = data;
  nn->next = NULL;

  if(!Q->front && !Q->rear ){
    Q->front = Q->rear = nn;
    Q->count++;
    return;
  }


  Q->rear->next = nn;
  Q->rear = Q->rear->next;
  Q->count++;

  return;
}


int dequeue(Queue Q){
  
  if (!Q->count )
    return -1;

  int temp = Q->front->data;

  Q->count--;

  if (Q->front == Q->rear){
    Q->front = Q->rear = NULL;
  } else{
    Q->front = Q->front->next;
  }

  return temp;
}

int peekF(Queue Q){
  if (!(Q) || !(Q)->count)
    return -1;
  return Q->front->data;
}

int peekR(Queue Q){
  if (!(Q) || !(Q)->count)
    return -1;
  return Q->rear->data;
}
