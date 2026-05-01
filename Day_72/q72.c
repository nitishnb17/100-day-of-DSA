#include <stdio.h>
#include <string.h>

char firstNonRepeating(char *s) {
    int count[256] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        count[(unsigned char)s[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (count[(unsigned char)s[i]] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100001];
    if (scanf("%s", s) == 1) {
        printf("%c\n", firstNonRepeating(s));
    }
    return 0;
}
