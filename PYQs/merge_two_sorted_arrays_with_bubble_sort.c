#include <stdio.h>

// Function to perform Bubble Sort on an array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to merge two sorted arrays
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge the arrays while elements are left in both
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // If there are remaining elements in arr1
    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // If there are remaining elements in arr2
    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int n1, n2;

    // Input size of first array
    printf("Enter the size of first array: ");
    scanf("%d", &n1);
    int arr1[n1];

    // Input elements of first array
    printf("Enter elements of first array: \n");
    for (int i = 0; i < n1; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    // Input size of second array
    printf("Enter the size of second array: ");
    scanf("%d", &n2);
    int arr2[n2];

    // Input elements of second array
    printf("Enter elements of second array: \n");
    for (int i = 0; i < n2; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    // Sort both arrays
    bubbleSort(arr1, n1);
    bubbleSort(arr2, n2);

    // Array to hold the merged result
    int merged[n1 + n2];

    // Merge the arrays
    mergeArrays(arr1, arr2, n1, n2, merged);

    // Print the merged array
    printf("\nMerged Sorted Array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
