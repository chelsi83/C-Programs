#include <stdio.h>
#include <string.h>

// Function to extract a substring from the source string
void extractSubstring(char source[], char result[], int start, int length) {
    int i;
    // Loop to copy the substring from source to result
    for (i = 0; i < length && source[start + i] != '\0'; i++) {
        result[i] = source[start + i];  // Copy each character
    }
    result[i] = '\0';  // Null-terminate the result string
}

int main() {
    char str[100], substring[100];
    int start, length;

    // take input from the user to enter a string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character if present

    // Input the starting position and the length of the substring to extract
    printf("Enter the starting position");
    scanf("%d", &start);
    printf("Enter the length of the substring");
    scanf("%d", &length);

    // Check if the starting position and length are within valid range
    if (start < 0 || start >= strlen(str) || length < 0) {
        printf("Invalid starting position or length.\n");
        return 1;  // Exit the program if input is invalid
    }

    // Call the function to extract the substring
    extractSubstring(str, substring, start, length);

    // Print the extracted substring
    printf("Extracted substring %s\n", substring);

    return 0;
}

