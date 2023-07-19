#include "graph.h"
#include "stack.h"

void initGraph(graph *G, char *filename){
    FILE *f = fopen(filename, "r");

    if (!f) return;

    fscanf(f, "%d", &G->n);

    G->A = (int **) malloc(sizeof(int *)*G->n);

    for (int i = 0; i < G->n; i++){
        G->A[i] = (int *) malloc(sizeof(int)*G->n);

        if (!G->A[i]) return;

        for (int j = 0; j < G->n; j++){
            fscanf(f, "%d", &G->A[i][j]);
        }
    }

    return;
}


void displayGraph(graph G){

    for (int i = 0; i < G.n; i++){
        for (int j = 0; j < G.n; j++){
            printf("%d\t", G.A[i][j]);

        }
        printf("\n");
    }

    return;
}

void displayDegree(graph G){

    int tempSum;

    for (int i = 0; i < G.n; i++){
        tempSum = 0;
        for (int j = 0; j < G.n; j++){
            if (G.A[i][j])
                tempSum++;
        }
        printf("Degree of Vertex %d is %d\n", i+1, tempSum);
    }

    return;

}

int BFS(graph g, int s){

    int *visited = (int *) calloc(sizeof(int), g.n);
    visited[s] = 1;

    Queue q; 
    initQueue(&q);

    enqueue(q, s);
    while(q->rear) {

        s = dequeue(q);
        for(int i = 0; i < g.n ; i++) {   
            if(g.A[s][i]!=0 && visited[i]==0) {
                enqueue(q,i);
                visited[i]=1;
            }
        }
        printf("%d\t",s+1);

    }

    for(int i = 0 ; i < g.n ; i++) {

        if( visited[i] == 0 ) {
            return 0;
        }
    }

    return 1;
}



void connectedComponents(graph g){

    int *visited = (int *) calloc(sizeof(int), g.n);

    visited[0] = 1;
    int x = 0;

    int s = 0;


    Queue q; 
    initQueue(&q);
    while(x < g.n){
        enqueue(q, x);

        s = x;
        while(q->rear) {

            for(int i = 0; i < g.n ; i++) {   
                if(g.A[s][i]!=0 && visited[i]==0) {
                    enqueue(q,i);
                    visited[i]=1;
                }
            }
            printf("%d\t",q->front->data+1);

            dequeue(q);
            if(q->front)
                s = q->front->data;
        }

        x++;

        while(x < g.n && visited[x]) x++;

    }
}



int isAdjacent(graph G, int v1, int v2){
    return G.A[v1][v2];
}

void DFS(graph G, int s){

    int *visited = (int *)calloc(sizeof(int), G.n);

    struct Stack *S = createStack(100);

    visited[s] = 1;
    push(S, s);

    while(!isEmpty(S)){
        s = pop(S);

        printf("%d\t", s+1);

        for (int i = 0; i < G.n; i++){
            if (G.A[s][i] && !visited[i]){
                push(S, i);
                visited[i] = 1;
            }
        }

    }

    return ;
}



Sp_Tree Prims(graph G, int s){
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
    for(int i = 0; i < G.n-1 ; i++){
        min = INT_MAX;
        for(p = 0; p < G.n ; p++){
            if(visited[p]){
                for(int j = 0; j < G.n ; j++){
                    if (G.A[p][j] && !visited[j]){
                        if (G.A[p][j] < min && G.A[p][j] > 0){
                            min = G.A[p][j];
                            minv = j;
                            prev_p = p;
                        }
                    }
                }
            }
        }

        node *nn = (node *) malloc(sizeof(node));
        if (!nn) return NULL;
        nn->j = minv;
        nn->w = min;
        nn->next = t[prev_p];
        t[prev_p] = nn;
        visited[minv] = 1;
    }
    return t;
}

void displaySPtree(Sp_Tree S, int n){

    node *temp;
    for(int i = 0; i < n ; i++){
        temp = S[i];
        printf("%d : ", i+1);
        while(temp){
            printf("%d %d\t", temp->j+1, temp->w );
            temp = temp->next;
        }
        printf("\n");
    }

    return;

}

int findParent(int arr[], int i){
    if (arr[i] == i)
        return i;

    return findParent(arr, arr[i]);
}



void applyUnion(int belongs[],int n, int c1, int c2) {

    int i = findParent(belongs, c1);
    int j = findParent(belongs, c2);

    if (belongs[i] < belongs[j])
        belongs[i] = j;
    else if (belongs[i] > belongs[j])
            belongs[j] = i;
        else 
            belongs[j] = i;
}
Sp_Tree Kruskals(graph G, int s){

    int res[G.n*G.n][3];
    int rescount = 0;

    for (int i = 1; i < G.n; i++){
        for (int j = 0; j < i; j++){
            if (G.A[i][j]){

                res[rescount][0] = i;
                res[rescount][1] = j;
                res[rescount][2] = G.A[i][j];
                rescount++;

            }
        }
    }


    // Sorting by weight
    int temp[3];
    for (int i = 1; i < rescount; i++){
        for (int j = 0; j < rescount - 1; j++)
            if (res[j][2] > res[j + 1][2]) {

                for (int k = 0; k<3; k++)
                    temp[k] = res[j+1][k];

                for (int k = 0; k<3; k++)
                    res[j][k] = res[j+1][k];

                for (int k = 0; k<3; k++)
                    res[j+1][k] = temp[k];
            }
    }


    int belongs[G.n];

    for (int i = 0; i < G.n; i++)
        belongs[i] = i;


    Sp_Tree t = (node **) malloc(sizeof(node *) * G.n);

    for(int i = 0; i < G.n ; i++){
        t[i] = NULL;
    }
    int count = 0;

    int c1, c2;
    for (int i = 0; i < rescount; i++) {
        c1 = findParent(belongs, res[i][0]);
        c2 = findParent(belongs, res[i][1]);

        if (c1 != c2) {

            node *nn = (node *) malloc(sizeof(node));
            if (!nn) return NULL;
            nn->j = res[i][1];
            nn->w = res[i][2];
            nn->next = t[res[i][0]];
            t[res[i][0]] = nn;

            count++;
            applyUnion(belongs,G.n, c1, c2);
        }
    }

    return t;
}

int *dijkstra(graph G, int src) {

    int res[G.n];

    int *visited = (int *) calloc(sizeof(int), G.n);

    for (int i = 0; i < G.n; i++)
        res[i] = INT_MAX;

    res[src] = 0;


    int min = INT_MAX;
    int min_index;
    int u;
    for (int i = 0; i < G.n - 1; i++){

        min = INT_MAX;
        for (int j = 0; j < G.n ; j++){
            if (!visited && res[j] <= min){

                min = res[j];
                min_index = j;

            }
        }

        u = min_index;

        visited[u] = 1;

        for (int v = 0; v < G.n; v++){

            if (!visited[u] && G.A[u][v] && res[u] != INT_MAX && res[u]+G.A[u][v] < res[v])
                res[v] = res[u] + G.A[u][v];
        }
    }
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < G.n; i++)
        printf("%d \t\t\t\t %d\n", i, res[i]);

    return res;




}

