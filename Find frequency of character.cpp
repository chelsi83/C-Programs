#include <stdio.h>
#include <string.h>

#define MAX 256  // Maximum number of possible characters (ASCII)

int main() {
    char str[100];
    int freq[MAX] = {0};  // Array to store frequency of each character
    int i;

    // Input the string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character if present

    // Calculate frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;  // Increment the frequency of the character
    }

    // Print the frequency of each character
    printf("Character frequencies:\n");
    for (i = 0; i < MAX; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}

