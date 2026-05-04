#include <stdio.h>

// Function to find maximum element
int max(int arr[], int n) {
    int m = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > m)
            m = arr[i];
    }
    return m;
}

// Function to find sum of array
int sum(int arr[], int n) {
    int s = 0;
    for(int i = 0; i < n; i++)
        s += arr[i];
    return s;
}

// Check if it is possible to paint with given max time
int isPossible(int arr[], int n, int k, int mid) {
    int painters = 1;
    int currSum = 0;

    for(int i = 0; i < n; i++) {
        if(currSum + arr[i] <= mid) {
            currSum += arr[i];
        } else {
            painters++;
            currSum = arr[i];

            if(painters > k)
                return 0;
        }
    }
    return 1;
}

// Main function to find minimum time
int minTime(int arr[], int n, int k) {
    int low = max(arr, n);
    int high = sum(arr, n);
    int ans = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = minTime(arr, n, k);
    printf("%d\n", result);

    return 0;
}