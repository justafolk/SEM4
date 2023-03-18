#include <stdio.h> 
#include <stdlib.h> 
#include "./LinkedList.h"
#include <limits.h>

int addLists(Number **L, int L1, int L2, char sign){

  printf("Adding %d with %d\n", L1, L2);
  List temp1 = L[L1]->numbers;
  List temp2 = L[L2]->numbers;

  Number *ret = (Number *) malloc(sizeof(Number));
  ret->numbers = (Node *) malloc(sizeof(Node));

  ret->numbers->data = INT_MIN;
  ret->numbers->next = 0;
  ret->sign = sign;
  ret->count = 0;

  int sum = 0;
  int carry = 0;

  while(temp1 != NULL && temp2 != NULL){
    sum = temp1->data + temp2->data + carry;
    push(&ret->numbers, sum%10);
    carry = sum / 10;
    ret->count++;

    temp1 = temp1->next;
    temp2 = temp2->next;

  }

  while(temp1 != NULL ){
    sum = temp1->data + carry;
    push(&ret->numbers, sum%10);
    carry = sum / 10;

    ret->count++;
    temp1 = temp1->next;
  }
  while(temp2 != NULL ){
    sum = temp2->data + carry;
    push(&ret->numbers, sum%10);
    carry = sum / 10;
    ret->count++;

    temp2 = temp2->next;
  }
  if( carry > 0){
    ret->count++;
    push(&ret->numbers, carry);
  }

  L[L1] = ret;

  //displayNumbers(L, 4);
  return L1;
}

int subLists(Number **L, int L1, int L2, char sign){


  printf("Subtracting %d with %d", L1, L2);
  List temp1 = L[L1]->numbers;
  List temp2 = L[L2]->numbers;

  Number *ret = (Number *) malloc(sizeof(Number));
  ret->numbers = (Node *) malloc(sizeof(Node));

  ret->numbers->data = INT_MIN;
  ret->numbers->next = 0;
  ret->sign = sign;
  ret->count = 0;

  int sum = 0;
  int carry = 0;
  int borrow = 0;

  while(temp1 != NULL && temp2 != NULL){
    printf("temp1:%d\ttemp2:%d", temp1->data, temp2->data);

    if(temp1->data < temp2->data){
      temp1->data=(temp1->data+10)-borrow;
      borrow = 1;
    }
  else{
      temp1->data = (temp1->data)-borrow;
      borrow = 0;
    }

    sum = (temp1->data + carry) - temp2->data ;
    push(&ret->numbers, sum%10);
    carry = sum / 10;

    ret->count++;

    temp1 = temp1->next;
    temp2 = temp2->next;

    printf("carry:%d\tborrow:%d\n", carry, borrow);
  }


  while(temp1 != NULL ){
    temp1->data = (temp1->data)-borrow;
    borrow = 0;
    sum = temp1->data + carry;
    push(&ret->numbers, sum%10);
    carry = sum / 10;

    ret->count++;
    temp1 = temp1->next;
  }
  while(temp2 != NULL ){
    temp2->data = (temp2->data)-borrow;
    borrow = 0;
    sum = temp2->data + carry;
    push(&ret->numbers, sum%10);
    carry = sum / 10;
    ret->count++;

    temp2 = temp2->next;
  }
  if( carry > 0){
    ret->count++;
    push(&ret->numbers, carry);
  }
  L[L1] = ret;

  printf("\nans: %c", L[L1]->sign);
  displayList(&L[L1]->numbers);

  // displayNumbers(L, 4);
  return L1;

}


void mulscalarList(Node *L, int num, Number **N){
  Node *sums = (*N)->numbers;
  Node *temp = L;
  int mul = 1;
  int carry = 0;
  (*N)->count = 0;

  while(temp ){
    if(!sums->next && temp->next){
      push(&(*N)->numbers, 0);
    }
    mul = ((temp->data + carry) * num)+sums->data;
    printf("%d\t", mul%10);
    sums->data = mul%10;
    carry = mul / 10;
    temp = temp->next;
    sums = sums->next;
    (*N)->count++;
  }

  while(carry){
    push(&(*N)->numbers, carry%10);
    printf("\n%d\t", carry%10);
    carry = carry / 10;
    (*N)->count++;
  }


}



int mulLists(Number **L, int L1, int L2, char sign){

  List temp1 = L[L1]->numbers;
  List temp2 = L[L2]->numbers;

  int inter = 0;
  int count = 0;
  Number *res = (Number *) malloc(sizeof(Number));
  res->numbers = NULL;
  res->count = 0;
  res->sign = sign;
  Node *templist = NULL;

  push(&res->numbers, 0);

  while(temp2){
    mulscalarList(L[L1]->data, temp2->data, &res);
    push()
    
  }


}
