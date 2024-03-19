#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define CHAR_UPPER_BOUND 26
#define CHAR_OFFSET 65

// Function to convert one-third of the string into a backward-offset lowercase version
void convertToLower(char *str, int len) {
    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            str[i] = ((str[i] - CHAR_OFFSET + CHAR_UPPER_BOUND - 1) % CHAR_UPPER_BOUND) + 'a';
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <multiple_of_60>\n", argv[0]);
        return 1;
    }

    int m = atoi(argv[1]);
    if (m % 60 != 0) {
        printf("Input must be a multiple of 60.\n");
        return 1;
    }

    srand(time(NULL));

    // Generate random string
    char *str = (char *)malloc((m + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        str[i] = 'A' + rand() % 26; // Generating random upper case characters
    }
    str[m] = '\0';

    printf("Generated a string of %d chars.\n", m);
    printf("Original random upper case string:\n%s\n", str);

    // Call the conversion function three times
    for (int i = 0; i < 3; i++) {
        int len = m / 3;
        convertToLower(str + i * len, len);
    }

    printf("Backward-offset lower case string after three function calls:\n%s\n", str);

    free(str);
    return 0;
}
