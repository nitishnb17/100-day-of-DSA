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

struct Node *buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node *queue[100];
    int front = 0, rear = 0;
    struct Node *root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node *curr = queue[front++];
        if (i < n) { curr->left = newNode(arr[i++]); queue[rear++] = curr->left; }
        if (i < n) { curr->right = newNode(arr[i++]); queue[rear++] = curr->right; }
    }
    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    struct Node *root = buildTree(arr, n);
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    return 0;
}
