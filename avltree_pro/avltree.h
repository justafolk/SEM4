#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct Node{
  char *key;
  int data;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
  int bf;
} Node;

typedef Node* AVLtree;

void preorderAVL(AVLtree t);
void initAVL(AVLtree *t);
void insertAVL(AVLtree *t, char *key, int data);
void adjustBF(AVLtree *t);

int height(AVLtree t);
Node *imbalNode(AVLtree t);

void generateLatex(AVLtree t);

AVLtree rmNodeAVL(AVLtree *t, char *key);

void destroyTree(AVLtree *t);

void adjustImbalance(AVLtree *t, AVLtree imbal);
void rrAVL(AVLtree *t, AVLtree imbal);
void llAVL(AVLtree *t, AVLtree imbal);

void inorderAVL(AVLtree t);

