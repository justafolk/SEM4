#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "queue.h"

typedef struct graph{
  int **A;
  int n;
} graph;
typedef struct node {
	int j, w;
	struct node *next;
} node;

typedef node **Sp_Tree;

void displaySPtree(Sp_Tree S, int n);

Sp_Tree Prims(graph G, int s);

void initGraph(graph *G, char *filename);
void displayGraph(graph G);
void displayDegree(graph G);

int BFS(graph G, int s);

void DFS(graph G, int s);
void connectedComponents(graph g);

int isAdjacent(graph G, int v1, int v2);

Sp_Tree Kruskals(graph G, int s);

int *dijkstra(graph G, int src) ;
