#include <stdio.h>
#include <ctype.h> // For isupper function

// Recursive function to find the first capital letter
char findFirstCapital(char str[], int index) {
    // Base case: End of string
    if (str[index] == '\0') {
        return '\0'; // No capital letter found
    }

    // Check if the current character is a capital letter
    if (isupper(str[index])) {
        return str[index]; // Return the capital letter
    }

    // Recursive case: Check the next character
    return findFirstCapital(str, index + 1);
}

int main() {
    char str[100];

    printf("Enter a string");
    scanf("%[^\n]s", str); // Read a string including spaces

    char result = findFirstCapital(str, 0);

    if (result != '\0') {
        printf("The first capital letter is: %c\n", result);
    } else {
        printf("No capital letter found in the string.\n");
    }

    return 0;
}

