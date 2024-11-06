#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100], result[100];
    int i, j = 0;

    // Input the string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);

    // Loop through each character in the string
    for (i = 0; str[i] != '\0'; i++) {
        // Check if the character is an alphabet (A-Z or a-z)
        if (isalpha(str[i])) {
            result[j++] = str[i];  // Add the alphabet character to result
        }
    }

    result[j] = '\0';  // Null-terminate the result string

    // Output the modified string
    printf("String after removing non-alphabet characters: %s\n", result);

    return 0;
}

