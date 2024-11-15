#include <stdio.h>

// Function to print even numbers in a range recursively
void printEven(int start, int end) {
    if (start > end) {
        return; // Base case: stop recursion when start exceeds end
    }

    if (start % 2 == 0) {
        printf("%d ", start); // Print the even number
    }

    printEven(start + 1, end); // Recursive call with the next number
}

// Function to print odd numbers in a range recursively
void printOdd(int start, int end) {
    if (start > end) {
        return; // Base case: stop recursion when start exceeds end
    }

    if (start % 2 != 0) {
        printf("%d ", start); // Print the odd number
    }

    printOdd(start + 1, end); // Recursive call with the next number
}

int main() {
    int start, end;
    char choice;

    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid range. Start should be less than or equal to end.\n");
        return 1;
    }

    printf("Do you want to print (e)ven or (o)dd numbers? ");
    scanf(" %c", &choice);

    if (choice == 'e' || choice == 'E') {
        printf("Even numbers in the range %d to %d are:\n", start, end);
        printEven(start, end);
    } else if (choice == 'o' || choice == 'O') {
        printf("Odd numbers in the range %d to %d are:\n", start, end);
        printOdd(start, end);
    } else {
        printf("Invalid choice. Please select 'e' for even or 'o' for odd.\n");
    }

    printf("\n");
    return 0;
}

