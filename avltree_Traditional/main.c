#include "avltree.h"

int main(){
  
  AVLtree t;

  initAVL(&t);
   insertAVL(&t, 178);
   insertAVL(&t, 32);
   insertAVL(&t, 59);
   insertAVL(&t, 205);
   insertAVL(&t, 210);
   insertAVL(&t, 80);
   insertAVL(&t, 75);
   insertAVL(&t, 66);
   insertAVL(&t, 100);
   insertAVL(&t, 125);
   insertAVL(&t, 10);
   insertAVL(&t, 15);
   insertAVL(&t, 108);
   insertAVL(&t, 84);

    insertAVL(&t, 84);
    insertAVL(&t, 83);
    insertAVL(&t, 85);
    insertAVL(&t, 86);



    preorderAVL(t);

}
