#include <stdio.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    // Loop through each element in the array
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Track if any swapping happened

        // Compare adjacent elements and swap if needed
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Indicate a swap occurred
            }
        }

        // If no two elements were swapped, the array is sorted
        if (swapped == 0) {
            break;
        }
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

    bubbleSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}

