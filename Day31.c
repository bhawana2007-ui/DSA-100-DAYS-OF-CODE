#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

// Display operation (Top to Bottom)
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, operation, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &operation);

        if (operation == 1) {
            scanf("%d", &value);
            push(value);
        }
        else if (operation == 2) {
            pop();
        }
        else if (operation == 3) {
            display();
        }
    }

    return 0;
}