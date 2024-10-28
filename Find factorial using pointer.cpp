#include <stdio.h>

void findFactorial(int *num, long *result)
 {
    *result = 1; // Initialize result to 1
    for (int i = 1; i <= *num; i++) 
    {
        *result *= i; // Multiply result by each number from 1 to *num
    }
}

int main()
 {
    int n;            // Variable to store the input number
    long fact;        // Variable to store the factorial result
    int *ptr_n = &n;  // Pointer to the input number
    long *ptr_fact = &fact; // Pointer to the factorial result
    printf("Enter a number: ");
    scanf("%d", ptr_n); 

    // Call the function to calculate factorial
    findFactorial(ptr_n, ptr_fact);

    // Print the result
    printf("Factorial of %d is %ld\n", *ptr_n, *ptr_fact);

    return 0;
}

