#include <stdio.h>

// Function to calculate factorial recursively
unsigned long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}

int main() {
    int num;
    
    printf("Enter a number to find its factorial");
    scanf("%d", &num);

    // Validate input (factorial is defined for non-negative integers)
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %llu\n", num, factorial(num));
    }

    return 0;
}

