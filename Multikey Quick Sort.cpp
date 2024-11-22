#include <stdio.h>
#include <stdlib.h>

// Structure to represent a point (tuple)
typedef struct {
    int x;
    int y;
} Point;

// Function to swap two elements
void swap(Point* a, Point* b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare two points (multi-key comparison)
int comparePoints(Point a, Point b) {
    // First compare by x coordinate
    if (a.x != b.x) {
        return a.x - b.x; // Return the difference to order the elements
    }
    // If x's are equal, compare by y coordinate
    return a.y - b.y;
}

// Partition function for multi-key quicksort
int partition(Point arr[], int low, int high) {
    Point pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (comparePoints(arr[j], pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]); // Place pivot in correct position
    return i + 1;
}

// Multi-key QuickSort function
void multiKeyQuickSort(Point arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the left and right parts
        multiKeyQuickSort(arr, low, pi - 1);
        multiKeyQuickSort(arr, pi + 1, high);
    }
}

// Function to print the array of points
void printPoints(Point arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", arr[i].x, arr[i].y);
    }
    printf("\n");
}

// Main function
int main() {
    // Array of points to be sorted
    Point arr[] = {{2, 3}, {1, 2}, {4, 1}, {3, 2}, {1, 3}, {2, 1}, {4, 3}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array of points:\n");
    printPoints(arr, n);

    // Perform Multi-key QuickSort
    multiKeyQuickSort(arr, 0, n - 1);

    printf("Sorted array of points:\n");
    printPoints(arr, n);

    return 0;
}

