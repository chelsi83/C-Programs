#include <stdio.h>

// Function to calculate the sum of numbers from 1 to n recursively
int sum(int n) {
    if (n == 1)  // Base case: if n is 1, return 1
        return 1;
    else
        return n + sum(n - 1);  // Recursive call
}

int main() {
    int n;
    printf("Enter a positive integer");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
    } else {
        int result = sum(n);
        printf("The sum of numbers from 1 to %d is: %d\n", n, result);
    }

    return 0;
}

