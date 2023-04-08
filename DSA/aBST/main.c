#include <stdio.h>
#include <stdlib.h>
#include "aBST.h"

int main(){

  aBST t;
  initaBST(&t);
  insertaBST(&t, 5);
  insertaBST(&t, 2);
  insertaBST(&t, 3);
  insertaBST(&t, 7);
  insertaBST(&t, 4);
  insertaBST(&t, 6);
  inOrderaBST(t);

  printf("\nSizeof the array %d\n", t.size);

  printf("\nHeight of the tree: %d\n", heightaBST(t));

  // for(int i = 0 ; i < t.size; i++){
   // printf("%d\n", t.arr[i]);
 // }
  printf("\nNumber of leaf nodes in the tree: %d\n", leafaBST(t));

  if(isComplete(t))
    printf("\nIts a complete tree");
  else
    printf("\nIts not a complete tree\n");

  levelOrderaBST(t);

}
