typedef struct Node{
  int data;
  struct Node *next;
} Node;

typedef struct Lists{
  Node *list;
  struct Lists *next;
} Lists;

typedef  struct Number{
  char sign;
  Node *numbers;
  int count;
} Number;

typedef Node* List;

void push(List *L, int data);
void displayList(List *L);
void displayListc(List *L);
int pop(List *L);

void reverse(struct Node** head_ref);
void displayLists(Lists **L);

int addLists(Number **L, int L1, int L2, char sign);

int subLists(Number **L, int L1, int L2, char sign);

int mulLists(Number **L, int L1, int L2, char sign);
int divLists(Number **L, int L1, int L2, char sign);
