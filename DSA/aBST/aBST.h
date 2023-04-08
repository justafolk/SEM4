typedef struct aBST{
  int *arr;
  int size;
} aBST;

void initaBST(aBST *t);
void insertaBST(aBST *t, int k);

void inOrderaBST(aBST t);


int heightaBST(aBST t);

int leafaBST(aBST t);

int isComplete(aBST t);

void levelOrderaBST(aBST t);
