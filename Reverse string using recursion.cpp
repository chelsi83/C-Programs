#include <stdio.h>
#include <string.h>

// Function to reverse a string recursively
void reverseString(char str[], int start, int end) {
    // Base case: if start >= end, the string is fully reversed
    if (start >= end) {
        return;
    }

    // Swap the characters at positions 'start' and 'end'
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call with the next positions
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];

    printf("Enter a string");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character if present
    str[strcspn(str, "\n")] = '\0';

    int length = strlen(str);

    // Reverse the string
    reverseString(str, 0, length - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}

