#include <stdio.h> 
#include <stdlib.h> 
#include "./Operations.h"
#include "./LinkedList.h"


void push(List *L, int data){
  List temp = *L;

  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  
  while(temp->next != NULL){
    temp = temp->next;
  }

  temp->next = newNode;
  
}

void displayList(List *L){

  List temp = *L;

  while(temp->next != NULL){
    printf("%d -> ",temp->data );
    temp = temp->next;
  }

}
