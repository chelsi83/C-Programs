#include <stdio.h>

// Function for interpolation search
int interpolationSearch(int array[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= array[low] && target <= array[high]) {
        // Calculate the position using the interpolation formula
        int pos = low + ((target - array[low]) * (high - low) / (array[high] - array[low]));

        // Check if the target is at the calculated position
        if (array[pos] == target) {
            return pos; // Target found
        }

        // If the target is larger, adjust the low boundary
        if (array[pos] < target) {
            low = pos + 1;
        }
        // If the target is smaller, adjust the high boundary
        else {
            high = pos - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(array) / sizeof(array[0]);
    int target;

    printf("Enter the target value");
    scanf("%d", &target);

    int result = interpolationSearch(array, size, target);

    if (result != -1) {
        printf("Target found at index: %d\n", result);
    } else {
        printf("Target not found in the array.\n");
    }

    return 0;
}

