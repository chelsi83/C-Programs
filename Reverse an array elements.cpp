#include <stdio.h>

int main() {
    // Declare an array of 5 elements
    int a[5], i;

    // Prompt the user to enter array elements
    printf("Enter 5 array elements: ");
    
    // Read input from the user
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    // Print the elements in reverse order
    printf("\nReversed array elements: ");
    for (i = 4; i >= 0; i--) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}

