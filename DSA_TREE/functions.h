typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
} Node;

typedef Node* Tree;

void initTree(Tree *t);

void displayInorder(Tree t);
// Tree functions
void insertBT(Tree *t, int key);
void displayBT(Tree t);
int searchBT(Tree t, int key);

// Tree functions
void insertBST(Tree *t, int key);
void displayBST(Tree t);
int searchBST(Tree t, int key);


int generateRange(int n, char *filename);
