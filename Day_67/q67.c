#include <stdio.h>
#define V 6

int graph[V][V];
int visited[V];
int stack[V];
int top = -1;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < V; i++) {
        if (graph[node][i] && !visited[i])
            dfs(i);
    }
    stack[++top] = node;
}

int main() {
    graph[5][2] = 1;
    graph[5][0] = 1;
    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(i);
    }

    printf("Topological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);
    printf("\n");

    return 0;
}
