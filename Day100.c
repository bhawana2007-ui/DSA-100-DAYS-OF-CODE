#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Node;

void merge(Node* arr, int left, int mid, int right, int* count, Node* temp) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Node* arr, int left, int right, int* count, Node* temp) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count, temp);
    mergeSort(arr, mid + 1, right, count, temp);
    merge(arr, left, mid, right, count, temp);
}

int* countSmaller(int* nums, int n) {

    Node* arr = (Node*)malloc(n * sizeof(Node));
    Node* temp = (Node*)malloc(n * sizeof(Node));
    int* count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1, count, temp);

    free(arr);
    free(temp);

    return count;
}