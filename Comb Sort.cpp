#include <stdio.h>

// Function to perform the Comb Sort
void combSort(int arr[], int n) {
    int gap = n; // Initial gap
    int swapped = 1; // To check if any elements were swapped in a pass

    // While gap is greater than 1
    while (gap > 1 || swapped) {
        // Shrink the gap
        gap = (gap * 10) / 13; // Reduce gap by factor of 1.3
        if (gap < 1) {
            gap = 1; // Make sure gap is at least 1
        }

        swapped = 0; // Reset the swap flag

        // Compare elements with the current gap
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                // Swap the elements
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1; // Set swapped flag to true
            }
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
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    // Perform Comb Sort
    combSort(arr, n);

    printf("Sorted array using Comb Sort:\n");
    printArray(arr, n);

    return 0;
}

