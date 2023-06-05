#include "graph.h"


void initGraph(Graph *G, char *filename){

	FILE *f = fopen(filename, "r");

	if (!f) return;

	fscanf(f, "%d", &G->n);

	G->A = (node **) malloc(sizeof(node *)*G->n);

	int st;
	for (int i = 0; i < G->n; i++){
		G->A[i] = NULL;

		for (int j = 0; j < G->n; j++){

			fscanf(f, "%d", &st);
			if (st){
				node *temp = (node *) malloc(sizeof(node));
				temp->weight = st;
				temp->j = j;

				temp->next = G->A[i];
				G->A[i] = temp;

			}
		}
	}

	return;
}

void displayGraph(Graph S){

	node *temp;
	for(int i = 0; i < S.n ; i++){
		temp = S.A[i];
		printf("%d : ", i+1);
		while(temp){
			printf("%d=>%d\t", temp->j+1, temp->weight );
			temp = temp->next;
		}
		printf("\n");
	}
	return;
}


void BFS(Graph g, int s){

	int *visited = (int *) calloc(sizeof(int), g.n);
	visited[s] = 1;

	Queue q; 
	initQueue(&q);

	enqueue(q, s);
	node *temp;
	while(q->rear) {

		s = dequeue(q);
		temp = g.A[s];
		while(temp){
			if(!visited[temp->j]) {
				enqueue(q,temp->j);
				visited[temp->j]=1;
			}
			temp = temp->next;

		}
		printf("%d\t",s+1);
	}


	return ;
}

void DFS(Graph G, int s){

	int *visited = (int *)calloc(sizeof(int), G.n);

	struct Stack *S = createStack(100);

	visited[s] = 1;
	push(S, s);

	node *temp;

	while(!isEmpty(S)){
		s = pop(S);

		printf("%d\t", s+1);

		temp = G.A[s];
		while(temp){
			if(!visited[temp->j]) {
				push(S, temp->j);
				visited[temp->j]=1;
			}
			temp = temp->next;

		}

	}

	return ;
}


Sp_Tree Prims(Graph G, int s){
	Sp_Tree t = (node **) malloc(sizeof(node *) * G.n);

	if (!t)
		return NULL;

	int *visited = (int *) calloc(G.n, (sizeof(int)));
	if (!visited){
		free(t);
		return NULL;
	}

	visited[s] = 1;

	int minv = G.n + 1;
	int min = INT_MAX;

	for(int i = 0; i < G.n ; i++){
		t[i] = NULL;

	}
	int prev_p = INT_MIN;
	int p ;
	node *temp;
	for(int i = 0; i < G.n-1 ; i++){
		min = INT_MAX;
		for(p = 0; p < G.n ; p++){
			if(visited[p]){
				temp = G.A[p];
				while(temp){
					if (!visited[temp->j]){
						if (temp->weight < min ){
							min = temp->weight;
							minv = temp->j;
							prev_p = p;
						}
					}
					temp = temp->next;
				}
			}
		}

		node *nn = (node *) malloc(sizeof(node));
		if (!nn) return NULL;
		nn->j = minv;
		nn->weight = min;
		nn->next = t[prev_p];
		t[prev_p] = nn;
		visited[minv] = 1;
	}
	return t;
}

void displaySPtree(Sp_Tree S, int n){

	node *temp;
	int cost = 0;
	printf("SPANNING TREE:\n");
	for(int i = 0; i < n ; i++){
		temp = S[i];
		printf("%d : ", i+1);
		while(temp){
			printf("%d=> %d\t", temp->j+1, temp->weight );
			cost += temp->weight;
			temp = temp->next;
		}
		printf("\n");
	}
	printf("COST => %d\n", cost);

	return;
}
