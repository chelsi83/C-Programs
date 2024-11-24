#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Bead Sort
void beadSort(int *arr, int n) {
    if (n == 0) return;

    // Find the maximum value in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a bead structure (2D array) to simulate the beads
    unsigned char *beads = calloc(n * max, sizeof(unsigned char));

    // Set beads in the structure
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i]; j++) {
            beads[i * max + j] = 1;
        }
    }

    // Perform the gravity simulation
    for (int j = 0; j < max; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += beads[i * max + j];
            beads[i * max + j] = 0;
        }
        for (int i = n - sum; i < n; i++) {
            beads[i * max + j] = 1;
        }
    }

    // Write back the sorted values to the array
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < max && beads[i * max + j]; j++);
        arr[i] = j;
    }

    free(beads); // Free allocated memory
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
    int arr[] = {5, 3, 1, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    beadSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

