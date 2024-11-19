#include <stdio.h>

// Function for linear search
int linearSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i; // Target found
        }
    }
    return -1; // Target not found
}

int main() {
    int array[] = {4, 2, 7, 1, 5, 3, 8, 6};
    int size = sizeof(array) / sizeof(array[0]);
    int target;

    printf("Enter the target value");
    scanf("%d", &target);

    int result = linearSearch(array, size, target);

    if (result != -1) {
        printf("Target found at index: %d\n", result);
    } else {
        printf("Target not found in the array.\n");
    }

    return 0;
}

