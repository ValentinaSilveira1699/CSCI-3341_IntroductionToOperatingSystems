#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <positive_integer>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    if (a < 2) {
        printf("Input should be a positive integer at least 2.\n");
        return 1;
    }

    printf("Iterated list for %d is:\n", a);
    int length = 0;
    while (a != 1) {
        printf("%d,", a);
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a = (3 * a + 1) / 2;
        }
        length++;
    }
    printf("1\n");
    length++;

    printf("Length of the list: %d\n", length);

    return 0;
}
