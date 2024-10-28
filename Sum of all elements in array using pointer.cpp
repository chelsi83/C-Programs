#include <stdio.h>

int sumArray(int *arr, int size) 
{
    int sum = 0; // Initialize sum to 0

    // Loop through the array using pointer arithmetic
    for (int i = 0; i < size; i++)
     {
        sum += *(arr + i); // Add each element to sum
    }

    return sum; // Return the final sum
}

int main()
 {
    int arr[100], n;
    printf("Enter the number of elements");
    scanf("%d", &n);

    // Read array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", arr + i); // Use pointer arithmetic to store elements
    }
    int totalSum = sumArray(arr, n);
    printf("Sum of all elements: %d\n", totalSum);

    return 0;
}

