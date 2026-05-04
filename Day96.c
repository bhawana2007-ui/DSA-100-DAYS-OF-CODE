#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    long long inv_count = 0;

    int *temp = (int *)malloc((right - left + 1) * sizeof(int));

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // count inversions
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // Copy back
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }

    free(temp);
    return inv_count;
}

long long mergeSort(int arr[], int left, int right) {
    long long inv_count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }

    return inv_count;
}

long long countInversions(int arr[], int n) {
    return mergeSort(arr, 0, n - 1);
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Number of inversions: %lld\n", countInversions(arr, n));
    return 0;
}