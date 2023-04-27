#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
  int *arr;
  int size;
  int rear;
} heap;

typedef heap* Heap;

void init(heap **h);
void insertheap(heap **h, int k);
int rmheap(heap **h);

