#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum and minimum values in an array
int* findMaxMin(int arr[], int size) {
    // Dynamically allocate memory for the result array
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize max and min with the first element
    result[0] = arr[0]; // max
    result[1] = arr[0]; // min

    // Traverse the array to find max and min
    for (int i = 1; i < size; i++) {
        if (arr[i] > result[0]) {
            result[0] = arr[i];
        }
        if (arr[i] < result[1]) {
            result[1] = arr[i];
        }
    }

    return result; // Return the pointer to the result array
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function and get the result
    int* maxMin = findMaxMin(arr, n);

    // Print the maximum and minimum values
    printf("Maximum value: %d\n", maxMin[0]);
    printf("Minimum value: %d\n", maxMin[1]);

    // Free the allocated memory
    free(maxMin);

    return 0;
}

