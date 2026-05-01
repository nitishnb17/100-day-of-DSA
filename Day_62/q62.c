#include <stdio.h>
#include <stdlib.h>

#define V 5

struct Node {
    int data;
    struct Node *next;
};

struct Node *adjList[V];

struct Node *newNode(int val) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

void addEdge(int u, int v) {
    struct Node *node = newNode(v);
    node->next = adjList[u];
    adjList[u] = node;

    node = newNode(u);
    node->next = adjList[v];
    adjList[v] = node;
}

void display() {
    for (int i = 0; i < V; i++) {
        printf("%d -> ", i);
        struct Node *temp = adjList[i];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < V; i++) adjList[i] = NULL;
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(3, 4);
    display();
    return 0;
}
