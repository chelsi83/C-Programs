#include <stdio.h>

// Function to compare two strings without using string library functions
int compareStrings(const char *str1, const char *str2) {
    int i = 0;

    // Loop through each character of both strings
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            // Return the difference if characters are not equal
            return str1[i] - str2[i];
        }
        i++;
    }

    // If one string is shorter, return difference in lengths
    return str1[i] - str2[i];
}

int main() {
    char str1[100], str2[100];

    // Input two strings from the user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline character at the end of each string if present
    if (str1[0] != '\0' && str1[strlen(str1) - 1] == '\n') {
        str1[strlen(str1) - 1] = '\0';
    }
    if (str2[0] != '\0' && str2[strlen(str2) - 1] == '\n') {
        str2[strlen(str2) - 1] = '\0';
    }

    // Compare the strings using compareStrings function
    int result = compareStrings(str1, str2);

    // Display the result
    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result < 0) {
        printf("The first string is lexicographically smaller.\n");
    } else {
        printf("The first string is lexicographically greater.\n");
    }

    return 0;
}

