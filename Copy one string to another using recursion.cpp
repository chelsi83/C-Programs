#include <stdio.h>

// Recursive function to copy a string
void copyString(char source[], char destination[], int index) {
    destination[index] = source[index]; // Copy current character

    // Base case: Stop when null character is copied
    if (source[index] == '\0') {
        return;
    }

    // Recursive call to copy the next character
    copyString(source, destination, index + 1);
}

int main() {
    char source[100], destination[100];

    printf("Enter the source string");
    scanf("%s", source);

    // Start the copying process from index 0
    copyString(source, destination, 0);

    printf("Source string: %s\n", source);
    printf("Destination string: %s\n", destination);

    return 0;
}

