#include <stdio.h>
#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = 0, top = -1;

void enqueue(int val) { queue[rear++] = val; }

void reverseQueue() {
    for (int i = front; i < rear; i++)
        stack[++top] = queue[i];
    front = rear = 0;
    while (top >= 0)
        queue[rear++] = stack[top--];
}

void display() {
    for (int i = front; i < rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("Original: ");
    display();
    reverseQueue();
    printf("Reversed: ");
    display();
    return 0;
}
