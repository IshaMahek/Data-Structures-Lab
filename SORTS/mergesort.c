#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // Size of left subarray
    int n2 = r - m;     // Size of right subarray

    // Temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r) {
    if (l >= r) // Base case: single element or invalid range
        return;

    int m = l + (r - l) / 2;

    // Recursively sort first and second halves
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
}

int main() {
    int i, n;

    // Input size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print elements before sorting
    printf("\nElements before sorting are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Perform Merge Sort
    MergeSort(arr, 0, n - 1);

    // Print elements after sorting
    printf("\nElements after sorting are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
