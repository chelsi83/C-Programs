#include <stdio.h>

int main() {
    char str[100]; // Declare a character array to hold the input string
    int length = 0; // Variable to store the length of the string

    // take input from the user to enter a string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin); // Read the input string

    // Iterate through the string until we reach the null terminator '\0'
    while (str[length] != '\0') {
        length++; // Increment length for each character
    }

    // Subtract 1 from the length to ignore the newline character added by fgets
    if (length > 0 && str[length - 1] == '\n') {
        length--;
    }

    // Print the length of the string
    printf("Length of the string: %d\n", length);

    return 0;
}

