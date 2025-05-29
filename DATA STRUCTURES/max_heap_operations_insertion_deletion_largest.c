#include <stdio.h>

void displayHeap(int heap[], int size);
void insert(int heap[], int *size, int value);
void deleteMax(int heap[], int *size);
void heapify(int heap[], int size, int index);

int main() {
    int heap[100], size = 0, choice, value;

    while (1) {
        printf("1. Insert\n2. Delete Max\n3. Display Max\n4. Display Heap\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(heap, &size, value);
                break;
            case 2:
                if (size == 0) 
                    printf("Heap is empty.\n");
                else {
                    printf("Deleted max value: %d\n", heap[0]);
                    deleteMax(heap, &size);
                }
                break;
            case 3:
                if (size == 0) 
                    printf("Heap is empty.\n");
                else 
                    printf("Max value: %d\n", heap[0]);
                break;
            case 4:
                displayHeap(heap, size);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Display the heap
void displayHeap(int heap[], int size) {
    if (size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Heap:\n");
     for (int i = 0; i < size; i++) { 
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", heap[i]);
    }
    printf("\n");
}

// Insert a value into the heap
void insert(int heap[], int *size, int value) {
    int i = (*size)++;
    heap[i] = value;

    // Bubble up
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Delete the max value (root) from the heap
void deleteMax(int heap[], int *size) {
    heap[0] = heap[--(*size)]; // Replace root with last element
    heapify(heap, *size, 0);   // Restore heap property
}

// Restore max-heap property
void heapify(int heap[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest]) 
    largest = left;
    if (right < size && heap[right] > heap[largest]) 
    largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap, size, largest);
    }
}





