#include "mySource.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <length>\n", argv[0]);
        return 1;
    }

    int len = atoi(argv[1]);
    if (len <= 0) {
        printf("Length must be a positive integer.\n");
        return 1;
    }

    char *myarr = (char *)malloc(len * sizeof(char));
    if (myarr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generateChars(myarr, len);

    printf("Original random string:\n");
    printChars(myarr, len);

    bwOffsetChars(myarr, len);

    printf("Backward-offset string:\n");
    printChars(myarr, len);

    free(myarr);

    return 0;
}

