#include <stdio.h>

// Function to perform Gnome Sort
void gnomeSort(int arr[], int n) {
    int index = 0;

    while (index < n) {
        // If at the start of the list or the current element is in order, move forward
        if (index == 0 || arr[index] >= arr[index - 1]) {
            index++;
        } else {
            // If the current element is out of order, swap it with the previous element
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--; // Move one step back
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
    int arr[] = {34, 2, 78, 12, 56, 1, 89, 22};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    gnomeSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}

