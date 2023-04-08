#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "aBST.h"
#include <math.h>

void initaBST(aBST *t){
  t->arr = NULL;
  t->size = 0;
}


void insertaBST(aBST *t, int k){
  if (!t->size){
    t->arr = (int *) malloc(sizeof(int));
    if (!t->arr)
      return;

    t->arr[0] = k;
    t->size++;
    return;
  }

  int p = 0;

  while(p < t->size && t->arr[p] != INT_MIN){
    if (t->arr[p] == k)
      return;

    if (t->arr[p] > k)
      p = 2 * p + 1;
    else
      p = 2 * p + 2;
  }

  if (p < t->size && t->arr[p] == INT_MIN){
    t->arr[p] = k;
    return;

  }

  t->arr = realloc(t->arr, (p+1) * sizeof(int));

  if (!t->arr)
    return;

  for(int i = t->size; i < p; i++){
    t->arr[i] = INT_MIN;
  }
  t->arr[p] = k;
  t->size = p+1;
  return;
}


void inorderImpl(aBST t, int index){
  if (index >= t.size || t.arr[index] == INT_MIN)
    return;

  inorderImpl(t, 2*index+1 );

  if (t.arr[index] != INT_MIN){
    printf("%d\t", t.arr[index]);
    inorderImpl(t, 2*index+2 );
    return;
  }
}

void inOrderaBST(aBST t){
  int index = 0;
  inorderImpl(t, index);
  return;
}


int heightaBST(aBST t){

  int a = -1;
  while( 1<<(++a) < t.size){}

  return a;

}


int leafaBST(aBST t){

  int count = 0;
  for(int i = 0; i < t.size ; i++){
    
    //    if (((2*i+1 >= t.size && t.arr[(i-1)/2] != INT_MIN) || (t.arr[2*i+1] == INT_MIN && t.arr[2*i+2] == INT_MIN  )) && (t.arr[i] != INT_MIN)){

    if (t.arr[i] != INT_MIN && ((2*i+1 >= t.size && t.arr[(i-1)/2] != INT_MIN) || (t.arr[2*i+1] == INT_MIN && t.arr[2*i+2] == INT_MIN))) {

    printf("\n%d\t%d\t", i, t.arr[i]);
      count++;
    }
  }

  return count;

}


int isComplete(aBST t){
  
  for(int i = 0; i < t.size; i++){
    if (t.arr[2*i+1] == INT_MIN && t.arr[2*i+2] != INT_MIN)
      return 0;
  }

  return 1;

  
}


void levelOrderaBST(aBST t){

  printf("Level Order : \n");

  int n = 0;

  for(int i = 0; i < t.size; i++){

    if(1<<n == i+1){
      printf("\n"  );
      n++;
    }

    if (t.arr[i] != INT_MIN)
      printf("%d\t", t.arr[i]);

  }
}
