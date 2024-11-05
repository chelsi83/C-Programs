#include <stdio.h>

int main() {
    char str[1000];
    int vowels = 0, consonants = 0;
    int i = 0;

    //take input from the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Loop through each character in the string
    while (str[i] != '\0' && str[i] != '\n') {
        // Check if the character is a letter
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            // Check if it is a vowel (both uppercase and lowercase)
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                vowels++;  // Increment vowel count
            } else {
                consonants++;  // Increment consonant count
            }
        }
        i++;
    }

    // Output the results
    printf("Total number of vowels: %d\n", vowels);
    printf("Total number of consonants: %d\n", consonants);

    return 0;
}

