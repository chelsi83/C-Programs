#include <stdio.h>
#include <math.h>

// Function for jump search
int jumpSearch(int array[], int size, int target) {
    int step = sqrt(size); // Calculate block size to jump
    int prev = 0;

    // Find the block where the target might be present
    while (array[fmin(step, size) - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1; // Target not found
        }
    }

    // Perform linear search within the identified block
    while (array[prev] < target) {
        prev++;
        if (prev == fmin(step, size)) {
            return -1; // Target not found
        }
    }

    // Check if the target is found
    if (array[prev] == target) {
        return prev;
    }

    return -1; // Target not found
}

int main() {
    int array[] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
    int size = sizeof(array) / sizeof(array[0]);
    int target;

    printf("Enter the target value");
    scanf("%d", &target);

    int result = jumpSearch(array, size, target);

    if (result != -1) {
        printf("Target found at index: %d\n", result);
    } else {
        printf("Target not found in the array.\n");
    }

    return 0;
}

