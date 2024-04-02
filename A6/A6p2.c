#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 6

// Global variables
int a, b, n;
int category_A_count = 0;
int category_B_count = 0;
int category_C_count = 0;
pthread_mutex_t mutex;

// Function to compute Collatz sequence for a given integer
void computeCollatz(int var) {
    int length = 1;
    while (var != 1) {
        if (var % 2 == 0) {
            var /= 2;
        } else {
            var = (3 * var + 1) / 2;
        }
        length++;
    }
}

// Thread function to count Collatz lists
void *countCollatzLists(void *arg) {
    int thread_id = *((int *)arg);
    int chunk_size = (b - a + 1) / n;
    int start = a + thread_id * chunk_size;
    int end = start + chunk_size - 1;

    // Adjust the range for the last thread
    if (thread_id == n - 1) {
        end = b;
    }

    for (int i = start; i <= end; i++) {
        int greater_than_var = 0;
        int less_than_var = 0;
        int var = i;

        while (var != 1) {
            if (var % 2 == 0)
                var /= 2;
            else
                var = (3 * var + 1) / 2;

            if (var > i)
                greater_than_var++;
            else if (var < i)
                less_than_var++;
        }

        pthread_mutex_lock(&mutex);
        if (less_than_var < greater_than_var)
            category_A_count++;
        else if (less_than_var == greater_than_var)
            category_B_count++;
        else
            category_C_count++;
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s a b n\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    n = atoi(argv[3]);

    if (a >= b || n < 2 || n > MAX_THREADS) {
        printf("Invalid input.\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    pthread_mutex_init(&mutex, NULL);

    printf("Using %d threads to handle %d Collatz lists from %d to %d inclusive.\n", n, b - a + 1, a, b);

    for (int i = 0; i < n; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, countCollatzLists, &thread_ids[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Category (A) count is %d.\n", category_A_count);
    printf("Category (B) count is %d.\n", category_B_count);
    printf("Category (C) count is %d.\n", category_C_count);

    return 0;
}