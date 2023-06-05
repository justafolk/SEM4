#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h"

void main()
{
    Graph g;
    initGraph(&g);
    printf("\n\n1] BFS Traversal:\n\n");
    bfsTraversal(g,0,1);
    printf("\n\n2] Degree of Vertices:\n");
    degreeOfVertex(g);
    printf("\n\n3] Is vertex %d adjacent to vertex %d:\t%d\n\n",0,3,adjacentVertices(g,0,3));
    printf("\n4] Components of graph are:\n\n");
    int *visited=visited=(int *)calloc(g.size,sizeof(int));
    componentsOfGraph(g,0,visited);
    printf("\n\n5] Cycles in the graph:\n\n");
    detectCycle(g); 
}