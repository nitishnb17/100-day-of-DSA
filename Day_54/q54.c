#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int val) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void zigzag(struct Node *root) {
    if (root == NULL) return;

    struct Node *queue[100];
    int front = 0, rear = 0;
    int leftToRight = 1;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;
        int level[size];

        for (int i = 0; i < size; i++) {
            struct Node *curr = queue[front++];
            if (leftToRight) level[i] = curr->data;
            else level[size - 1 - i] = curr->data;
            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", level[i]);
        printf("\n");

        leftToRight = !leftToRight;
    }
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Zigzag Traversal:\n");
    zigzag(root);
    return 0;
}
