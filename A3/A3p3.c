#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    // Convert command line arguments to integers
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for the first matrix
    int **matrix1 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix1[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix1[i][j] = rand() % 71 - 30; // Generate random integer between -30 and 40
        }
    }

    // Allocate memory for the second matrix (reverse row order)
    int **matrix2 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix2[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix2[m - i - 1][j] = matrix1[i][j];
        }
    }

    // Print the matrices
    printf("First matrix:\n");
    printMatrix(matrix1, m, n);
    printf("\n");

    printf("\nSecond matrix:\n");
    printMatrix(matrix2, m, n);

    return 0; // Return success code
}