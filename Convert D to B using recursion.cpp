#include <stdio.h>

// Function to convert a decimal number to binary recursively
void decimalToBinary(int n) {
    if (n == 0) {
        return;
    }

    // Recursive call to process the higher-order bits
    decimalToBinary(n / 2);

    // Print the current bit (remainder when divided by 2)
    printf("%d", n % 2);
}

int main() {
    int num;

    printf("Enter a decimal number");
    scanf("%d", &num);

    if (num < 0) {
        printf("Binary representation for negative numbers is not supported in this program.\n");
    } else if (num == 0) {
        printf("Binary representation: 0\n");
    } else {
        printf("Binary representation: ");
        decimalToBinary(num);
        printf("\n");
    }

    return 0;
}

