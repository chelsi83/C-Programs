#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum number of strings
#define LEN 100  // Maximum length of each string

int main() {
    char str[MAX][LEN];
    int n;

    // Get the number of strings
    printf("Enter the number of strings");
    scanf("%d", &n);
    getchar(); // To consume the newline character left by scanf

    // Get the strings from the user
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        fgets(str[i], sizeof(str[i]), stdin);
        str[i][strcspn(str[i], "\n")] = '\0';  // Remove the newline character
    }

    // Bubble sort algorithm to sort the strings
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Compare strings and swap if out of order
            if (strcmp(str[i], str[j]) > 0) {
                char temp[LEN];
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    // Print sorted strings
    printf("\nStrings in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}

