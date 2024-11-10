#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};  // Array to store frequency of each character (ASCII size)
    int i;

    // Input a string from the user
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);

    // Calculate frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }

    // Print characters and their frequencies
    printf("Character frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0 && i != '\n') {  // Ignore newline character
            printf("'%c' occurs %d times\n", i, freq[i]);
        }
    }

    return 0;
}

