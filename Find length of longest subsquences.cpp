#include <stdio.h>
#include <string.h>

// Function to find the length of the Longest Common Subsequence
int longestCommonSubsequence(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    
    // Create a 2D array to store the lengths of LCS
    int dp[m + 1][n + 1];
    
    // Fill the dp array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  // LCS of empty string and any string is 0
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;  // Characters match, add 1 to the previous LCS length
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];  // Take the max of previous results
            }
        }
    }
    
    // The bottom-right cell contains the length of the LCS
    return dp[m][n];
}

int main() {
    char str1[100], str2[100];

    // Input the two strings
    printf("Enter first string");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character if present

    printf("Enter second string");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline character if present

    // Calculate the length of the longest common subsequence
    int lcsLength = longestCommonSubsequence(str1, str2);

    // Output the result
    printf("Length of Longest Common Subsequence: %d\n", lcsLength);

    return 0;
}

