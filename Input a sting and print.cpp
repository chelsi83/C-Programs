#include <stdio.h>

int main() {
    char str[100]; // Declare a character array to hold the input string

    // Prompt the user to enter a string
    printf("Enter a string: ");
    
    // Use fgets to read a line of text including spaces
    fgets(str, sizeof(str), stdin);

    // Print the entered string
    printf("You entered: %s", str);

    return 0;
}

