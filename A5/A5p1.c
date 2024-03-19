#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h> // Added for srand() function

int numOfChars, numOfThreads, currentThread = 0; // Number of characters and threads

char charArray[1000]; // Array to hold characters

const int upperBoundUppercase = 90, lowerBoundUppercase = 65, upperBoundLowercase = 122, lowerBoundLowercase = 97; // ASCII values for upper and lower case characters

void generateChars() {
    srand(time(NULL)); // Seed for random number generator
    for(int i = 0; i < numOfChars; i ++) {
        charArray[i] = rand() % (upperBoundUppercase - lowerBoundUppercase + 1) + lowerBoundUppercase; // Generating random uppercase characters
    }
}

char reverseOffset(char c) {
    int offsetValue = -1; // Offset value for conversion

    c += upperBoundLowercase - upperBoundUppercase; // Adjusting uppercase ASCII value to lowercase range
    c += offsetValue; // Applying the offset

    if(c < lowerBoundLowercase) {
        c = upperBoundLowercase; // If out of lowercase range, wrap around to 'z'
    }
    return c;
}

void* doSomething(void * p) {
    int* length = (int*) p; // Length of character array portion for each thread

    int startIndex = (numOfChars / numOfThreads) * currentThread; // Starting index for processing
    currentThread++; // Incrementing thread counter

    for(int i = startIndex; i < (*length + startIndex); i++) { 
        charArray[i] = reverseOffset(charArray[i]); // Applying reverse offset conversion
    }
}

int main(int argc, char *argv[]) {
    numOfChars = atoi(argv[1]), numOfThreads = atoi(argv[2]); // Reading number of characters and threads from command line arguments
    generateChars(); // Generating random characters

    printf("Using %d threads to handle %d chars.\nOriginal random upper case string:\n", numOfThreads, numOfChars);
    generateChars(charArray, numOfChars); // Displaying original random characters

    for(int i = 0; i < numOfChars; i++) {
        printf("%c", charArray[i]); // Printing original characters
    }
    printf("\n");
    printf("Backward-offset lower case string after conversion with %d threads:\n", numOfThreads);
	
    pthread_t threadArray[numOfThreads]; // Array to hold thread IDs
	
    int start;
    for(int i = 0; i < numOfThreads; i++) {
        int lengthOfPart = numOfChars / numOfThreads; // Length of character array portion for each thread
        start = pthread_create(&threadArray[i], NULL, doSomething, &lengthOfPart); // Creating threads
    }
	
    for(int i = 0; i < numOfThreads; i++) {
        start = pthread_join(threadArray[i], NULL); // Waiting for threads to finish
    }
	
    for(int i = 0; i < numOfChars; i++) {
        printf("%c", charArray[i]); // Printing converted characters
    }
    printf("\n");
	
    return 0;
}
