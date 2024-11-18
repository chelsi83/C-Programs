#include <stdio.h>

// Recursive function to calculate power
double power(double base, int exp) {
    // Base case
    if (exp == 0) {
        return 1; // Any number raised to the power of 0 is 1
    }

    // If exponent is positive
    if (exp > 0) {
        return base * power(base, exp - 1); // Multiply base and reduce exp
    }

    // If exponent is negative
    return 1 / power(base, -exp); // Convert to positive exponent
}

int main() {
    double base;
    int exp;

    printf("Enter the base number");
    scanf("%lf", &base);
    printf("Enter the exponent");
    scanf("%d", &exp);

    double result = power(base, exp);
    printf("%.2lf raised to the power %d is %.2lf\n", base, exp, result);

    return 0;
}

