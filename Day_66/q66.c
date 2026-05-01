#include <stdio.h>
#define V 5

int graph[V][V];
int visited[V];
int recStack[V];

int dfsCycle(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfsCycle(i)) return 1;
            else if (recStack[i]) return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;
    graph[3][4] = 1;

    int hasCycle = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dfsCycle(i)) {
            hasCycle = 1;
            break;
        }
    }

    if (hasCycle) printf("Cycle detected in directed graph\n");
    else printf("No cycle in directed graph\n");

    return 0;
}
