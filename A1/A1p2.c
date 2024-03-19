/*
Write a C program A1p2.c that works in the same way as A1p1.java. Two sample runs look like the following:
[kwang@computer][~/temp]$ A1p2 5 47
5,8,11,{14},17
20,23,26,29,32
{35},38,41,44,47
[kwang@computer][~/temp]$ A1p2 -3 61
-3,{0},3,6,9
12,15,18,{21},24
27,30,33,36,39
{42},45,48,51,54
57,60

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Parse command line arguments as integers
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    // Counter to keep track of the number of outputs in the current row
    int outputCount = 0;

    // Iterate from 'a' to 'b' with a step of 3
    for (int i = a; i <= b; i += 3) {
        // Check if the current number is a multiple of 7
        if (i % 7 == 0) {
            // If multiple of 7, print the number within curly braces
            printf("{%d}", i);
        } else {
            // If not multiple of 7, print the number as is
            printf("%d", i);
        }

        // Add a comma if it's not the last number in the loop and not the 5th output
        if (i + 3 <= b && i + 3 - a <= b - a && outputCount < 4) {
            printf(",");
        }

        // Increment the output count
        outputCount++;

        // Print a newline after every 5 outputs
        if (outputCount == 5) {
            printf("\n");
            outputCount = 0; // Reset the output count for the next row
        }
    }

    // Print a newline if the last row contains less than 5 outputs
    if (outputCount > 0) {
        printf("\n");
    }

    return 0;
}

