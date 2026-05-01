#include <stdio.h>
#include <limits.h>
#define V 5

int graph[V][V];
int dist[V];
int visited[V];

int minDistance() {
    int min = INT_MAX, minIdx = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void dijkstra(int src) {
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance();
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from node %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("  Node %d -> %d\n", i, dist[i]);
}

int main() {
    graph[0][1] = 10; graph[1][0] = 10;
    graph[0][2] = 3;  graph[2][0] = 3;
    graph[1][2] = 1;  graph[2][1] = 1;
    graph[1][3] = 2;  graph[3][1] = 2;
    graph[2][3] = 8;  graph[3][2] = 8;
    graph[2][4] = 2;  graph[4][2] = 2;
    graph[3][4] = 5;  graph[4][3] = 5;

    dijkstra(0);
    return 0;
}
