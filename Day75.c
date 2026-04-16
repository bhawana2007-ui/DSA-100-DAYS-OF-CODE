#include <stdio.h>
#include <stdlib.h>

// A simple hash map using arrays (for demonstration)
// Works well for reasonable input ranges
#define MAX 100000

int maxLenZeroSumSubarray(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Create hash array and initialize with -1
    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum is 0 → subarray from 0 to i
        if (sum == 0) {
            maxLen = i + 1;
        }

        // Shift index to handle negative sums
        int index = sum + MAX;

        // Case 2: sum seen before
        if (hash[index] != -1) {
            int length = i - hash[index];
            if (length > maxLen)
                maxLen = length;
        } else {
            // Store first occurrence
            hash[index] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLenZeroSumSubarray(arr, n);
    printf("%d\n", result);

    return 0;
}