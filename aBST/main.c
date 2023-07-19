#include <stdio.h>
#include <stdlib.h>
#include "aBST.h"

int main(){

  aBST t;
  initaBST(&t);
  insertaBST(&t, 80);
  insertaBST(&t, 90);
  insertaBST(&t, 85);
  insertaBST(&t, 100);
  insertaBST(&t, 95);
  insertaBST(&t, 87);
  insertaBST(&t, 92);


  for(int i = 0; i < t.size; i++){
      printf("%d\t", t.arr[i]);

  }

}
