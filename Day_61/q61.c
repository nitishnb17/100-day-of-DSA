#include <stdio.h>
#define V 5

int graph[V][V];

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void display() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main() {
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);
    display();
    return 0;
}
