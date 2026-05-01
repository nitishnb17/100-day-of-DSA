#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 100

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][NAME_LEN];
    
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char names[MAX][NAME_LEN];
    int count[MAX] = {0};
    int unique = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], votes[i]) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(names[unique], votes[i]);
            count[unique] = 1;
            unique++;
        } else {
            count[found]++;
        }
    }

    int maxVotes = 0;
    char winner[NAME_LEN];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
