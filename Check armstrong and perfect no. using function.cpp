#include <stdio.h>
#include <math.h>

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int sum = 0, temp = num, digits = 0;

    // Calculate the number of digits
    while (temp > 0) {
        temp /= 10;
        digits++;
    }

    temp = num; // Reset temp to the original number

    // Calculate the sum of each digit raised to the power of the number of digits
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    // Check if the sum is equal to the original number
    return sum == num;
}

// Function to check if a number is a Perfect number
int isPerfect(int num) {
    int sum = 0;

    // Find the sum of proper divisors of the number
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of divisors is equal to the number
    return sum == num;
}

int main() {
    int num;

    // Input a number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the number is an Armstrong number
    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    // Check if the number is a Perfect number
    if (isPerfect(num)) {
        printf("%d is a Perfect number.\n", num);
    } else {
        printf("%d is not a Perfect number.\n", num);
    }

    return 0;
}

