#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to find the largest and smallest words in a string
void findLargestSmallestWord(char str[]) {
    int i = 0, j = 0;
    int len = strlen(str);
    
    char word[100];
    char largest[100], smallest[100];
    int largestLength = 0, smallestLength = len;

    // Initialize the largest and smallest words
    largest[0] = '\0';
    smallest[0] = '\0';

    // Loop through the string to find words
    while (i <= len) {
        // Check if current character is a space or end of string
        if (str[i] == ' ' || str[i] == '\0') {
            word[j] = '\0'; // Null-terminate the current word

            // Compare word length with largest and smallest
            int wordLength = strlen(word);

            if (wordLength > largestLength) {
                strcpy(largest, word);
                largestLength = wordLength;
            }

            if (wordLength < smallestLength) {
                strcpy(smallest, word);
                smallestLength = wordLength;
            }

            // Reset the word for the next iteration
            j = 0;
        } else {
            // Store the characters of the current word
            word[j++] = str[i];
        }
        i++;
    }

    // Output the largest and smallest words
    printf("Smallest Word: %s\n", smallest);
    printf("Largest Word: %s\n", largest);
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character from fgets

    // Call the function to find the largest and smallest words
    findLargestSmallestWord(str);

    return 0;
}

