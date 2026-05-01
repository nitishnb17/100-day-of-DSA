#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100];

void insert(int key, int m) {
    int i = 0;
    int index;
    while (i < m) {
        index = (key % m + i * i) % m;
        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }
}

int search(int key, int m) {
    int i = 0;
    int index;
    while (i < m) {
        index = (key % m + i * i) % m;
        if (table[index] == EMPTY)
            return 0;
        if (table[index] == key)
            return 1;
        i++;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0)
            insert(key, m);
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
