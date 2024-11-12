#include <stdio.h>

void printNumbers(int n) {
    if (n > 50) // Base condition: stop when n is greater than 50
        return;

    printf("%d ", n);
    printNumbers(n + 1); // Recursive call with the next number
}

int main() {
    printf("The first 50 natural numbers are:\n");
    printNumbers(1); // Start printing from 1
    return 0;
}

