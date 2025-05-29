#include <stdio.h>

int queue[100], front = -1, rear = -1, max;

void insertion(int n) {
    if (rear + 1 == max) {
        printf("Queue is full!!!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = n;
    }
}

void deletion() {
    if (front == -1) {
        printf("Empty Queue!!!\n");
    } else {
        printf("%d is deleted from the queue\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1; 
        }
    }
}

void display() {
    if (front == -1) {
        printf("Empty Queue!!!\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, num;

    printf("Enter the number of elements you want in your queue: ");
    scanf("%d", &max);

    while (1) {
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            printf("Enter the number you want to push to the queue: ");
            scanf("%d", &num);
            insertion(num);
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Thank you!!!!\n");
            return 0;
        default:
            printf("Invalid Choice!!!!!\n");
            break;
        }
    }
    return 0;
}s