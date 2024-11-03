#include <stdio.h>

int main() {
    char str[100];  // Declare a character array to hold the input string
    int i = 0;      // Variable to loop through the string

    // take input from the user to enter a string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);  // Read the input string

    // Loop through each character until we reach the null terminator '\0'
    printf("Individual characters in the string:\n");
    while (str[i] != '\0') {
        // Print each character if it's not the newline character
        if (str[i] != '\n') {
            printf("%c\n", str[i]);
        }
        i++; // Move to the next character
    }

    return 0;
}

