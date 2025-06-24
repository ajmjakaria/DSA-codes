#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty() {
	if(top == -1) return 1;
	else return 0;
   // return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    push(5);
    push(6);
    push(10);
    pop();
    display();

    return 0;
}
