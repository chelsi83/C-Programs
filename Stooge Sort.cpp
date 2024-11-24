#include <stdio.h>

// Function to perform Stooge Sort
void stoogeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    // If the first element is greater than the last, swap them
    if (arr[start] > arr[end]) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }

    // If the array has more than two elements
    if (end - start + 1 > 2) {
        int third = (end - start + 1) / 3;

        // Recursively sort the first 2/3 of the array
        stoogeSort(arr, start, end - third);

        // Recursively sort the last 2/3 of the array
        stoogeSort(arr, start + third, end);

        // Recursively sort the first 2/3 again
        stoogeSort(arr, start, end - third);
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
    int arr[] = {5, 3, 2, 8, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    stoogeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

