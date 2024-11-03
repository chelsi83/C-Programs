#include <stdio.h>

int main() {
    char str[100];  // Declare a character array to hold the input string
    int length = 0; // Variable to store the length of the string

    // take input from the user to enter a string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);  // Read the input string

    // Calculate the length of the string
    while (str[length] != '\0') {
        length++;
    }

    // Adjust length to ignore newline character added by fgets
    if (length > 0 && str[length - 1] == '\n') {
        length--;
    }

    // Print characters in reverse order
    printf("Characters in reverse order:\n");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c\n", str[i]);
    }

    return 0;
}

