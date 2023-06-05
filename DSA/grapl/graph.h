#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <limits.h>

typedef struct node{
  int j;
  int weight;
  struct node *next;
} node;

typedef struct graph{
  node **A;
  int n;
} Graph;


typedef node **Sp_Tree;

void initGraph(Graph *G, char *filename);
void displayGraph(Graph S);
void BFS(Graph g, int s);

void DFS(Graph G, int s);


void displaySPtree(Sp_Tree S, int n);

Sp_Tree Prims(Graph G, int s);
