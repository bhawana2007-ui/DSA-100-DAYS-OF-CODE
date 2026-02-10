#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    
    scanf("%s", str);   // Input string (no spaces)

    int n = strlen(str);

    // Reverse the string
    for(int i = n - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
