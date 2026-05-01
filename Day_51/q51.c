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

struct Node *insert(struct Node *root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

struct Node *lca(struct Node *root, int a, int b) {
    if (root == NULL) return NULL;
    if (a < root->data && b < root->data) return lca(root->left, a, b);
    if (a > root->data && b > root->data) return lca(root->right, a, b);
    return root;
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);

    struct Node *result = lca(root, 5, 15);
    printf("LCA of 5 and 15: %d\n", result->data);

    result = lca(root, 5, 30);
    printf("LCA of 5 and 30: %d\n", result->data);
    return 0;
}
