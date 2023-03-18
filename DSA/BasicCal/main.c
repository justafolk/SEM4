#include <stdio.h> 
#include <stdlib.h> 
#include "Operations.h"
#include "LinkedList.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "./infix.h"

int isnumeric(char s){

  if (s - '0' >= 0 && s - '0' <= 9){
    return 1;
  }
  return 0;
}

Number **L;

int main(){

  List operators = (List) malloc(sizeof(Node));
  operators->data = INT_MIN;

  char* input = NULL;
  size_t size = 0;

  getline(&input, &size, stdin);
  int len = strlen(input);

  int i = 0;
  int c = 1;

  while(input[i] != '\0'){
    if (!isnumeric(input[i])){
      c++;
    }
    i++;
  }

  char infix[c*3];
  i = 0;
  L = (Number **) malloc(sizeof(Number *)*(12));
  int index = 0;

  L[0] = (Number *) malloc(sizeof(Number ));
  L[0]->numbers = (Node *) malloc(sizeof(Node));
  L[0]->numbers->data = INT_MIN;
  L[0]->numbers->next = NULL;
  L[0]->count = 0;
  List temp = L[0]->numbers;

  if((input[0] == '+') || (input[0] == '-')){
    L[0]->sign = input[0];
    i++;
  } else{
    L[0]->sign = '+';
  }

  while(input[i]=='0'){i++;}
  if(!isnumeric(input[i+1]))
    i--;
  c = 0;

  while(input[i] != '\n'){
    if(isnumeric(input[i])){
      push(&temp, input[i] - '0');
      L[index]->count ++;

    } else if (input[i] == '('){
      if (input[i+1] == '+' || input[i+1] == '-' ){
      }

      push(&operators, input[i]);
    }
    else if (input[i] == ')'){
      push(&operators, '0'+c);
      push(&operators, input[i]);
      c++;
    }
    else{
      push(&operators, '0'+c);
      if (input[i] == '-' || input[i] == '+'){
        push(&operators, '+');
      }
      else {
        push(&operators, input[i]);
      }

      c++;
      reverse(&L[index]->numbers);
      index++;
      L[index] = (Number *) malloc(sizeof(Number ));

      if((input[i+1] == '+') || (input[i+1] == '-') ){
        L[index]->sign = input[i+1];
        i++;
      } else{
        L[index]->sign = '+';
      }

      if (input[i] == '-'){
        L[index]->sign = input[i];
      }

      while(input[i]=='0'){i++;}
      if(!isnumeric(input[i+1]))
        i--;

      L[index]->numbers = (Node *) malloc(sizeof(Node));
      L[index]->numbers->data = INT_MIN;
      L[index]->numbers->next = NULL;
      temp = L[index]->numbers;
    }
    i++;
  }

  if(input[i-1] != ')'){
      push(&operators, '0'+c);
      reverse(&L[index]->numbers);
  }
  i = 0;

  while(operators->next != NULL){
    infix[i] = operators->data;
    operators = operators->next;
    i++;
  }
  infix[i] = operators->data;
  infix[++i] = '\n';

  mulLists(L, 0, 1, '+');

  reverse(&L[1]->numbers);
  displayList(&L[1]->numbers);
// char postfix[50];
// infix_to_postfix(infix, postfix);
//
// printf("%s\n", postfix);
//
//   int rest = eval_postfix(postfix, L);
// printf("%c", L[rest]->sign);
// displayList(&L[rest]->numbers);

}
