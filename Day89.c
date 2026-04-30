#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] > maxPages) {
            students++;
            pagesSum = arr[i];

            if (students > m)
                return 0;
        } else {
            pagesSum += arr[i];
        }
    }
    return 1;
}

int findMinPages(int arr[], int n, int m) {
    if (m > n)
        return -1;

    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max, high = sum, result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = findMinPages(arr, n, m);
    printf("%d\n", result);

    return 0;
}