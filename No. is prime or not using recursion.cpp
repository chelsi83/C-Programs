#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime recursively
bool isPrime(int n, int divisor) {
    // Base case: if divisor reaches 1, the number is prime
    if (divisor == 1) {
        return true;
    }

    // If the number is divisible by the current divisor, it's not prime
    if (n % divisor == 0) {
        return false;
    }

    // Recursive call with the next smaller divisor
    return isPrime(n, divisor - 1);
}

int main() {
    int num;

    printf("Enter a number to check if it is prime");
    scanf("%d", &num);

    if (num <= 1) {
        printf("%d is not a prime number.\n", num);
    } else {
        // Start checking from n - 1 as the highest divisor
        if (isPrime(num, num - 1)) {
            printf("%d is a prime number.\n", num);
        } else {
            printf("%d is not a prime number.\n", num);
        }
    }

    return 0;
}

