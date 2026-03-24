#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Find LCA
struct Node* LCA(struct Node* root, int a, int b) {
    if (root == NULL) return NULL;

    if (root->data == a || root->data == b)
        return root;

    struct Node* left = LCA(root->left, a, b);
    struct Node* right = LCA(root->right, a, b);

    if (left && right) return root;

    return left ? left : right;
}

int main() {
    // Hardcoded tree (same as example)
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int a = 4, b = 5;

    struct Node* ans = LCA(root, a, b);
    printf("%d", ans->data);

    return 0;
}