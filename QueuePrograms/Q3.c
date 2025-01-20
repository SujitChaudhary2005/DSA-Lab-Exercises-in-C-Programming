//Program to implement basic Linear Unordered Queue operations including insert, remove minimum, and display using an array.
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

// Function to insert an element into the queue
void insert(int item) {
    if (isFull()) {
        printf("Queue Overflow! Can't add %d.\n", item);
    } else {
        if (isEmpty()) {
            front = 0;
        }
        queue[++rear] = item; // Add item at the rear
        printf("%d inserted into the queue.\n", item);
    }
}

// Function to remove the minimum element from the queue
void removeMin() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to remove.\n");
    } else {
        int minIndex = front, minValue = queue[front];
        for (int i = front + 1; i <= rear; i++) {
            if (queue[i] < minValue) {
                minValue = queue[i];
                minIndex = i;
            }
        }
        for (int i = minIndex; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        if (rear < front) {
            front = rear = -1; // Reset if the queue becomes empty
        }
        printf("%d removed from the queue.\n", minValue);
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
        printf("\nUnordered Queue Operations Menu:\n");
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