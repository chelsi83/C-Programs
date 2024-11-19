#include <stdio.h>

// Function for binary search
int binarySearch(int array[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is at mid
        if (array[mid] == target) {
            return mid; // Target found
        }

        // If target is greater, ignore the left half
        if (array[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int array[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(array) / sizeof(array[0]);
    int target;

    printf("Enter the target value");
    scanf("%d", &target);

    int result = binarySearch(array, size, target);

    if (result != -1) {
        printf("Target found at index: %d\n", result);
    } else {
        printf("Target not found in the array.\n");
    }

    return 0;
}

