#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order tree construction
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[++q->front];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node* root = createNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Node* current = dequeue(&q);

        // Left child
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    int leafCount = countLeafNodes(root);
    printf("%d\n", leafCount);

    return 0;
}