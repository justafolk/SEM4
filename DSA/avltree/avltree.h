#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int key;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
  int bf;
} Node;

typedef Node* AVLtree;

void initAVL(AVLtree *t);
void insertAVL(AVLtree *t, int d);
void adjustBF(AVLtree *t);

Node* adjustImbalance(AVLtree *t);

void inorderAVL(AVLtree t);


