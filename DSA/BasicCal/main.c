#include <stdio.h> 
#include <stdlib.h> 
#include "Operations.h"
#include "LinkedList.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int isnumeric(char s){
  if (s - '0' >= 0 && s - '0' <= 9){
    return 1;
  }
  return 0;
}


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

  char a[c+c];
  i = 0;
  Number **L = (Number** ) malloc(sizeof(Number *)*c);
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

  c = 0;

  while(input[i] != '\n'){
    if(isnumeric(input[i])){
      push(&temp, input[i] - '0');

      L[index]->count ++;
    } else if (input[i] == '('){

      push(&operators, input[i]);
    }
    else if (input[i] == ')'){
      push(&operators, '0'+c);
      push(&operators, input[i]);
      c++;
    }
    else{

      push(&operators, '0'+c);
      push(&operators, input[i]);
      c++;
      reverse(&L[index]->numbers);
      index++;
      L[index] = (Number *) malloc(sizeof(Number ));

      if((input[i+1] == '+') || (input[i+1] == '-')){
        L[index]->sign = input[0];
        i++;
      } else{
        L[index]->sign = '+';
      }

      L[index]->numbers = (Node *) malloc(sizeof(Node));
      L[index]->numbers->data = INT_MIN;
      L[index]->numbers->next = NULL;
      temp = L[index]->numbers;
    }
    i++;
  }

  printf("%d", L[0]->count);
  if(input[i-1] != ')'){
      push(&operators, '0'+c);
  }


  i = 0;
  printf("%c ->%c", L[0]->sign, L[1]->sign);
  printf("\n");
  while (i<index){

    printf("%c->", a[i]);
    i++;
  }
  printf("\n");

  displayListc(&operators);
  printf("\n\n");
  reverse(&L[1]->numbers);
  displayList(&L[0]->numbers);
  displayList(&L[1]->numbers);

  L[2] = (Number *) malloc(sizeof(Number));
  L[2] = addLists(L[0], L[1]);
  reverse(&L[2]->numbers);
  displayList(&L[2]->numbers);

  printf("The string entered is: %s\n", input);

}
