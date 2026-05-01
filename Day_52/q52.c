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

struct Node *lca(struct Node *root, int a, int b) {
    if (root == NULL) return NULL;
    if (root->data == a || root->data == b) return root;
    struct Node *left = lca(root->left, a, b);
    struct Node *right = lca(root->right, a, b);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    struct Node *result = lca(root, 4, 5);
    printf("LCA of 4 and 5: %d\n", result->data);

    result = lca(root, 4, 3);
    printf("LCA of 4 and 3: %d\n", result->data);
    return 0;
}
