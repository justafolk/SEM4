
#include <ctype.h>
#include <stdio.h>
#include "./LinkedList.h"
#include "./Operations.h"

char s[250];
int top = -1; /* Global declarations */

/* Function to remove spaces from given string */
void RemoveSpaces(char* source) {
  char* i = source;
  char* j = source;
  while(*j != 0) {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

/* Function for pushStack operation */
void pushStack(char elem) { 
  s[++top] = elem;
}

/* Function for popStack operation */
char popStack() { 
  return (s[top--]);
}

/* Function for precedence */
int pr(char elem) { 
  switch (elem) {
    case '#':
      return 0;
    case '(':
      return 1;
    case '+':
    case '-':
      return 2;
    case '*':
    case '/':
      return 3;
  }
}

/*
* Function to convert from infix to postfix expression
*/
void infix_to_postfix(char *infix, char *postfix) {
  char ch, elem;
  int i = 0, k = 0;

  RemoveSpaces(infix);
  pushStack('#');

  while ((ch = infix[i++]) != '\n') {
    if (ch == '(')
      pushStack(ch);
    else if (isalnum(ch))
        postfix[k++] = ch;
      else if (ch == ')') {
          while (s[top] != '(')
            postfix[k++] = popStack();
          elem = popStack(); /* Remove ( */
        } else { /* Operator */
          while (pr(s[top]) >= pr(ch))
            postfix[k++] = popStack();
          pushStack(ch);
        }
  }

  while (s[top] != '#') /* popStack from stack till empty */
    postfix[k++] = popStack();

  postfix[k] = 0; /* Make postfix as valid string */
}

void solve(int op1, int op2, char ch, Number **L){
  switch(ch) {
    case '+' : 
      pushStack(addLists(L, op1, op2, L[op1]->sign));
      break;
    case '-' : 
      if (L[op1]->count >= L[op2]->count || (L[op1]->numbers->data > L[op2]->numbers->data)) {
        pushStack(subLists(L, op1, op2, L[op1]->sign));

      } else if (L[op1]->count >= L[op2]->count && (L[op1]->numbers->data < L[op2]->numbers->data)) {
        pushStack(subLists(L, op2, op1, L[op2]->sign));

      } else{
        pushStack(subLists(L, op2, op1, '-'));
      }

      break;
    case '*' : pushStack(op1*op2);
      break;
    case '/' : pushStack(op1/op2);
      break;
  }


}

int eval_postfix(char *postfix, Number **L) {
  char ch;
  int i = 0, op1, op2;
  while((ch = postfix[i++]) != 0) {
    if(isdigit(ch)) 
      pushStack(ch-'0'); /* pushStack the operand */
    else {        /* Operator,popStack two  operands */
        op2 = popStack();
        op1 = popStack();

        if((ch == '+') && (L[op1]->sign == L[op2]->sign )){
          solve(op1, op2, '+', L);
        } else if((ch == '-') || (L[op1]->sign != L[op2]->sign) ){
          solve(op1, op2, '-', L);
        }

      }
  }

  reverse(&L[s[top]]->numbers);
  return s[top];
}

// int main() { /* Main Program */
//   
//   char infx[50], pofx[50];
//   printf("\nInput the infix expression: ");
//   fgets(infx, 50, stdin);
//   
//   infix_to_postfix(infx, pofx);
//
//   printf("\nResult of evaluation of postfix expression : %d", eval_postfix(pofx));
// }
