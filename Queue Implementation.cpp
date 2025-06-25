#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int myQueue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1 || front > rear;
}

int isFull() {
    return rear == MAX - 1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    myQueue[++rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    front++;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return myQueue[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d\n", myQueue[i]);
    }
}

int main() {
    enqueue(5);
    enqueue(6);
    enqueue(10);
    dequeue();
    display();

    return 0;
}
