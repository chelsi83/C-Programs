#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i;

    // Input a string from the user
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);

    // Convert vowels to uppercase
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            str[i] = toupper(str[i]);  // Convert to uppercase
        }
    }

    // Output the modified string
    printf("String with vowels in uppercase: %s", str);

    return 0;
}

