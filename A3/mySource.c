#include "mySource.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateChars(char *myarr, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        myarr[i] = 'A' + rand() % 26;
    }
}

void bwOffsetChars(char *myarr, int len) {
    for (int i = 0; i < len; i++) {
        if (myarr[i] == 'A')
            myarr[i] = 'Z';
        else
            myarr[i] -= 1;
    }
}

void printChars(char *myarr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%c", myarr[i]);
    }
    printf("\n");
}
