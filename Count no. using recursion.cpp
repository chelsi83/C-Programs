#include <stdio.h>

int countDigits(int n) {
    // Base case: if the number is reduced to 0, return 0
    if (n == 0)
        return 0;
    // Recursive case: remove one digit and add 1 to the count
    return 1 + countDigits(n / 10);
}

int main() {
    int number;
    printf("Enter a number");
    scanf("%d", &number);

    // Handle negative numbers by converting them to positive
    if (number < 0) {
        number = -number;
    }

    // If the number is 0, the count should be 1
    if (number == 0) {
        printf("Number of digits: 1\n");
    } else {
        printf("Number of digits: %d\n", countDigits(number));
    }

    return 0;
}

