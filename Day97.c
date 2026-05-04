#include <stdio.h>
#include <stdlib.h>

// Structure for meetings
typedef struct {
    int start, end;
} Meeting;

// Comparator for sorting by start time
int compare(const void* a, const void* b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

// Min Heap functions
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void insertHeap(int heap[], int* size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

void removeMin(int heap[], int* size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

// Function to find minimum rooms
int minMeetingRooms(Meeting arr[], int n) {
    // Step 1: Sort by start time
    qsort(arr, n, sizeof(Meeting), compare);

    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;

    // Add first meeting end time
    insertHeap(heap, &heapSize, arr[0].end);

    for (int i = 1; i < n; i++) {
        // If earliest room is free
        if (heap[0] <= arr[i].start) {
            removeMin(heap, &heapSize);
        }
        // Allocate room (insert end time)
        insertHeap(heap, &heapSize, arr[i].end);
    }

    int result = heapSize;
    free(heap);
    return result;
}

// Example usage
int main() {
    Meeting arr[] = {{1,4}, {10,15}, {7,10}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum rooms required: %d\n", minMeetingRooms(arr, n));
    return 0;
}