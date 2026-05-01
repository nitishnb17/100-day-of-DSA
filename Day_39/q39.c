#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void insert(int val) {
    heap[size] = val;
    int i = size;
    size++;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void deleteMin() {
    if (size == 0) { printf("Heap is empty\n"); return; }
    printf("Deleted min: %d\n", heap[0]);
    heap[0] = heap[--size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(5);
    insert(20);
    insert(1);
    display();
    deleteMin();
    display();
    return 0;
}
