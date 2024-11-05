#include <stdio.h>

int main() {
    char str[1000];
    int alphabets = 0, digits = 0, specialChars = 0;
    int i = 0;

    // take the input from the user to enter a string
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);

    // Loop through each character in the string
    while (str[i] != '\0' && str[i] != '\n') {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            alphabets++;  // Increment alphabet count
        } else if (str[i] >= '0' && str[i] <= '9') {
            digits++;  // Increment digit count
        } else {
            specialChars++;  // Increment special character count
        }
        i++;
    }

    // Output the results
    printf("Total alphabets %d\n", alphabets);
    printf("Total digits %d\n", digits);
    printf("Total special characters %d\n", specialChars);

    return 0;
}

