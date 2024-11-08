#include <stdio.h>

// Function to replace spaces in the string with a specific character
void replaceSpaces(char *str, char replacement) {
    int i = 0;

    // Loop through each character in the string
    while (str[i] != '\0') {
        if (str[i] == ' ') {   // Check if the character is a space
            str[i] = replacement; // Replace space with the specified character
        }
        i++;
    }
}

int main() {
    char str[100];
    char replacement;

    // Get a string input from the user
    printf("Enter a string");
    fgets(str, sizeof(str), stdin); // Read the whole line, including spaces

    // Get the replacement character from the user
    printf("Enter a replacement character: ");
    scanf(" %c", &replacement); // Read a single character

    // Replace spaces in the string with the specified character
    replaceSpaces(str, replacement);

    // Print the modified string
    printf("Modified string: %s\n", str);

    return 0;
}

