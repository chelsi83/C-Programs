#include <stdio.h>

// Function to find the largest element in an array
int findLargest(int arr[], int size) 
{
    int max = arr[0]; // Assume the first element is the largest initially

    // Traverse through the array to find the largest element
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > max) {
            max = arr[i]; // Update max if a larger element is found
        }
    }
    return max; // Return the largest element
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements of the array
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function and print the largest element
    int largest = findLargest(arr, n);
    printf("The largest element in the array is: %d\n", largest);

    return 0;
}

