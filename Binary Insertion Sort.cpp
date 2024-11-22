#include <stdio.h>

// Function to perform Binary Search for finding the insertion position
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid + 1; // Insert after the found element
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

// Function to perform Binary Insertion Sort
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int low = 0, high = i - 1;

        // Find the correct position using binary search
        int pos = binarySearch(arr, low, high, key);

        // Shift all elements to the right to make room for the key
        for (int j = i - 1; j >= pos; j--) {
            arr[j + 1] = arr[j];
        }
        // Insert the key at the found position
        arr[pos] = key;
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
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    // Perform Binary Insertion Sort
    binaryInsertionSort(arr, n);

    printf("Sorted array using Binary Insertion Sort:\n");
    printArray(arr, n);

    return 0;
}

