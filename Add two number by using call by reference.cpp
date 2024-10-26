#include <stdio.h>

// Function to add two numbers using call by reference
void addNumbers(int *a, int *b, int *result) 
{
    *result = *a + *b;
}

int main() 
{
    int num1, num2, sum;

    printf("Enter the first number");
    scanf("%d", &num1);

    printf("Enter the second number");
    scanf("%d", &num2);

    // Call the function and pass addresses of num1, num2, and sum
    addNumbers(&num1, &num2, &sum);

    printf("The sum of %d and %d is %d.\n", num1, num2, sum);

    return 0;
}

