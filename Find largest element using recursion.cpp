#include <stdio.h>

// Function to find the largest element in the array recursively
int findLargest(int arr[], int n) {
    // Base case: if the array has only one element
    if (n == 1) {
        return arr[0];
    }

    // Recursive case: find the largest in the rest of the array
    int maxOfRest = findLargest(arr, n - 1);

    // Return the larger between the current last element and maxOfRest
    return (arr[n - 1] > maxOfRest) ? arr[n - 1] : maxOfRest;
}

int main() {
    int n;

    printf("Enter the number of elements in the array");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = findLargest(arr, n);

    printf("The largest element in the array is: %d\n", largest);

    return 0;
}

