#include <stdio.h>

void printPascal(int n) {
    int i, j;
    
    // 2D array to store the triangle
    int pascal[n][n];
    
    // Generating Pascal's Triangle
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            // First and last elements in each row are 1
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            } else {
                // Other elements are the sum of the two numbers above
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }
    
    // Printing Pascal's Triangle
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows;

    // Input number of rows
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    // Print Pascal's Triangle
    printPascal(rows);

    return 0;
}
