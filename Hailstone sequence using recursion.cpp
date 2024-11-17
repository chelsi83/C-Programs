#include <stdio.h>

// Recursive function to print the Hailstone Sequence
void hailstoneSequence(int n) {
    printf("%d ", n);

    // Base case: stop when n becomes 1
    if (n == 1) {
        return;
    }

    // Recursive case
    if (n % 2 == 0) {
        hailstoneSequence(n / 2); // If n is even, next term is n/2
    } else {
        hailstoneSequence(3 * n + 1); // If n is odd, next term is 3n + 1
    }
}

int main() {
    int num;

    printf("Enter a positive integer");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
    } else {
        printf("Hailstone Sequence starting from %d:\n", num);
        hailstoneSequence(num);
    }

    printf("\n");
    return 0;
}

