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

void preorderAVL(AVLtree t);
void initAVL(AVLtree *t);
void insertAVL(AVLtree *t, int key);
void adjustBF(AVLtree *t);

int height(AVLtree t);
Node *imbalNode(AVLtree t);


AVLtree rmNodeAVL(AVLtree *t, int key);

void adjustImbalance(AVLtree *t, AVLtree imbal);
void rrAVL(AVLtree *t, AVLtree imbal);
void llAVL(AVLtree *t, AVLtree imbal);

void inorderAVL(AVLtree t);

