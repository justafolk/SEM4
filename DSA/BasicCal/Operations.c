#include <stdio.h> 
#include <stdlib.h> 
#include "./LinkedList.h"
#include <limits.h>

Number *addLists(Number *L1, Number *L2){
  List temp1 = L1->numbers;
  List temp2 = L2->numbers;

  Number *ret = (Number *) malloc(sizeof(Number));

  ret->numbers->data = INT_MIN;
  ret->numbers->next = 0;

  int sum = 0;
  int carry = 0;

  while(temp1 != NULL && temp2 != NULL){
    sum = temp1->data + temp2->data + carry;
    push(&ret->numbers, sum%10);
    carry = sum / 10;

    temp1 = temp1->next;
    temp2 = temp2->next;
    
  }

  while(temp1 != NULL ){
    sum = temp1->data + carry;
    push(&ret->numbers, sum%10);
    carry = sum / 10;

    temp1 = temp1->next;
  }
  while(temp2 != NULL ){
    sum = temp2->data + carry;
    push(&ret->numbers, sum%10);
    carry = sum / 10;

    temp2 = temp2->next;
  }
  if( carry > 0){
    push(&ret->numbers, carry);
    
  }



  return ret;
}


