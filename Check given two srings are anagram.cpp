#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CHAR_COUNT 256  // Number of possible characters (ASCII)

// Function to check if two strings are anagrams
int areAnagrams(char str1[], char str2[]) {
    int count[CHAR_COUNT] = {0};  // Array to store character counts

    // If lengths are different, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    // Increment the count for characters in str1 and decrement for str2
    for (int i = 0; i < strlen(str1); i++) {
        count[(unsigned char)tolower(str1[i])]++;
        count[(unsigned char)tolower(str2[i])]--;
    }

    // If all counts are zero, then they are anagrams
    for (int i = 0; i < CHAR_COUNT; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100], str2[100];

    // Input two strings from the user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;  // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;  // Remove newline character

    // Check if the strings are anagrams
    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}

