#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 10 

typedef struct {
    int weight[MAX_VERTICES][MAX_VERTICES]; 
    int n;
} GraphType;

void graph_init(GraphType* g) {
    g->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->weight[i][j] = 0;
        }
    }
}

void GenerateGraph(GraphType* g) {
    g->n = 10; 

    g->weight[0][1] = 12; g->weight[1][0] = 12;
    g->weight[0][5] = 11; g->weight[5][0] = 11;
    g->weight[1][2] = 7;  g->weight[2][1] = 7;
    g->weight[1][5] = 5;  g->weight[5][1] = 5;
    g->weight[2][3] = 6;  g->weight[3][2] = 6;
    g->weight[2][4] = 3;  g->weight[4][2] = 3;
    g->weight[3][4] = 4;  g->weight[4][3] = 4;
    g->weight[4][8] = 2;  g->weight[8][4] = 2;
    g->weight[8][9] = 10; g->weight[9][8] = 10;
}

void FindPrimMST(GraphType* g) {
    int selected[MAX_VERTICES] = { 0 }; 
    int minWeight[MAX_VERTICES];
    int parent[MAX_VERTICES]; 

    for (int i = 0; i < g->n; i++) {
        minWeight[i] = INT_MAX; 
        parent[i] = -1;
    }

    minWeight[0] = 0; 
    selected[0] = 1;

    printf("Prim MST Algorithm\n");
    printf("정점 1 추가\n"); 

    for (int i = 0; i < g->n - 1; i++) {
        int u = -1;
        int min = INT_MAX;

        for (int v = 0; v < g->n; v++) {
            if (!selected[v] && minWeight[v] < min) {
                min = minWeight[v];
                u = v;
            }
        }

        selected[u] = 1;

        printf("정점 %d 추가\n", u + 1); 

        for (int v = 0; v < g->n; v++) {
            if (g->weight[u][v] && !selected[v] && g->weight[u][v] < minWeight[v]) {
                minWeight[v] = g->weight[u][v];
                parent[v] = u;
            }
        }
    }
}

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);

    GenerateGraph(g);

    FindPrimMST(g);

    free(g);
    return 0;
}
