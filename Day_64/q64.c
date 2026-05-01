#include <stdio.h>
#define V 6

int graph[V][V];
int visited[V];
int queue[V];
int front = 0, rear = 0;

void bfs(int start) {
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < V; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int edges[][2] = {{0,1},{0,2},{1,3},{2,4},{3,5}};
    int n = 5;

    for (int i = 0; i < n; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    printf("BFS from node 0: ");
    bfs(0);
    printf("\n");
    return 0;
}
