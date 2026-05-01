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

int inorder[] = {4, 2, 5, 1, 6, 3, 7};
int postorder[] = {4, 5, 2, 6, 7, 3, 1};
int postIdx;

int search(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (arr[i] == val) return i;
    return -1;
}

struct Node *buildTree(int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;
    int rootVal = postorder[postIdx--];
    struct Node *root = newNode(rootVal);
    int inPos = search(inorder, inStart, inEnd, rootVal);
    root->right = buildTree(inPos + 1, inEnd);
    root->left = buildTree(inStart, inPos - 1);
    return root;
}

void inorderPrint(struct Node *root) {
    if (root == NULL) return;
    inorderPrint(root->left);
    printf("%d ", root->data);
    inorderPrint(root->right);
}

int main() {
    int n = 7;
    postIdx = n - 1;
    struct Node *root = buildTree(0, n - 1);
    printf("Inorder: ");
    inorderPrint(root);
    printf("\n");
    return 0;
}
