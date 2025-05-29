#include <stdio.h>

void removeDuplicates(int arr[], int *n) {
    int i, j, k;
    
    // Outer loop for each element
    for (i = 0; i < *n; i++) {
        // Check for duplicates
        for (j = i + 1; j < *n; j++) {
            if (arr[i] == arr[j]) {
                // Shift all elements left after a duplicate is found
                for (k = j; k < *n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                (*n)--;  // Decrease size of the array
                j--;  // Stay at the same index after shifting
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;

    // Ask the user for the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];  // Create an array with user-defined size

    // Ask the user to input the array elements
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);
    
    removeDuplicates(arr, &n);
    
    printf("Array after removing duplicates: \n");
    printArray(arr, n);
    
    return 0;
}
