#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &matrix[i][j]);
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

// Function to find the transpose of a matrix
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            transpose[j][i] = matrix[i][j];
}

// Function to check if a matrix is symmetric
int isSymmetric(int matrix[MAX][MAX], int row, int col) {
    if (row != col) return 0; // Not symmetric if not square matrix
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (matrix[i][j] != matrix[j][i])
                return 0; // Not symmetric
    return 1; // Symmetric
}

// Function to check if a matrix is orthogonal
int isOrthogonal(int matrix[MAX][MAX], int row, int col) {
    if (row != col) return 0; // Not orthogonal if not square matrix
    int transpose[MAX][MAX], product[MAX][MAX] = {0};
    transposeMatrix(matrix, transpose, row, col);
    
    // Multiply matrix with its transpose
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            for (int k = 0; k < row; k++)
                product[i][j] += matrix[i][k] * transpose[k][j];
    
    // Check if product is identity matrix
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if ((i == j && product[i][j] != 1) || (i != j && product[i][j] != 0))
                return 0; // Not orthogonal
    return 1; // Orthogonal
}

int main() {
    int matrix[MAX][MAX], transpose[MAX][MAX];
    int row, col, choice;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &row, &col);

    inputMatrix(matrix, row, col);
    printMatrix(matrix, row, col);  // Print the input matrix

    do {
        printf("\nMenu:\n");
        printf("1. Transpose of Matrix\n");
        printf("2. Check if Matrix is Orthogonal\n");
        printf("3. Check if Matrix is Symmetric\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                transposeMatrix(matrix, transpose, row, col);
                printf("Transpose of the matrix:\n");
                printMatrix(transpose, col, row);
                break;
            case 2:
                if (isOrthogonal(matrix, row, col))
                    printf("Matrix is orthogonal.\n");
                else
                    printf("Matrix is not orthogonal.\n");
                break;
            case 3:
                if (isSymmetric(matrix, row, col))
                    printf("Matrix is symmetric.\n");
                else
                    printf("Matrix is not symmetric.\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
