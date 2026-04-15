#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char votes[n][50];

    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char names[n][50];
    int count[n];
    int unique = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < unique; j++) {
            if (strcmp(votes[i], names[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(names[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[50];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}