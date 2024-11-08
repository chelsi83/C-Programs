#include <stdio.h>

// Function to concatenate two strings manually
void concatenateStrings(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;

    // Copy the first string to result
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    // Append the second string to result
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }

    // Null-terminate the result string
    result[i] = '\0';
}

int main() {
    char str1[100], str2[100], result[200];

    // Input the two strings
    printf("Enter the first string");
    fgets(str1, sizeof(str1), stdin); // Use fgets to allow spaces in the string
    str1[strcspn(str1, "\n")] = '\0'; // Remove the newline character added by fgets

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove the newline character

    // Call the function to concatenate the strings
    concatenateStrings(str1, str2, result);

    // Output the combined string
    printf("Combined String: %s\n", result);

    return 0;
}

