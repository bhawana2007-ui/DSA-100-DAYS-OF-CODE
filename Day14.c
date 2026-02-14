#include <stdio.h>

int main() {
    int n, i, j, flag = 1;

    // Input size
    scanf("%d", &n);

    int matrix[n][n];

    // Input matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity matrix condition
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) {
                    flag = 0;
                    break;
                }
            } 
            else {
                if(matrix[i][j] != 0) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0)
            break;
    }

    // Output result
    if(flag == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
