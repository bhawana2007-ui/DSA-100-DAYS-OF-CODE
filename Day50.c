#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int val) {
    if (!root) {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = val;
        n->left = n->right = NULL;
        return n;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

int search(struct Node* root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    int n, x, key;
    struct Node* root = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d", &key);

    if (search(root, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}