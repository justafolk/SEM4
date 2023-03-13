#include <stdio.h>
#include <stdlib.h>
#include "./functions.h"

int main(int argc, char *argv){
	
	Tree BST = NULL;
	Tree BT = NULL;

	FILE *fptr;

	fptr = fopen("test.txt", "r");

	int s;
	insertBST(&BST, 3);
	insertBST(&BST, 2);
	insertBST(&BST, 5);
	insertBST(&BST, 1);
	insertBT(&BT, 1);
	insertBST(&BST, 7);
	for(int i = 0; i < 10000; i++){
		fscanf(fptr, "%d",&s );
		insertBT(&BT, s);
		insertBST(&BST, s);
	}

	printf("%d", searchBT(BT, 1));

	return 0;




}

