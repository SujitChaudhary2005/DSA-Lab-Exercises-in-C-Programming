//Program to implement basic Linear Ordered Queue operations including insert, remove minimum, and display using an array.
#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 5 // Define the maximum size of the queue

int queue[MAXSIZE]; // Array to store queue elements
int front = -1; // Index of the front element
int rear = -1;  // Index of the rear element

// Function to check if the queue is empty
bool isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
bool isFull() {
    return rear == MAXSIZE - 1;
}

// Function to insert an element into the queue in sorted order
void insert(int item) {
    if (isFull()) {
        printf("Queue Overflow! Can't add %d.\n", item);
    } else {
        if (isEmpty()) {
            front = rear = 0;
            queue[rear] = item;
        } else {
            int i;
            for (i = rear; i >= front && queue[i] > item; i--) {
                queue[i + 1] = queue[i];
            }
            queue[i + 1] = item; // Insert the new item
            rear++;
        }
        printf("%d inserted into the queue.\n", item);
    }
}

// Function to remove the minimum element from the queue
void removeMin() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to remove.\n");
    } else {
        printf("%d removed from the queue.\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1; // Reset if the queue becomes empty
        }
    }
}

// Function to display the queue
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
        printf("\nOrdered Queue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Remove Minimum\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                removeMin();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Bye! Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}