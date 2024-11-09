#include <stdio.h>
#include <string.h>

int longestUniqueSubstring(char *str) {
    int n = strlen(str);
    int maxLength = 0;      // Length of the longest unique substring
    int start = 0;          // Start of the current substring
    int lastIndex[256];     // Array to store last index of each character (ASCII size)

    // Initialize all characters as not visited
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    for (int end = 0; end < n; end++) {
        // If the character is already in the current substring, update the start
        if (lastIndex[(int)str[end]] >= start) {
            start = lastIndex[(int)str[end]] + 1;
        }

        // Update the last index of the current character
        lastIndex[(int)str[end]] = end;

        // Update maximum length if needed
        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

int main() {
    char str[100];

    // Input a string from the user
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;  // Remove newline character from input

    // Find and display the length of the longest unique substring
    int length = longestUniqueSubstring(str);
    printf("Length of the longest substring without repeating characters: %d\n", length);

    return 0;
}

