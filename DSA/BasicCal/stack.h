#define MAXSIZE 100

typedef struct stack{
  int top;
  int arr[MAXSIZE];
  int count;
} Stack;

typedef struct queue{
  int top;
  int rear;
  Stack *set;
  int count;
} Queue;

void push(Stack **S, int data);
int pop(Stack *S);
int peek(Stack *S);
int isEmpty(Stack *S);
int isFull(Stack *S);
char *infix_to_postfix(char* infix );

void display(Stack *S);

int evaluate_postfix(char *s);
int evaluate_infix(char *s);

void enqueue(Queue **Q, int data);
int dequeue(Queue **Q);


void displayQ(Queue *Q);
void sortS(Stack **S);

int precedence(char s);
