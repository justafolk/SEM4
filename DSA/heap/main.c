#include "heap.h"

int main(){
  Heap h;
  init(&h);

  insertheap(&h, 2);
  insertheap(&h, 1);
  insertheap(&h, 1);
  rmheap(&h);
  insertheap(&h, 2);
  insertheap(&h, 3);
  insertheap(&h, 4);
  insertheap(&h, 5);

  rmheap(&h);
  rmheap(&h);
  rmheap(&h);
  rmheap(&h);
  rmheap(&h);


  insertheap(&h, 2);
  insertheap(&h, 1);
  insertheap(&h, 1);
  rmheap(&h);
  insertheap(&h, 2);
  insertheap(&h, 3);
  insertheap(&h, 4);
  insertheap(&h, 5);

  rmheap(&h);
  rmheap(&h);
  rmheap(&h);
  rmheap(&h);
  rmheap(&h);

}
