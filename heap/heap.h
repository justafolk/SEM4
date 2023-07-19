#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct heap{
  int *arr;
  int size;
  int rear;
} heap;

typedef heap* Heap;

void init(heap **h);
void insertheap(heap **h, int k);
int rmheap(heap **h);

void heapSortAsc(Heap *h);

void printArray(Heap h);
void heapSortDsc(Heap *h);
