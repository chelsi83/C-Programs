#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;

    // Traverse through 1 to n-1
    for (i = 1; i < n; i++) {
        key = arr[i]; // Element to be positioned
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // one position ahead to make space for the key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Place the key at its correct position
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}

