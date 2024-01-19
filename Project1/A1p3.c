/*
(see TestScanfandCondition.c in Folio if needed) Write a C program A1p3.c to read from stdin a specified number of lines of input (each line can be assumed to contain a pair of integers separated by a space). The program should print the product of the two numbers after each line is received. A sample run looks like the following:
[kwang@computer][~/temp]$ ./A1p3
How many pairs to input? 3
1 2
The product of 1 and 2 is 2.
5 6
The product of 5 and 6 is 30.
9 -28
The product of 9 and -28 is -252.

*/
#include <stdio.h>

int main() {
    // Declare variables to store the number of pairs and two numbers in each pair
    int numberOfPairs, num1, num2;

    // Prompt user for the number of pairs to input
    printf("How many pairs to input? ");
    scanf("%d", &numberOfPairs);

    // Iterate through each pair
    for (int i = 0; i < numberOfPairs; i++) {
        // Read two numbers as input for each pair
        scanf("%d %d", &num1, &num2);

        // Calculate and print the product of the two numbers in the pair
        printf("The product of %d and %d is %d.\n", num1, num2, num1 * num2);
    }

    return 0;
}
