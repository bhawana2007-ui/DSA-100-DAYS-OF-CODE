#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Queue node for level-order construction
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

// Queue structure
typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

// Queue functions
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Create a new tree node
Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Construct tree from level-order
Node* constructTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = createNode(arr[0]);
    Queue* q = createQueue();
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        Node* current = dequeue(q);
        if (!current) continue;

        // Left child
        current->left = createNode(arr[i++]);
        if (current->left) enqueue(q, current->left);

        // Right child
        if (i < n) {
            current->right = createNode(arr[i++]);
            if (current->right) enqueue(q, current->right);
        }
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Free tree memory
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node* root = constructTree(arr, n);

    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}