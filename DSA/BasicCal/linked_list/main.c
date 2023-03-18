#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int isnumeric(char s){

  if (s - '0' >= 0 && s - '0' <= 9){
    return 1;
  }
  return 0;
}

int main(){
  //
  // Input
  char* input = NULL;
  size_t size = 0;

  getline(&input, &size, stdin);
  int len = strlen(input);

  // Count of Numbers 
  int i = 0;
  int c = 1;

  while(input[i] != '\n'){
    if (!isnumeric(input[i])){
      c++;
    } 
    i++;
  }

  // Operators
  Node *operators = NULL;

  // Numbers Array
  Number **Lis = (Number **) malloc(sizeof(Number *)*(c+1));


  initNumber(Lis, 0, '+');

  Node *temp ;
  temp = Lis[0]->numbers;

  i = 0;
  int index = 0;
  Node *s;

  while(input[i] != '\n'){
    if(isnumeric(input[i])){
      Lis[index]->count++;
      addElement(&Lis[index]->numbers, input[i]);

      if (!isnumeric(input[i+1])) {
        addElement(&operators, index+'0');

        if (input[i+1] == '(' || input[i+1] == ')'){
          while (input[i+1] == '(' || input[i+1] == ')'){
          addElement(&operators, input[i+1]);
          i++;
        }
          i--;
        }
        if(input[i+1] == '-'){
          addElement(&operators, '+');
          initNumber(Lis, ++index, '-');
        } else {
          addElement(&operators, input[i+1]);
          initNumber(Lis, ++index, '+');
        }
      }
    } 

    i++;
  }

  displayNumbers(Lis, c);
  reverse(&operators);
  display(&operators);

}

