#include <stdio.h>
#include <stdlib.h>

// Function to perform Insertion Sort on a partition
void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[low..i-1] that are greater than key
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Partition Sort
void partitionSort(int arr[], int n, int partitionSize) {
    // Process the array in partitions
    for (int i = 0; i < n; i += partitionSize) {
        int end = (i + partitionSize - 1 < n) ? (i + partitionSize - 1) : (n - 1);
        insertionSort(arr, i, end); // Sort the partition using Insertion Sort
    }

    // After sorting all partitions, we need to merge them.
    // In this simple case, merging can be done by sorting the entire array (insertion sort is used again).
    insertionSort(arr, 0, n - 1); // Merge all partitions by sorting the entire array again
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
    int arr[] = {9, 4, 6, 2, 8, 7, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    int partitionSize = 3; // Define partition size
    partitionSort(arr, n, partitionSize);

    printf("Sorted array using Partition Sort:\n");
    printArray(arr, n);

    return 0;
}

