#include <stdio.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);   // size of hash table
    scanf("%d", &q);   // number of operations

    int table[m];

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    while (q--) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {  // INSERT
            int h = key % m;

            for (int i = 0; i < m; i++) {
                int idx = (h + i * i) % m;

                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
            }
        } 
        else if (op[0] == 'S') {  // SEARCH
            int h = key % m;
            int found = 0;

            for (int i = 0; i < m; i++) {
                int idx = (h + i * i) % m;

                if (table[idx] == EMPTY) {
                    break;
                }

                if (table[idx] == key) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}