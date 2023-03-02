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

  printf("Enter a string: ");
  getline(&input, &size, stdin);
  int len = strlen(input);
  List *L = (List* ) malloc(sizeof(Node *)*25);

  int i = 0;
  int index = 0;

  L[0] = (List) malloc(sizeof(Node ));
  L[0]->data = INT_MIN;
  List temp = L[0];
  while(i < len){
    if(isnumeric(input[i])){
      push(&temp, input[i] - '0');
    } else{
      push(&operators, input[i]);
      index++;
      L[index] = (List) malloc(sizeof(Node ));
      L[index]->data = INT_MIN;
      temp = L[index];
    }
    i++;
  }
  displayList(&L[0]);
  displayList(&L[1]);
  reverse(&L[0]);
  reverse(&L[1]);

  L[2] = addLists(&L[0], &L[1]);
  reverse(&L[2]);
  displayList(&L[2]);

  char* arr = (char*) malloc((len + 1) * sizeof(char));
  strcpy(arr, input);

  printf("The string entered is: %s\n", arr);

}
