#include <stdio.h> 
#include <stdlib.h> 
#include "./LinkedList.h"
#include <limits.h>

int addLists(Number **L, int L1, int L2, char sign){

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

  L[L2] = ret;

  //displayNumbers(L, 4);
  return L2;
}

int subLists(Number **L, int L1, int L2, char sign){


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

    if(temp1->data < temp2->data){
      temp1->data=(temp1->data+10)-borrow;
      borrow = 1;
    }
  else if (temp1->data == temp2->data && borrow){
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

  }


  while(temp1 != NULL ){
    if(temp1->data < borrow){
      temp1->data=(temp1->data+10)-borrow;
      borrow = 1;
    }
  else{
      temp1->data = (temp1->data)-borrow;
      borrow = 0;
    }
    sum = temp1->data + carry;
    push(&ret->numbers, sum%10);
    carry = sum / 10;

    ret->count++;
    temp1 = temp1->next;
  }
  while(temp2 != NULL ){
    if(temp2->data < borrow){
      temp2->data=(temp2->data+10)-borrow;
      borrow = 1;
    }
  else{
      temp2->data = (temp2->data)-borrow;
      borrow = 0;
    }
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

  displayList(&L[L1]->numbers);

  // displayNumbers(L, 4);
  return L1;

}

void mulscalarList(Number *L, int num, Number **N){
  Node *sums = (*N)->numbers;
  Node *temp = L->numbers;
  int mul = 1;
  int carry = 0;
  (*N)->count = 0;

  while(temp ){
    mul = (temp->data * num )+ carry;
    push(&sums, mul%10);

    carry = mul / 10;
    temp = temp->next;
    (*N)->count++;
  }

  while(carry){
    push(&(*N)->numbers, carry%10);
    carry = carry / 10;
    (*N)->count++;
  }

}



int mulLists(Number **L, int L1, int L2, char sign){

  Number *temp1 = L[L1];
  List temp2 = L[L2]->numbers;

  int inter = 0;
  int count = 0;

  Number *res = (Number *) malloc(sizeof(Number));
  res->numbers = NULL;
  pushf(&res->numbers, 0);

  res->count = 0;

    pushf(&res->numbers, 0);
  res->sign = '+';
  Node *templist = NULL;

  L[L1]= (Number *) malloc(sizeof(Number));
  L[L1]->count = 0;

  L[L2] = res;
  int k, i;
  i = 0;
  while(temp2){
    L[L1]->numbers = NULL;
    pushf(&L[L1]->numbers, 0);
    mulscalarList(temp1, temp2->data, &L[L1]);
    temp2 = temp2->next;
    k = 0;
    while(k<i){
      pushf(&(L[L1]->numbers), 0);
      k++;
    }
    i++;
    L[L2] = L[addLists(L, L1, L2, '+')];

  }


  L[L2]->numbers = L[L2]->numbers->next;

  return L2;

}

