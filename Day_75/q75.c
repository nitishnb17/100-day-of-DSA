#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int key;
    int value;
} Hash;

int findSubarray(int arr[], int n) {
    Hash hash[MAX];
    int size = 0;

    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int found = -1;
        for (int j = 0; j < size; j++) {
            if (hash[j].key == sum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            int len = i - hash[found].value;
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[size].key = sum;
            hash[size].value = i;
            size++;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", findSubarray(arr, n));

    return 0;
}
