#include <stdio.h>
#include <stdlib.h>

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
    // No return value since the function is declared as void
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s a b\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    if (a >= b) {
        printf("a must be less than b.\n");
        return 1;
    }

    int category_A_count = 0;
    int category_B_count = 0;
    int category_C_count = 0;

    for (int i = a; i <= b; i++) {
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

        if (greater_than_var > less_than_var)
            category_A_count++;
        else if (greater_than_var == less_than_var)
            category_B_count++;
        else
            category_C_count++;
    }

    printf("There are %d integers between %d and %d inclusive.\n", b - a + 1, a, b);
    printf("Category (A) count is %d.\n", category_A_count);
    printf("Category (B) count is %d.\n", category_B_count);
    printf("Category (C) count is %d.\n", category_C_count);

    return 0;
}