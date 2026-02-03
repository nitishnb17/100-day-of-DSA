#include <stdio.h>

int main() {
    int n, k;
    int count = 0, found = 0;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    scanf("%d", &k);


    for(int i = 0; i < n; i++) {
        count++;              
        if(arr[i] == k) {
            printf("Key found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Key not found\n");
    }

    printf("Number of comparisons = %d", count);

    return 0;
}
