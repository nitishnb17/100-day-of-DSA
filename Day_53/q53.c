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

#define MAX 200

int cols[MAX];
int vals[MAX][MAX];
int colCount[MAX];
int minCol, maxCol;

void fillMap(struct Node *root, int col) {
    if (root == NULL) return;
    if (col < minCol) minCol = col;
    if (col > maxCol) maxCol = col;
    int idx = col + 100;
    vals[idx][colCount[idx]++] = root->data;
    fillMap(root->left, col - 1);
    fillMap(root->right, col + 1);
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    minCol = 0; maxCol = 0;
    fillMap(root, 0);

    printf("Vertical Order Traversal:\n");
    for (int c = minCol; c <= maxCol; c++) {
        int idx = c + 100;
        for (int i = 0; i < colCount[idx]; i++)
            printf("%d ", vals[idx][i]);
        printf("\n");
    }
    return 0;
}
