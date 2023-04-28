#include "avltree.h"

int main(){
  
  AVLtree t;

  initAVL(&t);
  insertAVL(&t, 10);
  insertAVL(&t, 20);
  insertAVL(&t, 30);

  rrAVL(&t);
  printf("TOP NODE %d\n", t->key);
  inorderAVL(t);

}
