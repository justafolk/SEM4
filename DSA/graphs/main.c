#include "graph.h"
#include "stack.h"

int main(){

   graph G;
   initGraph(&G, "input.txt");
   displayGraph(G);
   displayDegree(G);

   if (BFS(G, 0)){
     printf("\nGraph is Connected\n");
   } else{
     printf("\nGraph is not Connected\n");
   }
   connectedComponents(G);


   if (isAdjacent(G, 0, 0)){
     printf("\nNodes are adjacent\n");
   } else{
     printf("\nNodes are not adjacent\n");
   }

  DFS(G, 0);

  Sp_Tree S = Prims(G, 0);
  printf("\n");
  displaySPtree(S, G.n);

	return 0;

}
