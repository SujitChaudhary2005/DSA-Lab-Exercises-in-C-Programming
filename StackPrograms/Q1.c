// Program to implement basic stack operations including push, pop, peek, and display using an array.
#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 5

int stack[MAXSIZE]; // stack storage
int top = -1;       // Tracks the top of the stack

// Check if the stack is full
bool isFull() {
    return top == MAXSIZE - 1;
}

// Check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Push an item onto the stack
int push(int item) {
    if (isFull()) {
        printf("Stack Overflow! Can't add %d.\n", item);
        return 1;
    } else {
        stack[++top] = item;
        printf("%d added to the stack.\n", item);
        return 0;
    }
}

// Peek an item in the stack
int peek() {
    if (isEmpty()) {
        printf("\nStack Underflow! Nothing to peek.\n");
        return -1;
    } else {
        printf("\n%d is at the top of the stack.\n", stack[top]);
        return stack[top];
    }
}

// Pop an item off the stack
int pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! Nothing to remove.\n");
        return -1;
    } else {
        int poppedValue = stack[top--];
        printf("\n%d removed from the stack.\n", poppedValue);
        return poppedValue;
    }
}

// Display stack elements
void display() {
    if (isEmpty()) {
        printf("The stack is empty. Nothing to show.\n");
    } else {
        printf("Stack from Bottom to Top: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");

        printf("Stack from Top to Bottom: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        // Menu for the user
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;    
            case 4:
                display();
                break;
            case 5:
                printf("Bye! Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}