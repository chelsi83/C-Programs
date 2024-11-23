#include <stdio.h>
#include <stdlib.h>

// Function to perform Pigeonhole Sort
void pigeonholeSort(int arr[], int n) {
    // Find the minimum and maximum values in the array
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate the range of elements
    int range = max - min + 1;

    // Create an array of pigeonholes
    int *holes = (int *)calloc(range, sizeof(int));

    // Map each element to its corresponding pigeonhole
    for (int i = 0; i < n; i++) {
        holes[arr[i] - min]++;
    }

    // Collect the elements from the pigeonholes
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (holes[i] > 0) {
            arr[index++] = i + min;
            holes[i]--;
        }
    }

    // Free the pigeonhole array
    free(holes);
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
    int arr[] = {8, 3, 2, 7, 5, 6, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    pigeonholeSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

