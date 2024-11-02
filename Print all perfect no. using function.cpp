#include <stdio.h>

// Function to check if a number is a Perfect number
int isPerfect(int num) {
    int sum = 0;

    // Calculate the sum of proper divisors of the number
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of divisors is equal to the number
    return sum == num;
}

int main() {
    int lower, upper;

    // Input the range from the user
    printf("Enter the lower bound of the range: ");
    scanf("%d", &lower);
    printf("Enter the upper bound of the range: ");
    scanf("%d", &upper);

    printf("Perfect numbers between %d and %d are:\n", lower, upper);

    // Iterate through the range and print perfect numbers
    for (int i = lower; i <= upper; i++) {
        if (isPerfect(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

