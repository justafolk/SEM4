#include "avltree.h"

void initAVL(AVLtree *t){
  *t = NULL;
  return;
}


void inorderAVL(AVLtree t){
  if (!t)
    return;

  inorderAVL(t->left);
  printf("%15s ~ %3d", t->key, t->bf);
  if(t->parent)
    printf("  ~ %15s\n", t->parent->key);
  else 
    printf("  ~  NULL\n");
  inorderAVL(t->right);
}


void preorderAVL(AVLtree t){
  if (!t)
    return;

  printf("%15s ~ %3d", t->key, t->bf);
  if(t->parent)
    printf("  ~ %15s\n", t->parent->key);
  else 
    printf("  ~  NULL\n");

  preorderAVL(t->left);
  preorderAVL(t->right);
}

void insertAVL(AVLtree *t, char *key){

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

    if (strcmp(h->key , key) < 0){
      h = h->right;

    } else if (strcmp(h->key , key) > 0){
      h = h->left;

    } else{
      return;
    }
  }

  nh->parent = p;
  if (strcmp(p->key , key) < 0){
    p->right = nh;
  } else{
    p->left = nh;
  }

  adjustBF(&nh);

  AVLtree imbalnode = imbalNode(nh);
  while (imbalnode){
    adjustImbalance(t, imbalnode);
    imbalnode = imbalNode(nh);
  }

}

Node *imbalNode(AVLtree t){
  if(!t)
    return NULL;

  while(t){
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
  if (!*t)
    return;

  if((*t)->parent)
    adjustBF(&(*t)->parent);

  (*t)->bf = height((*t)->left) - height((*t)->right);
  return;
}


void adjustImbalance(AVLtree *t, AVLtree imbal){
  if (!(t))
    return;

  if ((imbal)->bf < -1){
    if (imbal->right && imbal->right->bf <= -1){
      rrAVL(t, imbal);
    } else {
      llAVL(t, imbal->right);
  //    adjustBF(&imbal->right->right);

      rrAVL(t, imbal);
    }
  } else {
    if ( imbal->left && (imbal->left)->bf >= 1){
      llAVL(t, imbal);
    } else {
      rrAVL(t, imbal->left);
   //   adjustBF(&imbal->left->left);
      llAVL(t, imbal);
    }
  }
  //adjustBF(&imbal);

}

void rrAVL(AVLtree *t, AVLtree p){

  AVLtree aParent = p->parent;

  AVLtree b = p->right;

  p->right = b->left;

  b->left = p;
  b->parent = p->parent;
  p->parent = b;

  if (p->right){
    p->right->parent = p;
  }

  adjustBF(&p);

  if (*t == p){
    *t = b;
    return;
  }


  if (aParent->right == p){
    aParent->right = b;
  } else {
    aParent->left = b;
  }
  b->parent = aParent;


}

void llAVL(AVLtree *t, AVLtree p){



  AVLtree aParent = p->parent;
  AVLtree b = p->left;
  p->left = b->right;


  b->right = p;
  b->parent = p->parent;
  p->parent = b;

  if (p->left){
    p->left->parent = p;
  }

  adjustBF(&p);
  
  if (*t == p){
    *t = b;
    return;
  }


  if (aParent->right == p){
    aParent->right = b;
  } else {
    aParent->left = b;
  }
  b->parent = aParent;

}

AVLtree minValueNode(AVLtree t){
    while (t && t->left != NULL)
        t = t->left;
 
    return t;
}

AVLtree rmNodeBST(AVLtree t, char* key){
    if (t == NULL)
        return t;

    if (strcmp(key , t->key) < 0){
        t->left = rmNodeBST(t->left, key);
        if (t->left)
          t->left->parent = t;
    } else if (strcmp(key , t->key) > 0){

        t->right = rmNodeBST(t->right, key);
        if (t->right)
          t->right->parent = t;
    } else {
        if (t->left == NULL) {
            AVLtree temp = t->right;
            free(t);
            return temp;

        } else if (t->right == NULL) {
            AVLtree temp = t->left;
            free(t);
            return temp;
        }
        AVLtree temp = minValueNode(t->right);
        t->key = temp->key;
        t->right = rmNodeBST(t->right, temp->key);
        if (t->right)
          t->right->parent = t;
    }
    return t;
}

AVLtree rmNodeAVL(AVLtree *t, char* key){

  if (*t == NULL)
      return *t;

  AVLtree delnode = rmNodeBST(*t, key);

  adjustBF(&delnode->right);
  adjustBF(&delnode->left);
  
  AVLtree imbal = imbalNode(*t);

  while(imbal){
    adjustImbalance(t, imbal);
    imbal = imbalNode(*t);
  }

  return delnode;
}

void destroyTree(AVLtree *t){
  if (!*t)
    return;

  destroyTree(&(*t)->left);
  destroyTree(&(*t)->right);
  free(*t);
  return;
}

void generateLatex(AVLtree t){
  if (!t)
    return;

  printf("[");
  printf("%s", t->key);
  generateLatex(t->left);
  generateLatex(t->right);

  printf("]");
  return;
}
