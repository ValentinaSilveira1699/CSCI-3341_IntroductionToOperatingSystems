#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numOfRows, numOfThreads; // Number of rows and threads
int matrix[5][1000005]; // Matrix with a large number of columns

void* updateMatrix(void* arg)
{
    int firstThread = *((int*)arg); // First thread identifier

    // Loop through each row of the matrix
    for (int i = 0; i < 5; i++) {
        int currentColumn = (numOfThreads / numOfRows) * firstThread; // Calculate starting column index
        int length = (firstThread == numOfRows - 1) ? numOfThreads - currentColumn : numOfThreads / numOfRows; // Calculate the length of columns for this thread
        for (int j = currentColumn; j < currentColumn + length; j++) {
            matrix[i][j] %= 10; // Update matrix element
        }
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    numOfThreads = atoi(argv[1]); // Read number of threads from command line
    numOfRows = atoi(argv[2]); // Read number of rows from command line

    // Fill the matrix with random values
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < numOfThreads; j++) {
            matrix[i][j] = rand() % 79 + 1;
        }
    }

    printf("Using %d threads.\n", numOfRows);

    // Display the original matrix
    printf("Original 5 by %d array:\n", numOfThreads);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < numOfThreads; j++) {
            printf("%d", matrix[i][j]);
            if (j < numOfThreads - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    pthread_t threads[numOfRows]; // Array to hold thread IDs

    int firstThread[numOfRows]; // Array to hold identifiers for the first column processed by each thread

    // Create threads
    for (int i = 0; i < numOfRows; i++) {
        firstThread[i] = i;
        pthread_create(&threads[i], NULL, updateMatrix, &firstThread[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < numOfRows; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display the updated matrix
    printf("Updated 5 by %d array:\n", numOfThreads);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < numOfThreads; j++) {
            printf("%d", matrix[i][j]);
            if (j < numOfThreads - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    return 0;
}

