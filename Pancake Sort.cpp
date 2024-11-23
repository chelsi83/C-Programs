#include <stdio.h>

// Function to reverse (flip) the array from 0 to index
void flip(int arr[], int index) {
    int temp;
    for (int i = 0; i <= index / 2; i++) {
        temp = arr[i];
        arr[i] = arr[index - i];
        arr[index - i] = temp;
    }
}

// Function to find the index of the maximum element in the array
int findMax(int arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Pancake Sort function
void pancakeSort(int arr[], int n) {
    // One by one move the boundary of the unsorted subarray
    for (int curr_size = n; curr_size > 1; curr_size--) {
        // Find the index of the largest element in the current unsorted part
        int maxIndex = findMax(arr, curr_size);

        // Move the largest element to the top (flip it to the front)
        if (maxIndex != curr_size - 1) {
            // If it's not already in the correct position, flip it
            flip(arr, maxIndex);
            flip(arr, curr_size - 1);  // Flip it to the correct position
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {3, 6, 5, 10, 7, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    pancakeSort(arr, n);

    printf("Sorted array using Pancake Sort:\n");
    printArray(arr, n);

    return 0;
}

