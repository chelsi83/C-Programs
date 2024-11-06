#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int count = 0;

    // Input the string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character if present

    // Convert string to lowercase to handle case-insensitive comparison
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    // Tokenize the string and count occurrences of "the"
    char *token = strtok(str, " ,.-");  // Split by spaces and punctuation
    while (token != NULL) {
        if (strcmp(token, "the") == 0) {
            count++;
        }
        token = strtok(NULL, " ,.-");  // Move to the next word
    }

    // Output the result
    printf("The word 'the' appears %d times.\n", count);

    return 0;
}

