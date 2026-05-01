#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() { return front == -1; }
int isFull() { return rear == MAX - 1; }

void insertFront(int val) {
    if (isFull()) { printf("Deque is full\n"); return; }
    if (isEmpty()) { front = rear = 0; }
    else if (front == 0) { printf("Cannot insert at front\n"); return; }
    else front--;
    deque[front] = val;
}

void insertRear(int val) {
    if (isFull()) { printf("Deque is full\n"); return; }
    if (isEmpty()) { front = rear = 0; }
    else rear++;
    deque[rear] = val;
}

void deleteFront() {
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    printf("Deleted from front: %d\n", deque[front]);
    if (front == rear) front = rear = -1;
    else front++;
}

void deleteRear() {
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    printf("Deleted from rear: %d\n", deque[rear]);
    if (front == rear) front = rear = -1;
    else rear--;
}

void display() {
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    deleteFront();
    deleteRear();
    display();
    return 0;
}
