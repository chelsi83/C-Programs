#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char *word;

    // Input a string from the user
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    // Use strtok to split the string by spaces
    word = strtok(str, " ");
    while (word != NULL) {
        printf("%s\n", word); // Print each word on a new line
        word = strtok(NULL, " ");
    }

    return 0;
}

