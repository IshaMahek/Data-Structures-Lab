#include <stdio.h>

// Recursive Binary Search
int binSearchRec(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binSearchRec(arr, low, mid - 1, key);

        return binSearchRec(arr, mid + 1, high, key);
    }
    return -1;
}

// Iterative Binary Search
int binSearchIter(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n, key;

    // Get number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Declare and take input for the array
    int arr[n];
    printf("Enter sorted elements: \n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Get key to search
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    // Binary Search using Recursive Method
    int resultRec = binSearchRec(arr, 0, n - 1, key);
    if (resultRec == -1)
        printf("Element %d not found (recursive).\n", key);
    else
        printf("Element %d found at index %d (recursive).\n", key, resultRec);

    // Binary Search using Iterative Method
    int resultIter = binSearchIter(arr, n, key);
    if (resultIter == -1)
        printf("Element %d not found (iterative).\n", key);
    else
        printf("Element %d found at index %d (iterative).\n", key, resultIter);

    return 0;
}
