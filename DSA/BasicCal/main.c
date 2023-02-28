#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
  char s[50];
  while(1){
    scanf("%s", &s);
    printf(">>>%d\n", evaluate_postfix(s));
  }
}
