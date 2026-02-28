#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end in circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;   // Point to itself
        return;
    }

    struct Node* temp = *head;

    // Traverse to last node
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;  // Last node points to head
}

// Traverse circular linked list
void traverse(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop when we reach head again
}

int main() {
    int n, value;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    traverse(head);

    return 0;
}