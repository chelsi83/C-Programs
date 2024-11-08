#include <stdio.h>
#include <ctype.h> // For tolower function

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    int i = 0;
    
    // Loop through each character in the string
    while (str[i] != '\0') {
        str[i] = tolower(str[i]); // Convert character to lowercase
        i++;
    }
}

int main() {
    char str[100];

    // Get user input
    printf("Enter a string");
    fgets(str, sizeof(str), stdin); // Read a line of text, including spaces

    // Convert the string to lowercase
    toLowerCase(str);

    // Print the result
    printf("Lowercase string: %s\n", str);

    return 0;
}

