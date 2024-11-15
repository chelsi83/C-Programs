#include <stdio.h>

// Function to calculate the GCD (Greatest Common Divisor) using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate the LCM using the GCD
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);  // LCM formula: (a * b) / GCD(a, b)
}

int main() {
    int num1, num2;

    printf("Enter two numbers to find their LCM");
    scanf("%d %d", &num1, &num2);

    if (num1 == 0 || num2 == 0) {
        printf("LCM of 0 with any number is undefined.\n");
    } else {
        printf("The LCM of %d and %d is: %d\n", num1, num2, lcm(num1, num2));
    }

    return 0;
}

