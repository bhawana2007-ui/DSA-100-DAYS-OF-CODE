#include <stdio.h>

int integerSqrt(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // To avoid overflow, use mid <= n / mid instead of mid*mid <= n
        if (mid <= n / mid) {
            ans = mid;        // mid could be the answer
            low = mid + 1;    // search right side
        } else {
            high = mid - 1;   // search left side
        }
    }

    return ans;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Integer square root: %d\n", integerSqrt(n));

    return 0;
}