typedef struct graph{
    int **array;
    int size;
}Graph;

void initGraph(Graph *g);
void bfsTraversal(Graph g,int start_vertex,int bit);
void degreeOfVertex(Graph g);
int adjacentVertices(Graph g,int vertexA,int vertexB);
void detectCycle(Graph g);
void componentsOfGraph(Graph g,int startVertex,int *visited);


