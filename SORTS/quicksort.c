#include<stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];  // Set the pivot as the first element
    int start = lb;
    int end = ub;

    while (start < end) {
        while (arr[start] <= pivot && start < ub) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[lb], &arr[end]);
    return end;  // Return the partition index
}

// Function to perform QuickSort
void QuickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub);  // Get the partition index
        QuickSort(arr, lb, loc - 1);       // Recursively sort the left subarray
        QuickSort(arr, loc + 1, ub);       // Recursively sort the right subarray
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Elements before sorting are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    //Quick Sort
    QuickSort(arr, 0, n - 1);

    printf("\nElements after sorting are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
