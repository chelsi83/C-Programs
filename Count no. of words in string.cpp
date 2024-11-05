#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    int i = 0, wordCount = 0;
    int inWord = 0;  // Flag to check if we're inside a word

    // take input from the user to enter a string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);

    // Loop through each character in the string
    while (str[i] != '\0') {
        // Check if the current character is not a space
        if (!isspace(str[i])) {
            if (!inWord) {
                wordCount++;   // Found the beginning of a word
                inWord = 1;    // Set the inWord flag to 1 (true)
            }
        } else {
            inWord = 0;        // If it's a space, end the current word
        }
        i++;  // Move to the next character
    }

    // Output the total number of words found
    printf("Total number of words %d\n", wordCount);

    return 0;
}

