#include <stdio.h>
#define V 5

int graph[V][V];
int visited[V];

int dfsCycle(int node, int parent) {
    visited[node] = 1;
    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {
            if (!visited[i]) {
                if (dfsCycle(i, node)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int edges[][2] = {{0,1},{1,2},{2,3},{3,4},{4,1}};
    int n = 5;

    for (int i = 0; i < n; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    if (dfsCycle(0, -1)) printf("Cycle detected\n");
    else printf("No cycle\n");

    return 0;
}
