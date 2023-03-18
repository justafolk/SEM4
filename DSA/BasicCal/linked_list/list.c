#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"



void displayNumbers(Number **L, int len){
  int i = 0;

  Node *temp = L[i]->numbers;
  while(i < len){
    printf("\nnumber %d, count %d: %c", i, L[i]->count, L[i]->sign );
    display(&temp);
    i++;
    temp = L[i]->numbers;

  }
}


void initNumber(Number **L, int index, char sign ){
  L[index] = (Number *) malloc(sizeof(Number));
  L[index]->numbers = NULL;
  L[index]->count = 0;
  L[index]->sign = sign;
}

void addElement(Node **head, int data){
  Node *temp = (Node *) malloc(sizeof(Node));
  temp->data = data;

  if (*head == NULL){
    temp->next = NULL;
    *head = temp;
    return;
  }

  temp->next = *head;

  *head = temp;


}



void rmDuplicates(Node **head){

  Node *temp = *head;
  int dup = INT_MIN;

  while (temp != NULL){

    if (temp->data  == dup){
      temp = temp->next;
      rmElement(head, dup);
      continue;
    }
    dup = temp->data;
    temp = temp->next;

  }

}

void rmElement(Node **head, int value){

  Node *temp = *head;
  Node *prev = *head;

  while (temp != NULL){
    if (temp->data  == value){
      break;
    }
    prev = temp;
    temp = temp->next;
  }

  prev->next = temp->next;
  free(temp);
  return;



}

void display(Node **head){

  Node *temp = *head;

  printf("\n");
  while (temp != NULL){
    printf("%c", temp->data);
    temp= temp->next;
  }
  printf("\n");
}


void modify(Node **head, int toreplace, int replace){

  Node *temp = *head;

  while (temp != NULL){
    if (temp->data  == toreplace){
      temp->data = replace;
      break;
    }
    temp = temp->next;
  }
}

void reverse(Node **head){
  Node *prev = *head;
  Node *curNode = prev->next;
  Node *temp = prev->next ;


  prev->next = NULL; 

  while(temp != NULL)
    {
      temp = temp->next;
      curNode->next = prev;

      prev = curNode;
      curNode = temp;
    }

  *head = prev; 

}


