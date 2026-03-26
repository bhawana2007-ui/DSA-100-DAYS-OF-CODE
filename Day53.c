#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Simple vertical order
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Node* q[MAX];
    int hd[MAX], front = 0, rear = 0;

    int map[MAX][MAX], count[MAX] = {0};
    int offset = MAX/2;

    q[rear] = root;
    hd[rear++] = 0;

    while (front < rear) {
        struct Node* temp = q[front];
        int h = hd[front++] + offset;

        map[h][count[h]++] = temp->data;

        if (temp->left) {
            q[rear] = temp->left;
            hd[rear++] = h - offset - 1;
        }
        if (temp->right) {
            q[rear] = temp->right;
            hd[rear++] = h - offset + 1;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (count[i]) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }
}

int main() {
    // Example tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    verticalOrder(root);
    return 0;
}