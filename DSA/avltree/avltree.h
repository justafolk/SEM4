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
void insertAVL(AVLtree *t, int key);
void adjustBF(AVLtree *t);

int height(AVLtree t);
Node *imbalNode(AVLtree t);

void adjustImbalance(AVLtree *t);
void rrAVL(AVLtree *t);
void llAVL(AVLtree *t);

void inorderAVL(AVLtree t);

