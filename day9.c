#include <stdio.h>
#include <string.h>

// recursive function
void reverse(char str[], int index) {
    if(index < 0)
        return;

    printf("%c", str[index]);
    reverse(str, index - 1);
}

int main() {
    char str[1000];

    scanf("%s", str);

    int len = strlen(str);

    reverse(str, len - 1);

    return 0;
}
