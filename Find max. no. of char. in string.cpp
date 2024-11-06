#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0}; // Array to store frequency of each character
    int i, maxFreq = 0;

    //take the input from the user to enter a string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);

    // Count frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++; // Increment frequency based on ASCII value
    }

    // Find the maximum frequency
    for (i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i]; // Update max frequency if a higher one is found
        }
    }

    // Print the result
    printf("The maximum frequency of any character is %d\n", maxFreq);

    return 0;
}

