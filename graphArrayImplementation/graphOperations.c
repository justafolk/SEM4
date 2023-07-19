#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h"
#include"queue\queueOperations.c"

void initGraph(Graph *g)
{
    int i,j,bit;
    // g=(Graph *)malloc(sizeof(Graph));
    FILE *ptr=fopen("input.txt","r");
    if(!ptr)    return;
    int size;
    fscanf(ptr,"%d",&size);
    (*g).size=size;
    (*g).array= (int **)malloc((*g).size * sizeof(int *));
    for(i=0;i<g->size;i++)
    {
    
        (*g).array[i]=(int *)malloc((*g).size * sizeof(int));
        for(j=0;j< (*g).size;j++)
        {

            fscanf(ptr,"%d",&((*g).array[i][j]));   
        }
    }
    fclose(ptr);
    return;

}
void bfsTraversal(Graph g,int start_vertex,int bit)   
/*bit = 1 -> isconnected
        2 -> detect cycle*/
{
    int i=0;
    int *visitedNodes=(int *)calloc(g.size,sizeof(int));
    Queue q;
    init(&q);
    enqueue(&q,start_vertex);
    visitedNodes[start_vertex]=1;
    // display(q);
    while(q.rear) {
        for(i=0;i<g.size;i++) {   
        
            if(g.array[start_vertex][i]!=0 && visitedNodes[i]==0) {
                enqueue(&q,i);
                visitedNodes[i]=1;
            }
        }
        
        printf("%d\t",q.front->data);
        dequeue(&q);
        if(q.front)
        start_vertex=q.front->data;
    }
    if(bit==1){
        for(i=0;i<g.size;i++) {
            if(visitedNodes[i]==0) {
                printf("\n\nGraph is not Connected");
                return;
            }
    
        }
    
    printf("\n\nGraph is Connected");
    }
    return;

}

void degreeOfVertex(Graph g)
{
    int count=0;
    for(int i=0;i<g.size;i++)
    {
        for(int j=0;j<g.size;j++)
        {
            if(g.array[i][j]!=0)
                count++;
        }
        printf("\nvertex %d has degree %d",i,count);
        count=0;
    }

}

int adjacentVertices(Graph g,int vertexA,int vertexB){

    if(g.array[vertexA][vertexB]!=0)
    return 1;
    else
    return 0;

}


void componentsOfGraph(Graph g,int startVertex,int *visitedNodes)
{
    int i;
    Queue q;
    init(&q);
    enqueue(&q,startVertex);
    visitedNodes[startVertex]=1;
    // display(q);
    while(q.rear)
    {
        for(i=0;i<g.size;i++)
        {   
        
            if(g.array[startVertex][i]!=0 && visitedNodes[i]==0)
            {
                enqueue(&q,i);
                visitedNodes[i]=1;
            }
        }
        
        printf("%d\t->\t",q.front->data);
        dequeue(&q);
        if(q.front)
        startVertex=q.front->data;
    }
     for(i=0;i<g.size;i++)
        {
            if(visitedNodes[i]!=1)
            {
                printf("\n\n");
                componentsOfGraph(g,i,visitedNodes);
                printf("\n\n");

            }
        }
}
void detectCycle(Graph g)
{
   int *visited=visited=(int *)calloc(g.size,sizeof(int));
   int i=0,j,flag;
   Queue q;
   init(&q);
   enqueue(&q,0);
   visited[0]=1;
   
        for(j=0;j<g.size;j++)
        {
            if(g.array[i][j]!=0)
            {
                if(visited[j])
                {
                    printf("\n");
                    display(q);
                    printf("\n");
                    break;
                }
                enqueue(&q,j);
                visited[i]=1;
                i=j;
            }
        }
        display(q);
}
   

    
