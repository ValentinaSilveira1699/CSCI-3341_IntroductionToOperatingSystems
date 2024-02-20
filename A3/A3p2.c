#include <stdio.h>

int main(int args, char *argsp[]) {
    int n;
    int startLetterNum = 65;// ASCII code for 'A'
    // Prompt the user to enter an integer between 2 and 26
    printf("Enter some integer (2~26): \n");
    scanf("%d", &n);
    
    // Loop to print the pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            printf(" ");
        }
        printf("%c", startLetterNum + i); // Print the letters
        printf("\n");
    }
    return 0; // Exit successfully
}