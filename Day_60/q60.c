#include <stdio.h>

int isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[2 * i + 1] < arr[i]) return 0;
        if (2 * i + 2 < n && arr[2 * i + 2] < arr[i]) return 0;
    }
    return 1;
}

int main() {
    int arr1[] = {1, 3, 5, 7, 9, 8};
    int n1 = 6;
    if (isMinHeap(arr1, n1)) printf("Array 1 is a Min-Heap\n");
    else printf("Array 1 is NOT a Min-Heap\n");

    int arr2[] = {5, 3, 2, 1};
    int n2 = 4;
    if (isMinHeap(arr2, n2)) printf("Array 2 is a Min-Heap\n");
    else printf("Array 2 is NOT a Min-Heap\n");

    return 0;
}
