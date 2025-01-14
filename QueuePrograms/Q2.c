// Program to implement basic queue operations including enqueue, dequeue, peek, and display using a circular array.
#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 5

int queue[MAXSIZE]; // queue storage
int front = -1;     // Tracks the front of the queue
int rear = -1;      // Tracks the rear of the queue

// Check if the queue is full
bool isFull() {
    return (front == (rear + 1) % MAXSIZE);
}

// Check if the queue is empty
bool isEmpty() {
    return front == -1;
}

// Enqueue an item into the queue
bool enqueue(int item) {
    if (isFull()) {
        printf("Queue Overflow! Can't add %d.\n", item);
        return false;
    } else if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAXSIZE;
    }
    queue[rear] = item;
    printf("%d added to the queue.\n", item);
    return true;
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
        int dequeuedValue = queue[front];
        if (front == rear) {
            front = rear = -1; // Reset the queue if it becomes empty
        } else {
            front = (front + 1) % MAXSIZE;
        }
        printf("\n%d removed from the queue.\n", dequeuedValue);
        return dequeuedValue;
    }
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("The queue is empty. Nothing to show.\n");
    } else {
        printf("Queue from Front to Rear: ");
        int i = front;
        while (true) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAXSIZE;
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