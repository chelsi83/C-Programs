#include <stdio.h>

int stringLength(char *str) 
{
    int length = 0;

    // Traverse the string until the null character is found
    while (*str != '\0')
     {
        length++; // Increment length
        str++;    // Move pointer to the next character
    }
    
    return length;
}

int main() 
{
    char str[100];
    
    // Input string from user
    printf("Enter a string");
    fgets(str, sizeof(str), stdin);

    // Calculate and display the length of the string
    int length = stringLength(str);
    printf("The length of the string is %d\n", length);
    
    return 0;
}

