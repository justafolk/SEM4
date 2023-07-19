#include "avltree.h"

int main(){

  AVLtree t ;
  initAVL(&t);

  FILE *fptr;

  fptr = fopen("names", "r");


  char *s = (char *) malloc(sizeof(char)*25);
  fscanf(fptr, "%s",s);

  while(*s != '\0'){
    insertAVL(&t, s);
    s = (char *) malloc(sizeof(char)*25);
    fscanf(fptr, "%s",s);
  }

   s = (char *) malloc(sizeof(char)*25);
  fscanf(fptr, "%s",s);

  while(*s != '\0'){
    rmNodeAVL(&t, s);
    s = (char *) malloc(sizeof(char)*25);
    fscanf(fptr, "%s",s);
  }

  generateLatex(t);
  inorderAVL(t);

  while(1){

    printf("1. Add new Element to the tree.\n2. Remove an Element from the tree.\n3. Traverse through the tree.\n4. Destroy the tree. \n5. Exit. \nEnter your option: ");
    int n = 0;
    scanf("%d", &n);


    char ele[50];
    switch(n){
      case 1:
        printf("\nEnter your element: ");
        char *new_ele = malloc(sizeof(char) * 50); 
        scanf("%s", new_ele);
        insertAVL(&t, new_ele);
        break;
      case 2:
        printf("\nEnter your element: ");
        scanf("%s", ele);
        rmNodeAVL(&t, ele);
        break;
      case 3:
        generateLatex(t);
        printf("\n====================\n");

        inorderAVL(t);
        printf("\n====================\n");
        break;
      case 4:
        destroyTree(&t);
        initAVL(&t);
        break;
      case 5:
        exit(0);
      default:
        printf("\nINVALID INPUT\n");

    }
  }

}
