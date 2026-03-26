#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order (-1 = NULL)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[MAX];
    int front = 0, rear = 0;

    q[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = q[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[rear++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

// Zigzag traversal
void zigzag(struct Node* root) {
    if (!root) return;

    struct Node* q[MAX];
    int front = 0, rear = 0;

    q[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int arr[size];

        for (int i = 0; i < size; i++) {
            struct Node* temp = q[front++];
            arr[i] = temp->data;

            if (temp->left)  q[rear++] = temp->left;
            if (temp->right) q[rear++] = temp->right;
        }

        // Print level
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", arr[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", arr[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzag(root);

    return 0;
}