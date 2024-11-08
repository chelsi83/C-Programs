#include <stdio.h>
#include <string.h>

int main() {
    char str[100], substr[100];

    // Input the main string
    printf("Enter the main string");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character if present

    // Input the substring to search for
    printf("Enter the substring to search: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0';  // Remove newline character if present

    // Check if the substring is present in the main string using strstr
    if (strstr(str, substr) != NULL) {
        printf("The substring is present in the main string.\n");
    } else {
        printf("The substring is not present in the main string.\n");
    }

    return 0;
}

