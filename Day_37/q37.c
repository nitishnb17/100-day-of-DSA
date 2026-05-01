#include <stdio.h>
#define MAX 100

int queue[MAX];
int size = 0;

void enqueue(int val) {
    if (size == MAX) {
        printf("Queue is full\n");
        return;
    }
    int i = size - 1;
    while (i >= 0 && queue[i] < val) {
        queue[i + 1] = queue[i];
        i--;
    }
    queue[i + 1] = val;
    size++;
}

void dequeue() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued (highest priority): %d\n", queue[0]);
    for (int i = 0; i < size - 1; i++)
        queue[i] = queue[i + 1];
    size--;
}

void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(40);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
