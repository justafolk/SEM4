#include "heap.h"

int main(){
  Heap h;
  init(&h);

  insertheap(&h, 5);
  insertheap(&h, 6);
  insertheap(&h, 7);
  insertheap(&h, 8);
  insertheap(&h, 9);
  insertheap(&h, 10);
  insertheap(&h, 11);
  insertheap(&h, 12);
  insertheap(&h, 13);
  insertheap(&h, 14);
  insertheap(&h, 15);
  insertheap(&h, 16);


  heapSortDsc(&h);


  printArray(h);
}
