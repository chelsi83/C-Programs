#include <stdio.h>

// Function to check if a number is even or odd
void checkEvenOrOdd(int num) 
{
    if (num % 2 == 0) 
    {
        printf("%d is even.\n", num);
    } else 
    {
        printf("%d is odd.\n", num);
    }
}

int main() 
{
    int number;

    printf("Enter a number");
    scanf("%d", &number);

    // Function call to check even or odd
    checkEvenOrOdd(number);

    return 0;
}

