
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void display(Stack *S){
  while(peek(S) !=-1 ){
    printf("%d", pop(S));
  }

}
void push(Stack **S, int data){
  Stack *temp = *S;
  if (temp->top +1 > MAXSIZE){
    printf("STACK FULL");
    return;
  }
  temp->count++;

  temp->top++;
  temp->arr[temp->top] = data;

}

int peek(Stack *S){
  return S->arr[S->top];
}


int pop(Stack *S){
  if (S->top == -1){
    return -1;
  }
  int ret = S->arr[S->top];
  S->top--;
  S->count--;
  return ret;
}


int isEmpty(Stack *S){
  return S->top == MAXSIZE-1 ;
}


int isOperator(char x){
  if (x == '+' || x == '-' || x == '*' || x == '/')
    return 1;
  else
    return 0;
}

int solve(int n1, int n2, char s){
  int n3 = 0;
  switch (s){
    case '+':
      n3 = n1+n2;
      break;
    case '-':
      n3 = n1-n2;
      break;
    case '/':
      n3 = n1/n2;
      break;
    case '*':
      n3 = n1*n2;
      break;
    case '^':
      n3 = n1*n2;
      break;
    default:
      printf("INVALID INPUT");
      return;

  }
  return n3;
}

int evaluate_postfix(char *s){
  s = infix_to_postfix(s);
  Stack *S = (Stack *) malloc(sizeof(Stack));
  S->top = -1;

  int i = 0;

  int num1, num2;
  while(s[i] != '\0'){

    if (!isOperator(s[i])){
      push(&S, (int)s[i] - '0');

    }else{
      num1 = pop(S);
      num2 = pop(S);
      push(&S, solve(num1, num2, s[i]));
    }
    i++;
  }

  return pop(S);
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else {
        return 0;
    }
}

char *infix_to_postfix(char* infix ) {
    char* postfix;
    postfix = (char *) malloc(sizeof(char) * (50));
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;

    int infix_len = strlen(infix);
    int postfix_index = 0;

    for (int i = 0; i < infix_len; i++) {
        char current_char = infix[i];

        if (current_char == '(') {
            push(&stack, current_char);
        } else if (current_char == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[postfix_index++] = pop(stack);
            }
            pop(stack); // Discard the left parenthesis.
        } else if (current_char >= '0' && current_char <= '9') {
            postfix[postfix_index++] = current_char;
        } else if (isOperator(current_char)) {
            while (!isEmpty(stack) && peek(stack) != '(' &&
                   precedence(current_char) <= precedence(peek(stack))) {
                postfix[postfix_index++] = pop(stack);
            }
            push(&stack, current_char);
        }
    }

    while (!isEmpty(stack)) {
        postfix[postfix_index++] = pop(stack);
    }

    postfix[postfix_index] = '\0';
    return postfix;
}





void enqueue(Queue **Q, int data){
  Queue *temp = *Q;
  Stack *S = (Stack *) malloc(sizeof(Stack));
  S->top = -1;

  if (temp->top == -1 && temp->rear == -1){
    temp->top = 0;
    temp->rear = 0;
  }
else{
    temp->rear = (temp->rear + 1)% MAXSIZE;
  }

  while(temp->set->top != -1){
    push(&S, pop(temp->set));
  }

  push(&(temp->set), data);
  while(S->top != -1){
    push(&(temp->set), pop(S));
  }
  temp->count++;

}

int dequeue(Queue **Q){
  Queue *temp = *Q;
  if(temp->count == 0){
    return -1;
  }

  int lel = pop(temp->set);

  temp->top = (temp->top+1) % MAXSIZE;
  return lel;

}


void displayQ(Queue *Q){

  while(Q->set->top != -1){
    printf("%d", pop(Q->set));
  }

}
