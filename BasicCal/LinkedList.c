#include <stdio.h> 
#include <stdlib.h> 
#include "./Operations.h"
#include "./LinkedList.h"
#include <limits.h>

void push(List *L, int data){


  List temp = *L;
  if (temp->data == INT_MIN){
    temp->data = data;
    temp->next = NULL;
    return;

  }

  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  while(temp->next != NULL){
    temp = temp->next;
  }

  temp->next = newNode;

}


void displayNumbers(Number **L, int len){
  int i = 0;

  while(i < len){
    printf("\nnumber %d: %c", i+1, L[i]->sign );
    displayList(&L[i]->numbers);
    i++;

  }
}

void displayListc(List *L){

  List temp = *L;

  printf("\n");

  while(temp != NULL){

    printf("%c",temp->data );
    temp = temp->next;
  }
  printf("\n");

}
void displayList(List *L){

  List temp = *L;


  while(temp != NULL){

    printf("%d",temp->data );
    temp = temp->next;
  }
  printf("\n");

}


int pop(List *L){
  List temp = *L;
  int det;

  while(temp->next->next != NULL){
    temp = temp->next;
  }
  det = temp->next->data;
  free(temp->next);
  temp->next = NULL;
  return det;
}

void reverse(struct Node** head_ref)
{
  struct Node* prev = NULL;
  struct Node* current = *head_ref;
  struct Node* next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head_ref = prev;
}



void displayLists(Lists **L){

  Lists *t = *L;
  List temp;
  while(t != NULL){

    temp = t->list;

    printf("\n");

    while(temp != NULL){

      printf("%d",temp->data );
      temp = temp->next;
    }
    printf("\n");
    t = t->next;
  }

}
