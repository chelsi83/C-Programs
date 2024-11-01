#include <stdio.h>

// Function to calculate factorial of a number
int factorial(int n) 
{
    int fact = 1;
    for (int i = 1; i <= n; i++) 
    {
        fact *= i; // Multiply fact by i in each iteration
    }
    return fact; // Return the factorial of n
}

// Main function
int main() {
    int terms = 5; // Number of terms in the series
    float sum = 0.0; // Initialize sum to 0
    
    // Loop to calculate each term and add to sum
    for (int i = 1; i <= terms; i++) 
    {
        sum += (float)factorial(i) / i; // Calculate i!/i and add to sum
    }
    
    // Print the result
    printf("The sum of the series is: %.2f\n", sum);
    
    return 0;
}

