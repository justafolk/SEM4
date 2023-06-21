#include <stdio.h>
#include <stdlib.h>
#include "./functions.h"

int main(){
	
	Tree BST = NULL;
	Tree BT = NULL;

	FILE *fptr;

	fptr = fopen("test.txt", "r");

	int s;
	insertBT(&BT, 1);
	insertBST(&BST, 7);
	for(int i = 0; i < 10000; i++){
		fscanf(fptr, "%d",&s );
		insertBT(&BT, s);
		insertBST(&BST, s);
	}


	return 0;
}

