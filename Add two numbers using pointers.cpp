#include <stdio.h>

int main() 
{
    int num1, num2, sum;
    int *ptr1, *ptr2;  // Declare pointers for the two numbers

    // Assign values to num1 and num2
    num1 = 40;
    num2 = 40;

    // Assign the addresses of num1 and num2 to ptr1 and ptr2
    ptr1 = &num1;
    ptr2 = &num2;

    // Use the pointers to calculate the sum
    sum = *ptr1 + *ptr2;

    // Display the numbers and their sum
    printf("Value of num1: %d\n", *ptr1);
    printf("Value of num2: %d\n", *ptr2);
    printf("Sum of num1 and num2 using pointers: %d\n", sum);

    return 0;
}

