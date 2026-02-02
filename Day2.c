//Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.
#include <stdio.h>

int main() {
    int n, pos, i;
    int a[100];

    // Read number of elements
    scanf("%d", &n);

    // Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Read position to delete (1-based)
    scanf("%d", &pos);

    // Check for valid position
    if (pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    // Shift elements to the left
    for (i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    // Print updated array
    for (i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}