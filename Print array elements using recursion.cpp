#include <stdio.h>

// Function to print array elements recursively
void printArray(int arr[], int index, int size) {
    if (index == size)  // Base case: if index reaches size, stop recursion
        return;
    
    // Print the current element
    printf("%d ", arr[index]);
    
    // Recursive call to print the next element
    printArray(arr, index + 1, size);
}

int main() {
    int n;
    printf("Enter the number of elements in the array");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are: ");
    printArray(arr, 0, n);  // Call the recursive function starting from index 0
    printf("\n");

    return 0;
}

