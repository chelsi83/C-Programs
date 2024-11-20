#include <stdio.h>
#include <string.h>

// Function to perform counting sort
void countingSort(int arr[], int n, int max) {
    int count[max + 1]; // Array to store the count of each element
    int output[n];      // Output array for sorted elements

    // Initialize count array with 0
    memset(count, 0, sizeof(count));

    // Count occurrences of each element in the input array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update count array to store cumulative counts
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Original array:\n");
    printArray(arr, n);

    countingSort(arr, n, max);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}

