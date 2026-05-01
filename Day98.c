#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort (sort by start time)
int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    // Allocate memory for intervals
    int** arr = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    // Sort intervals by start time
    qsort(arr, n, sizeof(int*), cmp);

    // Result array
    int** res = (int**)malloc(n * sizeof(int*));
    int idx = 0;

    // First interval
    res[idx] = (int*)malloc(2 * sizeof(int));
    res[idx][0] = arr[0][0];
    res[idx][1] = arr[0][1];

    for (int i = 1; i < n; i++) {

        // Overlapping case
        if (arr[i][0] <= res[idx][1]) {
            if (arr[i][1] > res[idx][1]) {
                res[idx][1] = arr[i][1];
            }
        }
        // Non-overlapping case
        else {
            idx++;
            res[idx] = (int*)malloc(2 * sizeof(int));
            res[idx][0] = arr[i][0];
            res[idx][1] = arr[i][1];
        }
    }

    // Output result
    printf("\nMerged Intervals:\n");
    for (int i = 0; i <= idx; i++) {
        printf("[%d, %d]\n", res[i][0], res[i][1]);
    }

    return 0;
}