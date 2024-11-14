#include <stdio.h>

int sumOfDigits(int n) {
    // Base case: if the number is 0, the sum is 0
    if (n == 0)
        return 0;
    // Recursive case: get the last digit and add it to the sum of remaining digits
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int number;
    printf("Enter a number");
    scanf("%d", &number);

    // Handle negative numbers by converting them to positive
    if (number < 0) {
        number = -number;
    }

    printf("Sum of digits: %d\n", sumOfDigits(number));

    return 0;
}

