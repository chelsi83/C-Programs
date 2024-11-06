#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j;
    char temp;

    //take input from the user to enter a string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);

    // Bubble sort algorithm to sort the string
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            // Swap if characters are out of order
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    // Print sorted string
    printf("Sorted string: %s\n", str);

    return 0;
}

