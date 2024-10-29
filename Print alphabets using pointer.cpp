#include <stdio.h>

int main() 
{
    char letter;         // Variable to store each letter
    char *ptr = &letter; // Pointer to the variable `letter`

    // Print lowercase alphabets
    printf("Lowercase Alphabets:\n");
    for (letter = 'a'; letter <= 'z'; letter++)
     {
        printf("%c ", *ptr); // Dereference the pointer to print the letter
    }

    printf("\n");

    // Print uppercase alphabets
    printf("Uppercase Alphabets:\n");
    for (letter = 'A'; letter <= 'Z'; letter++) 
    {
        printf("%c ", *ptr); // Dereference the pointer to print the letter
    }

    printf("\n");

    return 0;
}

