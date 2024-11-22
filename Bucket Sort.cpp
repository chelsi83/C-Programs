#include <stdio.h>
#include <stdlib.h>

// Function to perform Insertion Sort on a bucket
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    // 1. Find the minimum and maximum values in the array
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    // 2. Create buckets
    int bucketCount = 10; // Assuming 10 buckets for simplicity
    int range = (maxVal - minVal) / bucketCount + 1;  // Range per bucket
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int)); // Maximum size of the bucket
        bucketSizes[i] = 0; // Initialize the size of each bucket
    }

    // 3. Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - minVal) / range;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // 4. Sort each bucket and concatenate the results
    int k = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);  // Sort each bucket using Insertion Sort
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[k++] = buckets[i][j];  // Concatenate the sorted buckets
            }
        }
    }

    // Clean up memory
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
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
    int arr[] = {42, 32, 33, 52, 37, 47, 51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    // Perform Bucket Sort
    bucketSort(arr, n);

    printf("Sorted array using Bucket Sort:\n");
    printArray(arr, n);

    return 0;
}

