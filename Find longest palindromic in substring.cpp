#include <stdio.h>
#include <string.h>

// Function to expand around the center and find the longest palindrome
char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) return "";

    int start = 0, end = 0;

    // Helper function to expand around the center
    int expandAroundCenter(char* s, int left, int right) 
    {
        while (left >= 0 && right < len && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;  // Length of the current palindrome
    }

    for (int i = 0; i < len; i++) {
        // Check for odd-length palindromes (single center character)
        int len1 = expandAroundCenter(s, i, i);
        // Check for even-length palindromes (pair center characters)
        int len2 = expandAroundCenter(s, i, i + 1);

        // Find the maximum length palindrome
        int maxLen = (len1 > len2) ? len1 : len2;
        if (maxLen > (end - start)) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    // Extract the longest palindromic substring
    static char result[1000];  // Use static to return a pointer to the result
    int j = 0;
    for (int i = start; i <= end; i++) {
        result[j++] = s[i];
    }
    result[j] = '\0';

    return result;
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove the newline character if present

    // Find and print the longest palindromic substring
    char* palindrome = longestPalindrome(str);
    printf("Longest palindromic substring: %s\n", palindrome);

    return 0;
}

