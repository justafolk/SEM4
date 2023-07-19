#include "graph.h"

int main(){

  Graph G;
  initGraph(&G, "input.txt");
  displayGraph(G);
  BFS(G, 0);
  printf("\n");
  DFS(G, 0);

  Sp_Tree t = Prims(G, 0);
  printf("\n");

  displaySPtree(t, G.n);
}
