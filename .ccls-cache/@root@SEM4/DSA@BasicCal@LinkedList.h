typedef struct Node{
  int data;
  struct Node *next;
} Node;

typedef struct Lists{
  Node *list;
  struct Lists *next;
} Lists;

typedef Node* List;

void push(List *L, int data);
void displayList(List *L);
int pop(List *L);

void reverse(struct Node** head_ref);
void displayLists(Lists **L);

Node *addLists(List *L1, List *L2);
Node *subLists(List *L1, List *L2);
Node *mulLists(List *L1, List *L2);
Node *divLists(List *L1, List *L2);
