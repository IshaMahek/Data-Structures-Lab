#include <stdio.h>

void multiplyMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("Matrix multiplication is not possible. Number of columns of matrix1 must equal number of rows of matrix2.\n");
        return;
    }
    
    // Initializing result matrix to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int calculateTrace(int matrix[10][10], int rows) {
    int trace = 0;
    for (int i = 0; i < rows; i++) {
        trace += matrix[i][i];  // Add diagonal element
    }
    return trace;
}

void inputMatrix(int matrix[10][10], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    printf("\nMatrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int r1, c1, r2, c2;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Multiply two matrices\n");
        printf("2. Calculate the trace of a matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Multiply matrices
                printf("Enter rows and columns for Matrix 1: ");
                scanf("%d %d", &r1, &c1);
                inputMatrix(matrix1, r1, c1);

                printf("Enter rows and columns for Matrix 2: ");
                scanf("%d %d", &r2, &c2);
                inputMatrix(matrix2, r2, c2);

                // Call multiply function
                multiplyMatrices(matrix1, matrix2, result, r1, c1, r2, c2);
                printMatrix(result, r1, c2);
                break;

            case 2:  // Calculate trace of a matrix
                printf("Enter the size of the square matrix: ");
                scanf("%d", &r1);  // For trace, the matrix must be square (rows = columns)
                inputMatrix(matrix1, r1, r1);

                int trace = calculateTrace(matrix1, r1);
                printf("The trace of the matrix is: %d\n", trace);
                break;

            case 3:  // Exit
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
