#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i;

    // Prompt the user to enter a sentence
    printf("Enter a sentence");
    fgets(str, sizeof(str), stdin);

    // Loop through each character in the string
    for (i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);  // Convert lowercase to uppercase
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);  // Convert uppercase to lowercase
        }
    }

    // Print the modified string
    printf("Modified sentence: %s\n", str);

    return 0;
}

