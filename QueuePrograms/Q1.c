// Program to implement basic queue operations including enqueue, dequeue, peek, and display using an array.
#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 5

int queue[MAXSIZE]; // queue storage
int front = -1;     // Tracks the front of the queue
int rear = -1;      // Tracks the rear of the queue

// Check if the queue is full
bool isFull() {
    return rear == MAXSIZE - 1;
}

// Check if the queue is empty
bool isEmpty() {
    return front == -1 || front > rear;
}

// Enqueue an item into the queue
int enqueue(int item) {
    if (isFull()) {
        printf("Queue Overflow! Can't add %d.\n", item);
        return 1;
    } else if (front == -1) {
        front = 0;
        queue[++rear] = item;
        printf("%d added to the queue.\n", item);
        return 0;
    } else {
        queue[++rear] = item;
        printf("%d added to the queue.\n", item);
        return 0;
    }
}

// Peek an item in the queue
int peek() {
    if (isEmpty()) {
        printf("\nQueue Underflow! Nothing to peek.\n");
        return -1;
    } else {
        printf("\n%d is at the front of the queue.\n", queue[front]);
        return queue[front];
    }
}

// Dequeue an item from the queue
int dequeue() {
    if (isEmpty()) {
        printf("\nQueue Underflow! Nothing to remove.\n");
        return -1;
    } else {
        int dequeuedValue = queue[front++];
        printf("\n%d removed from the queue.\n", dequeuedValue);
        if (front > rear) {
            front = rear = -1; // Reset the queue if it becomes empty
        }
        return dequeuedValue;
    }
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("The queue is empty. Nothing to show.\n");
    } else {
        printf("Queue from Front to Rear: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        // Menu for the user
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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