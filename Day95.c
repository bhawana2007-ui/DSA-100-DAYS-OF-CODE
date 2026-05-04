#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
struct Node {
    float data;
    struct Node* next;
};

// Insert in sorted order (for stability)
struct Node* insertSorted(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        return newNode;
    }

    struct Node* curr = head;
    while (curr->next != NULL && curr->next->data < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

void bucketSort(float arr[], int n) {
    // Step 1: Create buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Step 2: Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(buckets);
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}