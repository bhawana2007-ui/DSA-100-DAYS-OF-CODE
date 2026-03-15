#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

// Dequeue operation
int dequeue() {
    if (front == NULL)
        return -1;

    struct Node* temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'e') {   // enqueue
            scanf("%d", &x);
            enqueue(x);
        } 
        else if (op[0] == 'd') { // dequeue
            printf("%d\n", dequeue());
        }
    }

    return 0;
}