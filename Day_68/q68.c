#include <stdio.h>
#define V 6

int graph[V][V];
int indegree[V];
int queue[V];

int main() {
    graph[5][2] = 1;
    graph[5][0] = 1;
    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (graph[i][j]) indegree[j]++;

    int front = 0, rear = 0;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0) queue[rear++] = i;

    printf("Topological Order (Kahn's): ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < V; i++) {
            if (graph[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) queue[rear++] = i;
            }
        }
    }
    printf("\n");

    return 0;
}
