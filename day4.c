#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], rev[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        rev[i] = arr[n - 1 - i];
    }

    printf("Reversed array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", rev[i]);
    }

    return 0;
}
