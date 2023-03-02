#include <stdio.h> 
#include <stdlib.h> 
#include "./LinkedList.h"
#include <limits.h>

Node *addLists(List *L1, List *L2){
  List temp1 = *L1;
  List temp2 = *L2;
  List ret = (List) malloc(sizeof(Node));

  ret->data = INT_MIN;
  ret->next = 0;

  int sum = 0;
  int carry = 0;

  while(temp1 != NULL && temp2 != NULL){
    sum = temp1->data + temp2->data + carry;
    push(&ret, sum%10);
    carry = sum / 10;

    temp1 = temp1->next;
    temp2 = temp2->next;
    
  }

  while(temp1 != NULL ){
    sum = temp1->data + carry;
    push(&ret, sum%10);
    carry = sum / 10;

    temp1 = temp1->next;
  }
  while(temp2 != NULL ){
    sum = temp2->data + carry;
    push(&ret, sum%10);
    carry = sum / 10;

    temp2 = temp2->next;
  }
  if( carry > 0){
    push(&ret, carry);
    
  }



  return ret;
}
