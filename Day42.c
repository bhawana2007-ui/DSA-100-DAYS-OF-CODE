#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int queue[n], stack[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    int top = -1;

    // Push queue elements to stack
    for(int i = 0; i < n; i++)
        stack[++top] = queue[i];

    // Pop from stack to print reversed queue
    while(top != -1)
        printf("%d ", stack[top--]);

    return 0;
}