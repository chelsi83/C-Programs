#include <stdio.h>

// Function to calculate the square of a number
int square(int num) 
{
    return num * num;
}

int main() 
{
    int number, result;

    printf("Enter a number");
    scanf("%d", &number);

    // Function call to find the square
    result = square(number);

    printf("The square of %d is %d\n", number, result);

    return 0;
}

