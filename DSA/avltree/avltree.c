#include "avltree.h"

void initAVL(AVLtree *t){
  *t = NULL;
  return;
}


void inorderAVL(AVLtree t){
  if (!t)
    return;

  inorderAVL(t->left);
  printf("%d - %d\n", t->key, t->bf);
  inorderAVL(t->right);
}

void insertAVL(AVLtree *t, int key){

  AVLtree nh = (AVLtree) malloc(sizeof(Node));
  nh->left = nh->right =  NULL;
  nh->parent = NULL;
  nh->key = key;
  nh->bf = 0;

  if(!(*t)){
    *t = nh;
    return;
  }

  AVLtree h = *t;
  AVLtree p = h;

  while(h){
    p = h;

    if (h->key < key){
      h = h->right;

    } else if (h->key > key){
      h = h->left;

    } else{
      return;
    }
  }

  nh->parent = p;
  if (p->key < key){
    p->right = nh;
  } else{
    p->left = nh;
  }

  adjustBF(&nh);

  AVLtree imbalnode = imbalNode(nh);
  if (imbalnode)
    printf("imbal node:%d\n", imbalnode->key);


}

Node *imbalNode(AVLtree t){
  if(!t)
    return NULL;

  while(t->parent){
    if (t->bf > 1 || t->bf < -1){
      return t;
    }
    t = t->parent;
  }

  return NULL;

}


int height(AVLtree t){
  if (!t)
    return -1;

  int a = height(t->right)+1;
  int b = height(t->left)+1;

  return a>=b?a:b;
}


void adjustBF(AVLtree *t){
  if (!t)
    return;

  if((*t)->parent)
    adjustBF(&(*t)->parent);

  (*t)->bf = height((*t)->left) - height((*t)->right);
  return;
}


void adjustImbalance(AVLtree *t){
  if (!(*t))
    return;

  if ((*t)->bf > 1){
    if ((*t)->bf > 1){
      rrAVL(t);
    } else {
      // rrAVL(t);
      // llAVL(t);
    }
  } else {
    if ((*t)->bf < -1){
      // llAVL(t);
    } else {
      // llAVL(t);
      // rrAVL(t);
    }
  }

}

void rrAVL(AVLtree *t){

  if ((*t)->parent){
    AVLtree aParent = (*t)->parent;
    if (aParent->right == *t){
      aParent->right = (*t)->right;
    } else {
      aParent->left = (*t)->right;
    }
    (*t)->right->parent = aParent;
  } else {
    (*t)->right->parent = NULL;
  }

  AVLtree h = *t;
  AVLtree b = h->right;

  h->right = b->left;

  b->left = h;
  h->parent = b;
  b->parent = h->parent;
  *t = b;


}

void llAVL(AVLtree *t){

  if ((*t)->parent){
    AVLtree aParent = (*t)->parent;
    if (aParent->right == *t){
      aParent->right = (*t)->left;
    } else {
      aParent->left = (*t)->left;
    }
    (*t)->left->parent = aParent;
  } else {
    (*t)->left->parent = NULL;
  }

  AVLtree h = *t;
  AVLtree b = h->left;

  h->left = b->right;

  b->right = h;
  h->parent = b;
  b->parent = h->parent;
  *t = b;

}
