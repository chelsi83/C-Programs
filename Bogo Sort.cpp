#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to check if the array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to shuffle the array randomly
void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int randIndex = rand() % n; // Pick a random index
        // Swap arr[i] with arr[randIndex]
        int temp = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }
}

// Function to perform Bogo Sort
void bogoSort(int arr[], int n) {
    while (!isSorted(arr, n)) {
        shuffle(arr, n);
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
    int arr[] = {3, 2, 5, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    // Seed the random number generator
    srand(time(0));

    bogoSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

