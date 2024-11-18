#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Recursive function to check if the string is a palindrome
bool isPalindrome(char str[], int start, int end) {
    // Base cases
    if (start >= end) {
        return true; // If we reach the middle or overlap, it's a palindrome
    }
    if (str[start] != str[end]) {
        return false; // Mismatch found, not a palindrome
    }

    // Recursive case: check the next pair of characters
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];

    printf("Enter a string");
    scanf("%s", str);

    int length = strlen(str);

    if (isPalindrome(str, 0, length - 1)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}

